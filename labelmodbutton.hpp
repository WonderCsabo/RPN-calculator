#ifndef LABELMODBUTTON_HPP
#define LABELMODBUTTON_HPP

#include "button.hpp"
#include "label.hpp"

class LabelModButton : public Button // c�mkefelirat m�dos�t� gomb
{
public:
    LabelModButton(int px, int py, int sx, int sy, std::string text, bool focus = false)
     : Button(px, py, sx, sy, text, focus) // megkapja a m�dos�tand� c�mk�t is
    {
        targetLabel = NULL;
    }
    void SetLabel(Label* label) { targetLabel = label; } // c�mke lek�rdez�se
    Label* GetLabel() { return targetLabel; } // c�mke be�ll�t�sa
protected:
    void Action() // m�dos�t�s akci�ja
    {
        if (targetLabel) // ha a c�mke mutat�ja nem nulla
            targetLabel->SetText("HEHE"); // m�dos�t�s
    }

    Label *targetLabel;
};

#endif // LABELMODBUTTON_HPP
