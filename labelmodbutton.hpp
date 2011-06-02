#ifndef LABELMODBUTTON_HPP
#define LABELMODBUTTON_HPP

#include "button.hpp"
#include "label.hpp"

class LabelModButton : public Button // címkefelirat módosító gomb
{
public:
    LabelModButton(int px, int py, int sx, int sy, std::string text, bool focus = false)
     : Button(px, py, sx, sy, text, focus) // megkapja a módosítandó címkét is
    {
        targetLabel = NULL;
    }
    void SetLabel(Label* label) { targetLabel = label; } // címke lekérdezése
    Label* GetLabel() { return targetLabel; } // címke beállítása
protected:
    void Action() // módosítás akciója
    {
        if (targetLabel) // ha a címke mutatója nem nulla
            targetLabel->SetText("HEHE"); // módosítás
    }

    Label *targetLabel;
};

#endif // LABELMODBUTTON_HPP
