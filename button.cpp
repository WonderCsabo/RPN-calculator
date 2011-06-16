#include "button.hpp"
using namespace genv;

Button::Button(int px, int py, int sx, int sy, std::string text, bool focus)
: Widget(px, py, sx, sy, focus)
{
    buttonText = text;
    isClicked = false;
}

void Button::Show() const
{
    gout << move_to(posX, posY) << color(255,255,255) << box(sizeX, sizeY);

    if(isClicked) gout << color(244,91,0);
    else if (isFocused) gout << color(0,0,100);
    else if(Mouse) gout << color(255,0,0);

    else gout << color(0,0,50);
    gout << move_to(posX + 1, posY + 1) << box(sizeX - 2, sizeY - 2);

    gout << color(255,255,255)
         << move_to(posX + sizeX / 2 - gout.twidth(buttonText) / 2, posY + sizeY / 2 + 6)
         << text(buttonText);
}

void Button::HandleEvent(event ev, std::string &s)
{
    // if it is focused and hit ENTER or the cursor is on it and clicked
    if ((isFocused && ev.keycode == key_enter) || (MouseOver(ev.pos_x, ev.pos_y) && ev.button == btn_left))
        Action(s); // execute action

    if(MouseOver(ev.pos_x, ev.pos_y)) // if the cursor is over the button
        Mouse = true;
    else if (ev.type == ev_mouse)
        Mouse = false;
    if(MouseOver(ev.pos_x, ev.pos_y) && ev.button == 1) // if the button is clicked
        isClicked = true;
    else if(ev.button == -1 && isClicked)
        isClicked = false;
}

void Button::Action(std::string &s)
{
    if(s[s.length()-1] == '!')
        s.clear();
    if(buttonText!="C" && buttonText!="CE" && buttonText!="sqrt" && s.length()<21)
        s+=buttonText;
    else if(buttonText == "C" )
        s = s.substr(0, s.length()-1);
    else if(buttonText == "CE")
        s.clear();
    else if(buttonText == "sqrt")
        s+="^(1/2)";
}

