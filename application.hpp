#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "widget.hpp"
#include <vector>

class Application // grafikus alkalmaz�s
{
public:
    Application(int sx, int sy); // m�ret alapj�n program l�trehoz�sa
    ~Application();
    void AddWidget(Widget *w); // �j vez�rl� felv�tele
    void Run(); // futtat�s
    void Shutdown(); // le�ll�t�s

    int Width() const { return sizeX; }
    int Height() const { return sizeY; }
protected:
    std::vector<Widget*> widgets; // vez�rl�k
    int focus; // megadja, melyik vez�rl�n van a f�kusz
    bool isExiting; // kil�p�s alatt �ll-e a program
    int sizeX, sizeY; // k�perny� m�ret
};

#endif // APPLICATION_HPP
