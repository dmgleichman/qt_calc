// main.cpp
// start top window app

#include <QApplication>

#include "top.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TopWindow top;

    top.show();

    return a.exec();
}
