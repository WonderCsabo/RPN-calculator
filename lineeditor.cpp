/**The screen of the calculator, also the event handler for the keyboard.**/
#include "lineeditor.hpp"
using namespace genv;
using namespace std;

LineEditor::LineEditor(int px, int py, int sx, int sy, bool focus)
    : Widget(px, py, sx, sy, focus)
{
    lineText = "";
}

void LineEditor::Show()
{
    Image::DrawImage(posX,posY,1); //drawing the screen's background

    gout << move_to(posX + sizeX - gout.twidth(lineText+"_") -10, posY + 27) << color(0,0,0);
    if(isFocused && isUnderscore) //drawing the text of the screen
        gout<<text(lineText+"_");
    else
        gout<<text(lineText);
}

void LineEditor::HandleEvent(event ev, string &s)
{
    if(s[s.length()-1] == '!') // if we got a result already
        lineText = s.substr(0, s.length()-1);
    else
        lineText = s;

    if ((((ev.keycode >= 40 && ev.keycode <= 43) || (ev.keycode >= 45 && ev.keycode <= 57) || ev.keycode == 94) && lineText.length()<21) || ev.keycode == key_backspace)
    {   //if the char is legal or backspace
        if(s[s.length()-1] == '!') // if we got a result already
        {
            lineText.clear();
            s.clear();
        }
        if(ev.keycode != key_backspace) //adding characters
            lineText += ev.keycode;
        else // deleting with backspace
            lineText = lineText.substr(0, lineText.length()-1);

        s=lineText;
    }

    if(ev.type == ev_timer && !isUnderscore && s[s.length()-1] != '!') //flashing underscore
        isUnderscore = true;
    else if(ev.type == ev_timer)
        isUnderscore = false;
}

void LineEditor::SetText(std::string text)
{
    lineText = text;
}
