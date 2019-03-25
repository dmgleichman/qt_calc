#include "temperatureconverter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TemperatureConverter tempConverter;

    tempConverter.show();


    return a.exec();
}
