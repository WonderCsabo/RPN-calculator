#ifndef LINEEDITOR_HPP
#define LINEEDITOR_HPP

#include "widget.hpp"
#include <string>

class LineEditor : public Widget
{
public:
    LineEditor(int px, int py, int sx, int sy, bool focus = false);
    void Show() const;
    void HandleEvent(genv::event ev, std::string &s);
    void SetText(std::string text);
    std::string Text() const { return lineText; };
protected:
    std::string lineText; // stored text
    bool isUnderscore;
    Image *img;
};

#endif // LINEEDITOR_HPP
