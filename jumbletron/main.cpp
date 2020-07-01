// main.cpp
// start top window app

#include <QApplication>

#include <QtWidgets>

#include "top.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TopWindow top;

    // set the application overall style to boxy and plain
    a.setStyle(QStyleFactory::create("Fusion"));

    top.show();

    return a.exec();
}
