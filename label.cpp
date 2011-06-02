#include "label.hpp"
using namespace genv;

Label::Label(int px, int py, std::string text)
: Widget(px, py, gout.twidth(text), 12)
{
    labelText = text;
}
void Label::Show() const
{
    gout << move_to(posX, posX + 10) << color(255,255,255) << genv::text(labelText);
}
void Label::SetText(std::string text)
{
    labelText = text;
}
