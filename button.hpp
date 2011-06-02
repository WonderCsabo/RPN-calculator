#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widget.hpp"
#include <string>

class Button : public Widget { // controller of the button
public:
    Button(int px, int py, int sx, int sy, std::string text, bool focus = false);
    void Show() const;
    void HandleEvent(genv::event ev); // event handling
    void SetText(std::string text);

    std::string Text() const { return buttonText; }
protected:
    virtual void Action() {} // event handling, maybe hidden

    std::string buttonText;
};


#endif // BUTTON_HPP
