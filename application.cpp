#include "application.hpp"
#include <graphics.hpp>
#include "image.hpp"
#include <iostream>
using namespace genv;

Application::Application(int x, int y): sizeX(x), sizeY(y)
{
    isExiting = false;
    focus = 0;
}
Application::~Application()
{
    for (unsigned int i = 0; i < widgets.size(); i++)
        delete widgets[i];
}
void Application::AddWidget(Widget *w)
{
    widgets.push_back(w);
}
void Application::Run()
{
   gout.open(sizeX, sizeY);
   Image *img = new Image("background.kep");
   img->DrawImage(0, 0);
   delete img;
   gin.timer(700);
    while (gin && !isExiting) // while it can accept events and not in exiting state
    {
        event ev; gin >> ev;
        if ((ev.keycode == key_tab || ev.keycode == key_right) && widgets.size() > 0) // focus is chaned with tab or key_right
            focus++;
        else if(widgets.size() > 0 && ev.keycode == key_left) // focus is changed with key_left
            focus--;

        if(focus<0)
            focus = widgets.size()-1;
        else if(focus>widgets.size()-1)
            focus = 0;

        for (unsigned int i = 0; i < widgets.size(); i++)
            widgets[i]->SetFocus(focus == i);

        for (unsigned int i = 0; i < widgets.size(); i++)  // controllers in the vector
            widgets[i]->HandleEvent(ev, line); //event handling

        //gout << move_to(0, 0) << color(0,0,0) << box(sizeX, sizeY);
        for (unsigned int i = 0; i < widgets.size(); i++)
            widgets[i]->Show(); // displaying
        gout << refresh;

        //std::cout<<line<<std::endl;
    }
}
void Application::Shutdown()
{
    isExiting = true; // initalizing exiting
}
