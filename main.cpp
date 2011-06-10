#include "application.hpp"
#include "labelmodbutton.hpp"
#include "label.hpp"
#include "exitbutton.hpp"

int main()
{
    Application app(212,239);

    Button* scr = new Button(9, 15, 194, 50, "screen goes here"); //this will be the screen
    Button* del = new Button(9, 72, 34, 27, "<-");
    Button* ce = new Button(49, 72, 34, 27, "CE");
    Button* c = new Button(89, 72, 34, 27, "C");
    Button* pm = new Button(129, 72, 34, 27, "±");
    Button* sqrt = new Button(169, 72, 34, 27, "√");
    Button* n8 = new Button(49, 104, 34, 27, "8");
    Button* n7 = new Button(9, 104, 34, 27, "7");
    Button* n9 = new Button(89, 104, 34, 27, "9");
    Button* div = new Button(129, 104, 34, 27, "/");
    Button* mod = new Button(169, 104, 34, 27, "%");
    Button* n4 = new Button(9, 136, 34, 27, "4");
    Button* n5 = new Button(49, 136, 34, 27, "5");
    Button* n6 = new Button(89, 136, 34, 27, "6");
    Button* tim = new Button(129, 136, 34, 27, "*");
    Button* rec = new Button(169, 136, 34, 27, "1/x");
    Button* n1 = new Button(9, 168, 34, 27, "1");
    Button* n2 = new Button(49, 168, 34, 27, "2");
    Button* n3 = new Button(89, 168, 34, 27, "3");
    Button* min = new Button(129, 168, 34, 27, "-");
    Button* eq = new Button(169, 168, 34, 59, "=");
    Button* n0 = new Button(9, 200, 74, 27, "0");
    Button* com = new Button(89, 200, 34, 27, ",");
    Button* plus = new Button(129, 200, 34, 27, "+");

    app.AddWidget(scr);
    app.AddWidget(del);
    app.AddWidget(ce);
    app.AddWidget(c);
    app.AddWidget(pm);
    app.AddWidget(sqrt);
    app.AddWidget(n7);
    app.AddWidget(n8);
    app.AddWidget(n9);
    app.AddWidget(div);
    app.AddWidget(mod);
    app.AddWidget(n4);
    app.AddWidget(n5);
    app.AddWidget(n6);
    app.AddWidget(tim);
    app.AddWidget(rec);
    app.AddWidget(n1);
    app.AddWidget(n2);
    app.AddWidget(n3);
    app.AddWidget(min);
    app.AddWidget(eq);
    app.AddWidget(n0);
    app.AddWidget(com);
    app.AddWidget(plus);
    app.Run();
    return 0;
}
