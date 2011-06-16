#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

#include <vector>
#include <string>
#include <fstream>
#include "color.hpp"


class Image
{
private:
    std::vector<std::vector<Color> > v;

public:
    Image(std::string filename);
    void DrawImage(int x, int y);
};

#endif // IMAGE_HPP_INCLUDED
