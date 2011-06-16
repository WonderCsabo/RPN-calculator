#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <graphics.hpp>
#include <iostream>
#include <string>
#include "image.hpp"



class Widget // graphic controller class
{
public:
    Widget(int px, int py, int sx, int sy, bool focus = false);
    // constructor with position, size
    virtual ~Widget(){} // empty deconstructor
    virtual void Show() const = 0; // displaying
    virtual void HandleEvent(genv::event ev, std::string &s); // event handling
    void SetPosition(int x, int y); // setting the position
    void SetFocus(bool focus); // setting the focus
    virtual void Action(std::string &s){}
    // getter methods:
    bool MouseOver(int x, int y) const; // is the mouse on the widget
    int PositionX() const { return posX; }
    int PositionY() const { return posY; }
    int Width() const { return sizeX; }
    int Height() const { return sizeY; }
    bool Focus() const { return isFocused; }
protected:
    int posX, posY, sizeX, sizeY;
    bool isFocused;
};


#endif // WIDGET_HPP
