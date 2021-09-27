#include <QApplication>
#include "window.h"
#include "calculationcontroller.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);


    CalculationController calcController;
    Window window(calcController.getCalculationModel());
    window.show();

    return app.exec();
}
