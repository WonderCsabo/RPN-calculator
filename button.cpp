/**Class for the buttons, except the calc button; drawing, event handling.**/

#include "button.hpp"
using namespace genv;

Button::Button(int px, int py, int sx, int sy, std::string text, bool focus)
: Widget(px, py, sx, sy, focus), buttonText(text), isClicked(false) {}

int Button::Type()
{
    int t=0;
    switch (buttonText[0])
    {
        case 'C':
        case '(':
        case ')':
        case 's':
        case '/':
        case '*':
        case '-':
        case '+':
        case '%':
        case '^':
            t=2;
            break;
        case '0':
            t=3;
            break;
        case '=':
            t=4;
            break;
        default:
            t=5;
            break;
    }
    if(isClicked)
        return t+8;
    else if(Mouse)
        return t+4;
    else
        return t;
}
void Button::Show()
{
        Image::DrawImage(posX,posY,Button::Type()); //draw the button

        if(isFocused) // draw the nice dotted frame
        {
            for(int i=0;i<sizeX-8;i+=2)
                gout<<move_to(posX+i+4,posY+4)<<color(0,0,0)<<dot<<
                      move_to(posX+i+4,posY+sizeY-4)<<color(0,0,0)<<dot;
            if(sizeX==34)
            gout<<move_to(posX+sizeX-4,posY+4)<<color(0,0,0)<<dot<<
                  move_to(posX+sizeX-4,posY+sizeY-4)<<color(0,0,0)<<dot;

            for(int i=0;i<sizeY-8;i+=2)
                gout<<move_to(posX+4,posY+i+4)<<color(0,0,0)<<dot<<
                      move_to(posX+sizeX-4,posY+i+4)<<color(0,0,0)<<dot;
        }

    gout << color(0,0,0) //drawing the label
         << move_to(posX + sizeX / 2 - gout.twidth(buttonText) / 2, posY + sizeY / 2 + 6)
         << text(buttonText);
}

void Button::HandleEvent(event ev, std::string &s)
{
    // if it is focused and hit SPACE or the cursor is on it and clicked
    if ((isFocused && ev.keycode == key_space) || (MouseOver(ev.pos_x, ev.pos_y) && ev.button == btn_left))
        Action(s); // execute action
    else if(ev.keycode == key_enter && buttonText == "=")
        Action(s);

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
    if(s[s.length()-1] == '!') // we got a result, start the string from scratch
        s.clear();
    if(buttonText!="C" && buttonText!="CE" && buttonText!="sqrt" && s.length()<21) //adding a number/operator
        s+=buttonText;
    else if(buttonText == "C" ) //delete on char
        s = s.substr(0, s.length()-1); //delete the whole string
    else if(buttonText == "CE")
        s.clear();
    else if(buttonText == "sqrt" && s.length()<16)
        s+="^(1/2)";
}
