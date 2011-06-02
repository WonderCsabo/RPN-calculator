#ifndef LABELMODBUTTON_HPP
#define LABELMODBUTTON_HPP

#include "button.hpp"
#include "label.hpp"

class LabelModButton : public Button // label modifier button
{
public:
    LabelModButton(int px, int py, int sx, int sy, std::string text, bool focus = false)
     : Button(px, py, sx, sy, text, focus) // gets the label wich should be modified
    {
        targetLabel = NULL;
    }
    void SetLabel(Label* label) { targetLabel = label; } // get the label
    Label* GetLabel() { return targetLabel; } // setting the label
protected:
    void Action() // modifyng action
    {
        if (targetLabel) // if the pointer of the label is not null
            targetLabel->SetText("HEHE"); // modify
    }

    Label *targetLabel;
};

#endif // LABELMODBUTTON_HPP
