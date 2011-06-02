#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "widget.hpp"
#include <vector>

class Application // graphics application
{
public:
    Application(int sx, int sy); // create program with size
    ~Application();
    void AddWidget(Widget *w); // create new controller
    void Run(); 
    void Shutdown(); 

    int Width() const { return sizeX; }
    int Height() const { return sizeY; }
protected:
    std::vector<Widget*> widgets; // controllers
    int focus; // gives the focus' position
    bool isExiting; // is the program exiting
    int sizeX, sizeY; // size of screen
};

#endif // APPLICATION_HPP
