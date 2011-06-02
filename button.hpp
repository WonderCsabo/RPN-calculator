#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widget.hpp"
#include <string>

class Button : public Widget // gomb vez�rl�je
{
public:
    Button(int px, int py, int sx, int sy, std::string text, bool focus = false);
    void Show() const;
    void HandleEvent(genv::event ev); // esem�nykezel�s
    void SetText(std::string text);

    std::string Text() const { return buttonText; }
protected:
    virtual void Action() {} // akci�kezel�s, ez lehet rejtett

    std::string buttonText;
};


#endif // BUTTON_ppH
