/**Object for the button which fires calc. Inherits everything expect the calc firing.**/

#include "enterbutton.hpp"
#include "core.hpp"

void EnterButton::Action(std::string &s)
{
    if(!s.empty() && s[s.length()-1] != '!') //if we didnt got a result already
    {
        Core *c = new Core(s); //converting to postfix RPN
        s = c->GetResult()+"!"; //calculating the result
        delete c;
    }
}
