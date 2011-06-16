/** The core of the calculator, it converts an infix mathematical expression to RPN, than evaulates the result. **/

#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <cmath>
using namespace std;

bool isoperator(char output)
{
    switch(output)
    {
    case '+' :
    case '-' :
    case '*' :
    case '/' :
    case '^' :
        return true;
    default:
        return false;
    }
}


int preced(char op)
{
    switch(op)
    {
    case '+' :
    case '-' :
        return 2;

    case '*' :
    case '/' :
        return 3;

    case '^' :
        return 4;
    }
    return 0;
}

bool assoc(char op)
{
    switch(op)
    {
    case '^' :
        return true;
    default:
        return false;
    }
}

void tokenize(string &s, deque <string> &d, bool &bad)
{
    string temp;

    if(s[0] == '-')
        s="0"+s;

    for(unsigned int i=0; i<s.size(); i++)
        if(i>0 && s[i] == '-' && s[i-1] == '(')
            s = s.substr(0,i)+"0-"+s.substr(i+1,s.length()-i-1);

    for(unsigned int i=0; i<s.size(); i++)
    {
        if(i>0 && isoperator(s[i-1]) && s[i] == ')')
            bad = true;
        if(isoperator(s[i]) || s[i] == '(' || s[i] == ')' && s[i] != '.')
        {
            if(!temp.empty())
                d.push_back(temp);

            temp=s[i];
            d.push_back(temp);
            temp.clear();
        }
        else if(isdigit(s[i]) || s[i] == '.')
            temp+=s[i];
        else
        {
            bad = true;
            break;
        }

    }
    if(isdigit(s[s.size()-1]) && !temp.empty())
        d.push_back(temp);
}

double evaulate(vector <double> v, string s)
{
    switch(s[0])
    {
    case '+':
        return v[0]+v[1];
    case '-':
        return v[1]-v[0];
    case '*':
        return v[0]*v[1];
    case '/':
        return v[1]/v[0];
    case '^':
        return pow(v[1],v[0]);
    }

    return 0;
}

int main()
{
    bool bad = false;
    bool lpar = false;
    deque <string> rpn;
    stack <string> opStack;
    string input;
    getline(cin,input);
    deque <string> d;
    tokenize(input,d,bad);

    //converting to RPN

    while(!d.empty() && !bad)
    {
        if(isoperator(d.front()[0]))
        {
            while(!opStack.empty())
            {
                if(isoperator(opStack.top()[0]) &&
                        ((!assoc(d.front()[0]) && preced(d.front()[0])<=preced(opStack.top()[0])) ||
                         (assoc(d.front()[0]) && preced(d.front()[0])<preced(opStack.top()[0]))))
                {
                    rpn.push_back(opStack.top());
                    opStack.pop();
                }
                else
                    break;
            }

            opStack.push(d.front());
        }

        else if(d.front() == "(")
            opStack.push(d.front());

        else if(d.front() == ")")
        {
            lpar = false;
            while(!opStack.empty())
            {
                if(opStack.top() == "(")
                {
                    lpar = true;
                    break;
                }
                rpn.push_back(opStack.top());
                opStack.pop();
            }

            if(!lpar)
                bad = true;

            if(!opStack.empty())
                opStack.pop();
        }

        else
        {
            rpn.push_back(d.front());
        }

        d.pop_front();

    }

    while (!opStack.empty() && !bad)
    {

        if(opStack.top() == "(" || opStack.top() == ")")
        {
            bad = true;
            break;
        }

        rpn.push_back(opStack.top());
        opStack.pop();

//    while(!rpn.empty())
//    {
//        cout<<rpn.front()<<",";
//        rpn.pop_front();
//    }
//    cout<<endl;
    }

    //evaluating the result

    stack <double> valStack;
    vector <double> *tempv;
    stringstream *s;
    double t;
    while(!rpn.empty() && !bad)
    {
        if(isoperator(rpn.front()[0]))
        {
            if(valStack.size()<2)
            {
                bad = true;
                break;
            }
            else
            {
                tempv = new vector <double>;
                for(unsigned int i=0; i<2; i++)
                {
                    tempv->push_back(valStack.top());
                    valStack.pop();
                }

                valStack.push(evaulate(*tempv, rpn.front()));
                delete tempv;
            }

        }
        else
        {
            s = new stringstream;
            *s<<rpn.front();
            *s>>t;
            valStack.push(t);
            delete s;
        }

        rpn.pop_front();
    }

    if(valStack.size() > 1 || valStack.empty())
        bad = true;

    if(bad)
        cout<<"hibas kifejezes";
    else
        cout<<"eredmeny: "<<valStack.top();


    return 0;
}
