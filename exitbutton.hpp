#ifndef EXITBUTTON_HPP
#define EXITBUTTON_HPP

#include "button.hpp"
#include "application.hpp"

class ExitButton : public Button // application exit button
{
public:
    ExitButton(int px, int py, int sx, int sy, std::string text, bool focus = false)
    : Button(px, py, sx, sy, text, focus)
    {
        application = NULL;
    }
    void SetApplication(Application* app) { application = app; } // setting the application
    Application* GetApplication() { return application; } // getting the application

protected:
    void Action() // overdefiniate the function
    {
        if (application) // if the pointer is not null
            application->Shutdown(); // exit the program
    }

    Application* application;
};

#endif // EXITBUTTON_HPP
