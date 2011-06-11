#include "application.hpp"
#include "button.hpp"
#include "lineeditor.hpp"

int main()
{
    Application app(212,239);

    Widget* scr = new LineEditor(9, 15, 194, 50);
    Widget* del = new Button(9, 72, 34, 27, "<-");
    Widget* ce = new Button(49, 72, 34, 27, "CE");
    Widget* c = new Button(89, 72, 34, 27, "C");
    Widget* pm = new Button(129, 72, 34, 27, "±");
    Widget* sqrt = new Button(169, 72, 34, 27, "√");
    Widget* n8 = new Button(49, 104, 34, 27, "8");
    Widget* n7 = new Button(9, 104, 34, 27, "7");
    Widget* n9 = new Button(89, 104, 34, 27, "9");
    Widget* div = new Button(129, 104, 34, 27, "/");
    Widget* mod = new Button(169, 104, 34, 27, "%");
    Widget* n4 = new Button(9, 136, 34, 27, "4");
    Widget* n5 = new Button(49, 136, 34, 27, "5");
    Widget* n6 = new Button(89, 136, 34, 27, "6");
    Widget* tim = new Button(129, 136, 34, 27, "*");
    Widget* rec = new Button(169, 136, 34, 27, "1/x");
    Widget* n1 = new Button(9, 168, 34, 27, "1");
    Widget* n2 = new Button(49, 168, 34, 27, "2");
    Widget* n3 = new Button(89, 168, 34, 27, "3");
    Widget* min = new Button(129, 168, 34, 27, "-");
    Widget* eq = new Button(169, 168, 34, 59, "=");
    Widget* n0 = new Button(9, 200, 74, 27, "0");
    Widget* com = new Button(89, 200, 34, 27, ",");
    Widget* plus = new Button(129, 200, 34, 27, "+");

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
