#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widget.hpp"
#include <string>

class Button : public Widget { // controller of the button
public:
    Button(int px, int py, int sx, int sy, std::string text, bool focus = false);
    virtual ~Button(){}
    void Show() const;
    virtual void HandleEvent(genv::event ev, std::string &s); // event handling
    void SetText(std::string text);

    std::string Text() const { return buttonText; }
protected:
    virtual void Action(std::string &s); // event handling, maybe hidden

    std::string buttonText;
    bool Mouse;
    bool isClicked;
};


#endif // BUTTON_HPP
