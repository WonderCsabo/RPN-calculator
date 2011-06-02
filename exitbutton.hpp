#ifndef EXITBUTTON_HPP
#define EXITBUTTON_HPP

#include "button.hpp"
#include "application.hpp"

class ExitButton : public Button // alkalmaz�s kil�p� gomb
{
public:
    ExitButton(int px, int py, int sx, int sy, std::string text, bool focus = false)
    : Button(px, py, sx, sy, text, focus)
    {
        application = NULL;
    }
    void SetApplication(Application* app) { application = app; } // alkalmaz�s be�ll�t�sa
    Application* GetApplication() { return application; } // alkalmaz�s lek�rdez�se

protected:
    void Action() // fel�ldefini�ljuk az akci�f�ggv�nyt
    {
        if (application) // ha a mutat� nem nulla
            application->Shutdown(); // kil�p�nk a programb�l
    }

    Application* application;
};

#endif // EXITBUTTON_HPP
