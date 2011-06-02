#ifndef LABEL_HPP
#define LABEL_HPP

#include "widget.hpp"
#include <string>

class Label: public Widget // label controller
{
public:
    Label(int px, int py, std::string text);
    void Show() const;
    void SetText(std::string text); // set the text
    std::string Text() const { return labelText; }; // get the text
protected:
    std::string labelText;
};

#endif // LABEL_HPP
