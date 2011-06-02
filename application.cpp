#include "application.hpp"

#include <graphics.hpp>
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
    while (gin && !isExiting) // amíg fogadhat eseményeket és nincs kilépési módban
    {
        event ev; gin >> ev;

        if ((ev.keycode == key_tab || ev.keycode == key_right) && widgets.size() > 0) // tab hatására változik a fókusz
            focus++;
        if(widgets.size() > 0 && ev.keycode == key_left)
            focus--;

        if(focus>2)
            focus = 0;
        if(focus<0)
            focus = 2;

        for (unsigned int i = 0; i < widgets.size(); i++)
            widgets[i]->SetFocus(focus == i);

        for (unsigned int i = 0; i < widgets.size(); i++)
        { // vectorban található vezérlõk
            widgets[i]->HandleEvent(ev); // eseménykezelés
        }

        gout << move_to(0, 0) << color(0,0,0) << box(sizeX, sizeY);
        for (unsigned int i = 0; i < widgets.size(); i++)
            widgets[i]->Show(); // megjelenítés
        gout << refresh;
    }
}
void Application::Shutdown()
{
    isExiting = true; // kilépés inicializálása
}
