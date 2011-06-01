/** The core of the calculator, it converts an infix mathematical expression to RPN. **/

#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <vector>
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
        if(!isdigit(s[i]) || s[i] != '.')
        {
            if(!temp.empty())
                d.push_back(temp);

            temp=s[i];
            d.push_back(temp);
            temp="";
        }
        else
            temp+=s[i];

    }
    if(isdigit(s[s.size()-1]))
        d.push_back(temp);

    return d;
}

int main()
{
    bool bad = false;
    bool lpar = false;

    stack <char> opStack;
    string queuestr;
    string input;
    getline(cin,input);
    deque <string> d = tokenize(input);

    while(!d.empty())
    {
        cout<<d.front()<<endl;
        if(isoperator(d.front()[0]))
        {
            while(!opStack.empty())
            {
                if(isoperator(opStack.top()) &&
                        ((!assoc(d.front()[0]) && preced(d.front()[0])<=preced(opStack.top())) ||
                         (assoc(d.front()[0]) && preced(d.front()[0])<preced(opStack.top()))))
                {
                    queuestr+=opStack.top();
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
                queuestr+= opStack.top();
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
                    queuestr+= opStack.top();
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

                queuestr+=opStack.top();
                opStack.pop();
            }

            if(!lpar)
                bad = true;
        }
        else if(isfunction(d.front()[0]))
            queuestr+= d.front();

        else
            queuestr+= d.front();

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

        queuestr+=opStack.top();
        opStack.pop();
    }


    if(bad)
        cout<<"hibas kifejezes";
    else
        cout<<"rpn "<<queuestr;


    return 0;
}
