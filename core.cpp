/** The core of the calculator, it converts an infix mathematical expression to RPN, than evaulates the result. **/

#include <cmath>
#include "core.hpp"
using namespace std;

bool Core::isOperator(char c)
{
    switch(c)
    {
    case '+' :
    case '-' :
    case '*' :
    case '/' :
    case '%' :
    case '^' :
        return true;
    default:
        return false;
    }
}

int Core::Preced(char op)
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
    }
    return 0;
}

bool Core::Assoc(char op)
{
    switch(op)
    {
    case '^' :
        return true;
    default:
        return false;
    }
}

void Core::Tokenize(string input)
{
    string temp;

    for(unsigned int i=0; i<input.size(); i++)
    {
        if(input[i] == '-' && (input[i-1] == '(' || i==0)) //interpreting negation operator as (0-1)*number
            input = input.substr(0,i)+"(0-1)*"+input.substr(i+1,input.length()-i);
        if(((!isdigit(input[i-1]) && input[i-1]!=')') && input[i] == ')') || (input[i]=='(' && i != 0 && !isOperator(input[i-1]) && input[i-1] !='('))
        {
            bad = true;  //somehow the algorith cant handle this error, fix it here for now
            break;
        }
        if(isOperator(input[i]) || input[i] == '(' || input[i] == ')')
        {
            if(!temp.empty())
                d.push_back(temp);

            temp=input[i];
            d.push_back(temp);
            temp.clear();

        }
        else if(isdigit(input[i]) || input[i] == '.')
        {
            temp+=input[i];
            int k=0;
            k=temp.find('.');
            if(temp.substr(k+1,temp.length()-k-1).find('.')!=string::npos) //handling bad points in numbers
            {
                bad=true;
                break;
            }
        }
        else //if the char is illegal
        {
            bad = true;
            break;
        }
    }

    if(!temp.empty() && isdigit(input[input.size()-1]) && !bad) //adding the last char
        d.push_back(temp);
}

double Core::Evaulate(vector <double> v, string s)
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
        if(v[0] == 0) //division by zero
        {
            bad = true;
            return 1;
        }
        else
            return v[1]/v[0];
    case '%':
        if(v[0] == 0 || floor(v[0]) != ceil(v[0]) || floor(v[1]) != ceil(v[1])) //division by zero, or not integers
        {
            bad = true;
            return 2;
        }
        else
            return int(v[1]) % int(v[0]);
    case '^':
        if(v[1] == 0 && v[0] <= 0) //division by zero
        {
            bad = true;
            return 1;
        }
        else if(floor(v[0]) != ceil(v[0]) && int(1/v[0]) % 2 == 0 && v[1]<0) //would be a compley result
        {
            bad = true;
            return 3;
        }
        else
            return pow(v[1],v[0]);
    }

    return 0;
}

Core::Core(string input)
{
    stack <string> opStack; //stack for operators
    bad = false;
    bool lpar = false;
    Tokenize(input); //tokenizing the input

    while(!d.empty() && !bad) //converting to RPN
    {
        if(isOperator(d.front()[0])) // If the token is an operator, op1, then:
        {
            while(!opStack.empty())
            {
                // While there is an operator token, o2, at the top of the stack
                // op1 is left-associative and its precedence is less than or equal to that of op2,
                // or op1 is right-associative and its precedence is less than that of op2,
                if(isOperator(opStack.top()[0]) &&
                        ((!Assoc(d.front()[0]) && Preced(d.front()[0])<=Preced(opStack.top()[0])) ||
                         (Assoc(d.front()[0]) && Preced(d.front()[0])<Preced(opStack.top()[0]))))
                {
                    // Pop o2 off the stack, onto the output queue;
                    rpn.push_back(opStack.top());
                    opStack.pop();
                }
                else
                    break;
            }
            // push op1 onto the stack.
            opStack.push(d.front());
        }
        // If the token is a left parenthesis, then push it onto the stack.
        else if(d.front() == "(")
            opStack.push(d.front());
        // If the token is a right parenthesis:
        else if(d.front() == ")")
        {
            lpar = false;
            // Until the token at the top of the stack is a left parenthesis,
            // pop operators off the stack onto the output queue
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

            if(!lpar) // If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
                bad = true;

            if(!opStack.empty()) // Pop the left parenthesis from the stack, but not onto the output queue.
                opStack.pop();
        }

        else // If the token is a number, then add it to the output queue
            rpn.push_back(d.front());

        d.pop_front(); //pop the read token
    }
    // When there are no more tokens to read:
    // While there are still operator tokens in the stack:
    while (!opStack.empty() && !bad)
    {

        if(opStack.top() == "(" || opStack.top() == ")")
        {
            bad = true;
            break;
        }

        rpn.push_back(opStack.top());
        opStack.pop();
    }
}

string Core::GetResult() //evaluating the result
{
    stack <double> valStack; //stack for evaulated values
    stringstream *s; //temp for converting

    while(!rpn.empty() && !bad) // While there are input tokens left
    {
        if(isOperator(rpn.front()[0])) //if it's an operator
        {
            if(valStack.size()<2) //if there are enought argouments
            {
                bad = true;
                break;
            }
            else
            {
                //evaulating the last two vaules; the swap them to the result
                vector <double> *tempv = new vector <double>;
                for(unsigned int i=0; i<2; i++)
                {
                    tempv->push_back(valStack.top());
                    valStack.pop();
                }

                valStack.push(Evaulate(*tempv, rpn.front()));
                delete tempv;
            }

        }
        else //otherwise it's a number: push it onto the value stack
        {
            double t; //temp for converting
            s = new stringstream;
            *s<<rpn.front();
            *s>>t;
            valStack.push(t);
            delete s;
        }

        rpn.pop_front(); // the token is read, read the next
    }

    if(valStack.size() > 1 || valStack.empty()) // if not one value remained
        return "hibas kifejezes"; //error
    else if(bad && valStack.top() == 1)
        return "osztas nullaval"; //division by zero
    else if(bad && valStack.top() == 2)
        return "MOD es nem egesz szam"; //modulus with non-integer
    else if(bad && valStack.top() == 3)
        return "paros gyok, alap < 0"; //complex result of sqrt
    else if(bad) // if not one value remained
        return "hibas kifejezes"; //error


    else // if it's okay, return the result
    {
        s = new stringstream;
        *s<<valStack.top();
        string temp = s->str();
        delete s;
        return temp;
    }
}
