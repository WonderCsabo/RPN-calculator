#ifndef ENTERBUTTON_HPP_INCLUDED
#define ENTERBUTTON_HPP_INCLUDED

#include "button.hpp"

class EnterButton : public Button { // controller of the button
public:
    EnterButton(int px, int py, int sx, int sy, std::string text, bool focus = false) : Button(px, py, sx, sy, text, focus){}

protected:
    virtual void Action(std::string &s); // event handling
};


#endif // ENTERBUTTON_HPP_INCLUDED
