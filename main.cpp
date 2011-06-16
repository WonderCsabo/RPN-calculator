/**Main, just starting the program with deterimined window size.**/
#include "application.hpp"

int main()
{
    Application *app = new Application(212,239);
    app->Run();
    delete app;
    return 0;
}
