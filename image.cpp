#include "image.hpp"
#include <graphics.hpp>
using namespace genv;
using namespace std;

Image::Image(string filename)
{
    ifstream f(filename.c_str());
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
}

void Image::DrawImage(int x, int y)
{
    for (unsigned int i = 0; i < v.size(); i++)
        for (unsigned int j = 0; j < v[i].size(); j++)
            gout << move_to(j+x, i+y) // transpose the matrix
            << color(v[i][j].R, v[i][j].G, v[i][j].B)
            << dot;
    // drawing the actual pixel
}
