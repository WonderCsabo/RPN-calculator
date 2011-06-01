/** The core of the calculator, it converts an infix mathematical expression to RPN. **/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool isoperand(char output)
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
        return true;
    default:
        return false;
    }
}

int pr(char operand)
{
    switch(operand)
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

    case '(' :
    case ')' :
        return 1;
    }
    return 0;
}

bool lr(char operand)
{
    switch(operand)
    {
    case '^' :
        return true;
    default:
        return false;
    }
}

int main()
{
    bool bad=false;

    stack <char> charStack;
    string queuestr;
    string input;
    getline(cin,input);
    int pr1=0;
    int lr1=0;
    int pr2=0;

    while(!bad)
    {

        for(unsigned int i=0; i<input.length(); ++i)
        {
            switch(input[i])
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':


                if(!charStack.empty())
                {
                    pr1=pr(input[i]);
                    lr1=lr(input[i]);
                    pr2=pr(charStack.top());
                }

                while(!charStack.empty())
                {
                    if((lr1 && pr1<pr2) || (!lr1 && pr1<=pr2))
                    {
                        queuestr+=charStack.top();
                        queuestr+='_';
                        charStack.pop();
                    }
                    else
                        break;
                }
                charStack.push(input[i]);
                break;

            case '(':
                charStack.push(input[i]);
                break;

            case ')':

                if(!charStack.empty())
                {
                    while(charStack.top() != '(')
                    {
                        queuestr+= charStack.top();
                        queuestr+='_';
                        charStack.pop();
                        if(charStack.empty())
                        {
                            bad=true;
                            break;
                        }
                    }

                    if(!charStack.empty())
                        charStack.pop();
                }
                else
                    bad=true;
                break;

            default:
                if(isdigit(input[i]) || input[i]=='.' || input[i]==',')
                {
                    if(input.length()>i+1)
                    {
                        if(!isdigit(input[i+1]))
                        {
                            queuestr+= input[i];
                            queuestr+='_';

                        }
                        else
                            queuestr+= input[i];
                    }
                    else
                        queuestr+= input[i];
                }
                else
                    bad=true;

            }

        }
        break;
    }

    while (!charStack.empty() && bad==false)
    {

        if(charStack.top() == '(' || charStack.top() == ')')
            bad=true;
        else
        {
            queuestr+='_';
            queuestr+=charStack.top();
            charStack.pop();
        }
    }

    if(bad)
        cout<<"hibas kifejezes";
    else
        cout<<queuestr;


    return 0;
}