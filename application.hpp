#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "widget.hpp"
#include <vector>

class Application // grafikus alkalmazás
{
public:
    Application(int sx, int sy); // méret alapján program létrehozása
    ~Application();
    void AddWidget(Widget *w); // új vezérlõ felvétele
    void Run(); // futtatás
    void Shutdown(); // leállítás

    int Width() const { return sizeX; }
    int Height() const { return sizeY; }
protected:
    std::vector<Widget*> widgets; // vezérlõk
    int focus; // megadja, melyik vezérlõn van a fókusz
    bool isExiting; // kilépés alatt áll-e a program
    int sizeX, sizeY; // képernyõ méret
};

#endif // APPLICATION_HPP
