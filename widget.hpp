#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <graphics.hpp>

class Widget // grafikus vezérlõ õsosztálya
{
public:
    Widget(int px, int py, int sx, int sy, bool focus = false);
    // konstruktor pozíció, méret és fókusz alapján
    virtual ~Widget(){} // üres destruktor
    virtual void Show() const = 0; // megjelenítés
    virtual void HandleEvent(genv::event ev); // eseménykezelés
    void SetPosition(int x, int y); // pozíció beállítása
    void SetFocus(bool focus); // fókusz beállítása
    // lekérdezõ mûveletek:
    bool MouseOver(int x, int y) const; // rajta van-e az egér
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
