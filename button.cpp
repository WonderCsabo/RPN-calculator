#include "button.hpp"
using namespace genv;

Button::Button(int px, int py, int sx, int sy, std::string text, bool focus)
: Widget(px, py, sx, sy, focus)
{
    buttonText = text;
}

void Button::Show() const
{
    gout << move_to(posX, posY) << color(255,255,255) << box(sizeX, sizeY);

    if (isFocused ) gout << color(0,0,100);
    else if(Mouse) gout << color(255,0,0);
    else gout << color(0,0,50);
    gout << move_to(posX + 1, posY + 1) << box(sizeX - 2, sizeY - 2);

    gout << color(255,255,255)
         << move_to(posX + sizeX / 2 - gout.twidth(buttonText) / 2, posY + sizeY / 2 + 6)
         << text(buttonText);
}

void Button::HandleEvent(event ev)
{
    // ha a gomb fókuszálva van és ENTER-t ütünk, vagy felette bal egérgombbal kattintunk
    if ((isFocused && ev.keycode == key_enter) ||
        (MouseOver(ev.pos_x, ev.pos_y) && ev.button == btn_left))
    {
        Action(); // hajtsuk végre az akciót
    }
    if(MouseOver(ev.pos_x, ev.pos_y))
    {
        Mouse = true;
    }
    else if (!MouseOver(ev.pos_x, ev.pos_y) && ev.type == ev_mouse)
        Mouse = false;
}

