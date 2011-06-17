/** The application layer, program initializing, event loop **/

#include "application.hpp"
#include <graphics.hpp>
#include "button.hpp"
#include "lineeditor.hpp"
#include "enterbutton.hpp"
using namespace genv;
using namespace std;

Application::Application(int x, int y): sizeX(x), sizeY(y)
{
    isExiting = false;
    focus = 0;

    // adding the controllers
    widgets.push_back(new LineEditor(11, 10, 194, 50)); //screen
    widgets.push_back(new Button(11, 72, 34, 27, "C"));
    widgets.push_back(new Button(50, 72, 34, 27, "CE"));
    widgets.push_back(new Button(89, 72, 34, 27, "("));
    widgets.push_back(new Button(128, 72, 34, 27, ")"));
    widgets.push_back(new Button(167, 72, 34, 27, "sqrt"));
    widgets.push_back(new Button(11, 104, 34, 27, "7"));
    widgets.push_back(new Button(50, 104, 34, 27, "8"));
    widgets.push_back(new Button(89, 104, 34, 27, "9"));
    widgets.push_back(new Button(128, 104, 34, 27, "/"));
    widgets.push_back(new Button(167, 104, 34, 27, "%"));
    widgets.push_back(new Button(11, 136, 34, 27, "4"));
    widgets.push_back(new Button(50, 136, 34, 27, "5"));
    widgets.push_back(new Button(89, 136, 34, 27, "6"));
    widgets.push_back(new Button(128, 136, 34, 27, "*"));
    widgets.push_back(new Button(167, 136, 34, 27, "^"));
    widgets.push_back(new Button(11, 168, 34, 27, "1"));
    widgets.push_back(new Button(50, 168, 34, 27, "2"));
    widgets.push_back(new Button(89, 168, 34, 27, "3"));
    widgets.push_back(new Button(128, 168, 34, 27, "-"));
    widgets.push_back(new EnterButton(167, 168, 34, 59, "=")); //this button fires calculating
    widgets.push_back(new Button(11, 200, 74, 27, "0"));
    widgets.push_back(new Button(89, 200, 34, 27, "."));
    widgets.push_back(new Button(128, 200, 34, 27, "+"));

    vector<string> v; // the location of the images of buttons
    v.push_back("background.kep");
    v.push_back("screen.kep");
    v.push_back("fbutton.kep");
    v.push_back("0button.kep");
    v.push_back("hbutton.kep");
    v.push_back("nbutton.kep");
    v.push_back("fbutton_m.kep");
    v.push_back("0button_m.kep");
    v.push_back("hbutton_m.kep");
    v.push_back("fbutton_m.kep");
    v.push_back("fbutton_c.kep");
    v.push_back("0button_c.kep");
    v.push_back("hbutton_c.kep");
    v.push_back("fbutton_c.kep");

    img = new Image(v); // image loader/drawer object
}

Application::~Application()
{
    for (unsigned int i = 0; i < widgets.size(); i++)
        delete widgets[i];

    delete img;
}

void Application::Run()
{
    gout.open(sizeX, sizeY); //open a new graphic window
    img->DrawImage(0,0,0,img->imgs); //draw the background
    gin.timer(700); //tick in every 700ms
    while (gin && !isExiting) // while it can accept events and not in exiting state
    {
        event ev; //event variable
        gin >> ev; //getting events

        if(ev.keycode == key_escape)
            Shutdown();
        else if ((ev.keycode == key_tab || ev.keycode == key_right) && widgets.size() > 0) // focus is chaned with tab or key_right
            focus++;
        else if(widgets.size() > 0 && ev.keycode == key_left) // focus is changed with key_left
            focus--;

        if(focus<0) //jump from last to first and vica versa
            focus = widgets.size()-1;
        else if(focus>widgets.size()-1)
            focus = 0;

        for (unsigned int i = 0; i < widgets.size(); i++)
            widgets[i]->SetFocus(focus == i);

        for (unsigned int i = 0; i < widgets.size(); i++)  // controllers in the vector
            widgets[i]->HandleEvent(ev, line); //event handling

        for (unsigned int i = 0; i < widgets.size(); i++)
            widgets[i]->Show(img->imgs); // displaying
        gout << refresh; // refreshing the screen
    }
}
void Application::Shutdown()
{
    isExiting = true; // initalizing exiting
}
