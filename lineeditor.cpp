#include "lineeditor.hpp"

using namespace genv;
using namespace std;

LineEditor::LineEditor(int px, int py, int sx, int sy, bool focus)
  : Widget(px, py, sx, sy, focus)
{
    lineText = "";
}

void LineEditor::Show() const
{
    gout << move_to(posX, posY) << color(255,255,255)
         << box(sizeX, sizeY) << move_to(posX + 1, posY + 1)
         << color(0,0,50) << box(sizeX - 2, sizeY - 2);

    // determining the rendered text part
    string currentText = lineText;
    if (isFocused && isUnderscore) currentText += "_";
    while (currentText.length() * 8 > sizeX - 4)
       currentText = currentText.substr(1, currentText.length() - 1);

    gout << move_to(posX + sizeX - gout.twidth(lineText+"_") -5, posY + 27) << color(255,255,255) << text(currentText);
}
void LineEditor::HandleEvent(event ev)
{
    if (((ev.keycode >= 40 && ev.keycode <= 43) || (ev.keycode >= 45 && ev.keycode <= 57) || ev.keycode == 94) && lineText.length()<21) // if the char is legal
        lineText += ev.keycode;
    if (ev.keycode == key_backspace) // deleting with backspace
        lineText = lineText.substr(0, lineText.length()-1);

    if(ev.type == ev_timer && !isUnderscore)
        isUnderscore = true;
    else if(ev.type == ev_timer)
        isUnderscore = false;
}

void LineEditor::SetText(std::string text)
{
    lineText = text;
}
