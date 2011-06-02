#include "widget.hpp"

Widget::Widget(int px, int py, int sx, int sy, bool focus)
: posX(px), posY(py), sizeX(sx), sizeY(sy), isFocused(focus)
{ }

void Widget::HandleEvent(genv::event ev)
{
    // no event handling here
}
bool Widget::MouseOver(int x, int y) const
{
    return (posX <= x && x <= posX + sizeX && posY <= y && y <= posY + sizeY);
}
void Widget::SetPosition(int x, int y)
{
    posX = x; posY = y;
}
void Widget::SetFocus(bool focus)
{
    isFocused = focus;
}
