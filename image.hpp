#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

#include <vector>
#include <string>
#include "color.hpp"

class Image
{
private:

public:
    Image(std::vector<std::string> filenames); // constructor, loads the images from files

    static void DrawImage(int x, int y, int type); //draws the specific image

private:
    static std::vector<std::vector<std::vector<Color> > > imgs; //vector of the images
};

#endif // IMAGE_HPP_INCLUDED
