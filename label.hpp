#ifndef LABEL_HPP
#define LABEL_HPP

#include "widget.hpp"
#include <string>

class Label: public Widget // címke vezérlõje
{
public:
    Label(int px, int py, std::string text);
    void Show() const;
    void SetText(std::string text); // szöveg beállítása
    std::string Text() const { return labelText; }; // szöveg lekérdezése
protected:
    std::string labelText;
};

#endif // LABEL_HPP
