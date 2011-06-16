#include "lineeditor.hpp"

using namespace genv;
using namespace std;

LineEditor::LineEditor(int px, int py, int sx, int sy, bool focus)
    : Widget(px, py, sx, sy, focus)
{
    lineText = "";
    img = new Image("screen.kep");
}

void LineEditor::Show() const
{
//    gout << move_to(posX, posY) << color(255,255,255)
//         << box(sizeX, sizeY) << move_to(posX + 1, posY + 1)
//         << color(0,0,50) << box(sizeX - 2, sizeY - 2);
    //gout << move_to(posX, posY);
    img->DrawImage(posX, posY);

    // determining the rendered text part
    string currentText = lineText;
    if (isFocused && isUnderscore) currentText += "_";
    while (currentText.length() * 8 > sizeX - 4)
        currentText = currentText.substr(1, currentText.length() - 1);

    gout << move_to(posX + sizeX - gout.twidth(lineText+"_") -10, posY + 27) << color(0,0,0) << text(currentText);
}

void LineEditor::HandleEvent(event ev, string &s)
{
    if(s[s.length()-1] == '!')
        lineText = s.substr(0, s.length()-1);
    else
        lineText = s;

    if (((ev.keycode >= 40 && ev.keycode <= 43) || (ev.keycode >= 45 && ev.keycode <= 57) || ev.keycode == 94) && lineText.length()<21 && s[s.length()-1] != '!') // if the char is legal
        lineText += ev.keycode;

    else if(((ev.keycode >= 40 && ev.keycode <= 43) || (ev.keycode >= 45 && ev.keycode <= 57) || ev.keycode == 94) && lineText.length()<21 && s[s.length()-1] == '!')
    {
        lineText.clear();
        lineText += ev.keycode;
        s.clear();
    }
    if (ev.keycode == key_backspace) // deleting with backspace
        lineText = lineText.substr(0, lineText.length()-1);

    if(s[s.length()-1] != '!')
        s=lineText;

    if(ev.type == ev_timer && !isUnderscore && s[s.length()-1] != '!')
        isUnderscore = true;
    else if(ev.type == ev_timer)
        isUnderscore = false;
}

void LineEditor::SetText(std::string text)
{
    lineText = text;
}
