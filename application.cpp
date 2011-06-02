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
    while (gin && !isExiting) // am�g fogadhat esem�nyeket �s nincs kil�p�si m�dban
    {
        event ev; gin >> ev;

        if ((ev.keycode == key_tab || ev.keycode == key_right) && widgets.size() > 0) // tab hat�s�ra v�ltozik a f�kusz
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
        { // vectorban tal�lhat� vez�rl�k
            widgets[i]->HandleEvent(ev); // esem�nykezel�s
        }

        gout << move_to(0, 0) << color(0,0,0) << box(sizeX, sizeY);
        for (unsigned int i = 0; i < widgets.size(); i++)
            widgets[i]->Show(); // megjelen�t�s
        gout << refresh;
    }
}
void Application::Shutdown()
{
    isExiting = true; // kil�p�s inicializ�l�sa
}
