#include "temperatureconverter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TemperatureConverter tempConvert;
    tempConvert.show();

    return app.exec();
}

