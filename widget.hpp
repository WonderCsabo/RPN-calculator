#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <graphics.hpp>

class Widget // grafikus vez�rl� �soszt�lya
{
public:
    Widget(int px, int py, int sx, int sy, bool focus = false);
    // konstruktor poz�ci�, m�ret �s f�kusz alapj�n
    virtual ~Widget(){} // �res destruktor
    virtual void Show() const = 0; // megjelen�t�s
    virtual void HandleEvent(genv::event ev); // esem�nykezel�s
    void SetPosition(int x, int y); // poz�ci� be�ll�t�sa
    void SetFocus(bool focus); // f�kusz be�ll�t�sa
    // lek�rdez� m�veletek:
    bool MouseOver(int x, int y) const; // rajta van-e az eg�r
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
