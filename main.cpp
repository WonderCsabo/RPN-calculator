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
    case '%' :
    case '^' :
    case ',' :
    case '!' :
        return true;
    default:
        return false;
    }
}

bool isfunction(char c) //using only one char length function names for now
{
    return false;
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
    case '%' :
        return 3;

    case '^' :
        return 4;

    case '!' :
        return 5;

    case '(' :
    case ')' :
        return 1;
    }
    return 0;
}

bool assoc(char op)
{
    switch(op)
    {
    case '^' :
    case '!' :
        return true;
    default:
        return false;
    }
}

int op_argc(char op)
{
    switch(op)
    {
    case '*':
    case '/':
    case '%':
    case '+':
    case '-':
    case '^':
        return 2;
    case '!':
        return 1;
    }
    return 0;
}

deque <string> tokenize(string s)
{
    deque <string> d;
    string temp;

    for(unsigned int i=0; i<s.size(); i++)
    {
        if(!isdigit(s[i]) && s[i] != '.')
        {
            if(!temp.empty())
                d.push_back(temp);

            temp=s[i];
            d.push_back(temp);
            temp.clear();
        }
        else
            temp.append(1, s[i]);
    }
    if(isdigit(s[s.size()-1]) && temp!="")
        d.push_back(temp);

    return d;
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
    case '%':
        return int(v[1]) % int(v[0]);
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
    stack <char> opStack;
    string input;
    string temp;
    getline(cin,input);
    deque <string> d = tokenize(input);

    //converting to RPN

    while(!d.empty())
    {
        if(isoperator(d.front()[0]))
        {
            while(!opStack.empty())
            {
                if(isoperator(opStack.top()) &&
                        ((!assoc(d.front()[0]) && preced(d.front()[0])<=preced(opStack.top())) ||
                         (assoc(d.front()[0]) && preced(d.front()[0])<preced(opStack.top()))))
                {
                    temp = opStack.top();
                    rpn.push_back(temp);
                    opStack.pop();
                }
                else
                    break;
            }

            opStack.push(d.front()[0]);
        }

        else if(d.front() == "(")
            opStack.push(d.front()[0]);

        else if(d.front() == ")")
        {
            lpar = false;
            while(!opStack.empty())
            {
                if(opStack.top() == '(')
                {
                    lpar = true;
                    break;
                }
                temp = opStack.top();
                rpn.push_back(temp);
                opStack.pop();
            }

            if(!lpar)
                bad = true;

            if(!opStack.empty())
                opStack.pop();

            if(!opStack.empty())
            {
                if(isfunction(opStack.top()))
                {
                    temp = opStack.top();
                    rpn.push_back(temp);
                    opStack.pop();
                }
            }
        }

        else if(d.front() == ",")
        {
            lpar = false;
            while(!opStack.empty())
            {
                if(opStack.top() == '(')
                {
                    lpar = true;
                    break;
                }

                temp = opStack.top();
                rpn.push_back(temp);
                opStack.pop();
            }

            if(!lpar)
                bad = true;
        }

        else
        {
            temp = d.front();
            rpn.push_back(temp);
        }

        if(bad)
            break;

        d.pop_front();
    }

    while (!opStack.empty() && !bad)
    {

        if(opStack.top() == '(' || opStack.top() == ')')
        {
            bad=true;
            break;
        }

        temp = opStack.top();
        rpn.push_back(temp);
        opStack.pop();
    }

    //evaluating the result

    stack <double> valStack;
    vector <double> *tempv;
    stringstream *s;
    int t;
    while(!rpn.empty())
    {
        if(isoperator(rpn.front()[0]) || isfunction(rpn.front()[0]))
        {
            if(valStack.size()<op_argc(rpn.front()[0]))
            {
                bad = true;
                break;
            }
            else
            {
                int n = valStack.size();
                tempv = new vector <double>;
                while(n-valStack.size()<op_argc(rpn.front()[0]))
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
            delete s;
            valStack.push(t);
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
