/**The screen of the calculator, also the event handler for the keyboard.**/
#include "lineeditor.hpp"
using namespace genv;
using namespace std;

LineEditor::LineEditor(int px, int py, int sx, int sy, bool focus)
    : Widget(px, py, sx, sy, focus)
{
    lineText = "";
}

void LineEditor::Show(std::vector<std::vector<std::vector<Color> > > &images)
{
    Image::DrawImage(posX,posY,1,images); //drawing the screen's background

    // determining the rendered text part
    string currentText = lineText;
    if (isFocused && isUnderscore) currentText += "_";
    while (currentText.length() * 8 > sizeX - 4)
        currentText = currentText.substr(1, currentText.length() - 1);

    gout << move_to(posX + sizeX - gout.twidth(lineText+"_") -10, posY + 27) << color(0,0,0) << text(currentText);
    //drawing the text of the screen
}

void LineEditor::HandleEvent(event ev, string &s)
{
    if(s[s.length()-1] == '!') // if we got a result already
        lineText = s.substr(0, s.length()-1);
    else
        lineText = s;

     // if the char is legal, add it
    if (((ev.keycode >= 40 && ev.keycode <= 43) || (ev.keycode >= 45 && ev.keycode <= 57) || ev.keycode == 94) && lineText.length()<21 && s[s.length()-1] != '!')
        lineText += ev.keycode;

    else if(((ev.keycode >= 40 && ev.keycode <= 43) || (ev.keycode >= 45 && ev.keycode <= 57) || ev.keycode == 94) && lineText.length()<21 && s[s.length()-1] == '!')
    {
        lineText.clear();
        lineText += ev.keycode;
        s.clear();
    }
    if (ev.keycode == key_backspace && s[s.length()-1] != '!') // deleting with backspace
        lineText = lineText.substr(0, lineText.length()-1);
    else if(ev.keycode == key_backspace)
    {
        s.clear();
        lineText.clear();
    }

    if(s[s.length()-1] != '!')
        s=lineText;

    if(ev.type == ev_timer && !isUnderscore && s[s.length()-1] != '!') //flashing underscore
        isUnderscore = true;
    else if(ev.type == ev_timer)
        isUnderscore = false;
}

void LineEditor::SetText(std::string text)
{
    lineText = text;
}
