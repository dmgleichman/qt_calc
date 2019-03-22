#include "temperatureconverter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TemperatureConverter w;
    w.show();

    return a.exec();
}
