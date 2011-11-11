/**Image loading from files, and drawing to screen.**/

#include "image.hpp"
#include <graphics.hpp>
#include <fstream>
using namespace genv;
using namespace std;

std::vector<std::vector<std::vector<Color> > > Image::imgs;

Image::Image(vector<string> filenames)
{
    vector<vector<Color> > v; //temp matrix for the actual image

    for(unsigned int i=0; i<filenames.size(); i++)
    {
        ifstream f(filenames[i].c_str());
        unsigned int n, m;
        if(f)
        {
            f >> n >> m; // read the sizes
            v.resize(m); // resizing the matrix
            for (unsigned int i = 0; i < m; i++)
                v[i].resize(n);
            for (unsigned int i = 0; i < v.size(); i++)
                for (unsigned int j = 0; j < v[i].size(); j++)
                    f >> v[i][j].R >> v[i][j].G >> v[i][j].B;
            // read the 3 color components of the pixel
        }
        f.close();
        imgs.push_back(v); //add the image the the vector

    }
}

void Image::DrawImage(int x, int y, int type)
{
    for (unsigned int i = 0; i < imgs[type].size(); i++)
        for (unsigned int j = 0; j < imgs[type][i].size(); j++)
            gout << move_to(j+x, i+y) // transpose the matrix
            << color(imgs[type][i][j].R, imgs[type][i][j].G, imgs[type][i][j].B)
            << dot;
    // drawing the actual pixel
}
