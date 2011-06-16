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
    std::vector<std::vector<std::vector<Color> > > imgs; //vector of the images
    static void DrawImage(int x, int y, int type, std::vector<std::vector<std::vector<Color> > > &images); //draws the specific image
};

#endif // IMAGE_HPP_INCLUDED
