#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <graphics.hpp>

class Widget // graphic controller class
{
public:
    Widget(int px, int py, int sx, int sy, bool focus = false);
    // constructor with position, size
    virtual ~Widget(){} // empty deconstructro
    virtual void Show() const = 0; // displaying
    virtual void HandleEvent(genv::event ev); // event handling
    void SetPosition(int x, int y); // setting the position
    void SetFocus(bool focus); // setting the focus
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
    bool Mouse;
};


#endif // WIDGET_HPP
