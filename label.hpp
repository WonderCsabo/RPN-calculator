#ifndef LABEL_HPP
#define LABEL_HPP

#include "widget.hpp"
#include <string>

class Label: public Widget // c�mke vez�rl�je
{
public:
    Label(int px, int py, std::string text);
    void Show() const;
    void SetText(std::string text); // sz�veg be�ll�t�sa
    std::string Text() const { return labelText; }; // sz�veg lek�rdez�se
protected:
    std::string labelText;
};

#endif // LABEL_HPP
