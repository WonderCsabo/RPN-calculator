#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widget.hpp"
#include <string>

class Button : public Widget // gomb vezérlõje
{
public:
    Button(int px, int py, int sx, int sy, std::string text, bool focus = false);
    void Show() const;
    void HandleEvent(genv::event ev); // eseménykezelés
    void SetText(std::string text);

    std::string Text() const { return buttonText; }
protected:
    virtual void Action() {} // akciókezelés, ez lehet rejtett

    std::string buttonText;
};


#endif // BUTTON_ppH
