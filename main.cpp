#include "application.hpp"
#include "labelmodbutton.hpp"
#include "label.hpp"
#include "exitbutton.hpp"

int main()
{
    Application app(400,200);

    Label* l = new Label(50,50,"HUHU");
    LabelModButton* lmb = new LabelModButton(50, 150, 100, 25, "Modify");
    lmb->SetLabel(l);
    ExitButton* eb = new ExitButton(250, 150, 100, 25, "Exit");
    eb->SetApplication(&app);

    app.AddWidget(l);
    app.AddWidget(lmb);
    app.AddWidget(eb);
    app.Run();
    return 0;
}
