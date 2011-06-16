#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "widget.hpp"
#include "image.hpp"
#include <vector>

class Application // graphics application
{
public:
    Application(int sx, int sy); // create program with size
    ~Application();
    void Run();
    void Shutdown();
    int Width() const { return sizeX; }
    int Height() const { return sizeY; }
protected:
    std::vector<Widget*> widgets; // controllers
    int focus; // gives the focus' position
    bool isExiting; // is the program exiting
    int sizeX, sizeY; // size of window
    std::string line; //string of the screen
    Image *img; // drawing object
};

#endif // APPLICATION_HPP
