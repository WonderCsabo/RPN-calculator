#ifndef CORE_HPP_INCLUDED
#define CORE_HPP_INCLUDED

#include <stack>
#include <deque>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Core
{
private:
    bool isOperator(char c); // is the token an operator
    int Preced(char op); // returns the precedence of the operator
    bool Assoc(char op); // returns the associativity of the operator (left or right)
    void Tokenize(string input); //parse the input string into tokens
    double Evaulate(vector <double> v, string s); // evaulate operation
    bool bad; // is the mathematical expression is bad
    deque <string> rpn; // stores the postfix form
    deque <string> d; //stores the tokenized input

public:
    Core(string input); //constructor, also the infix to postfix converter
    string GetResult(); // evauletes the result of the postfix expression

};



#endif // CORE_HPP_INCLUDED
