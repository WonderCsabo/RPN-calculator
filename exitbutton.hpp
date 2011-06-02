#ifndef EXITBUTTON_HPP
#define EXITBUTTON_HPP

#include "button.hpp"
#include "application.hpp"

class ExitButton : public Button // alkalmazás kilépõ gomb
{
public:
    ExitButton(int px, int py, int sx, int sy, std::string text, bool focus = false)
    : Button(px, py, sx, sy, text, focus)
    {
        application = NULL;
    }
    void SetApplication(Application* app) { application = app; } // alkalmazás beállítása
    Application* GetApplication() { return application; } // alkalmazás lekérdezése

protected:
    void Action() // felüldefiniáljuk az akciófüggvényt
    {
        if (application) // ha a mutató nem nulla
            application->Shutdown(); // kilépünk a programból
    }

    Application* application;
};

#endif // EXITBUTTON_HPP
