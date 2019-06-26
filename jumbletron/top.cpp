// top.cpp
// top level button choices

#include <QtWidgets>

#include "temperatureconverter.h"
#include "jumbletronwindow.h"
#include "logwindow.h"
#include "top.h"

TopWindow::TopWindow(QWidget *parent)
    : QWidget(parent)
{

    openTemperatureConverterButton = new QPushButton("Temperature Converter");
    openJumbleButton = new QPushButton("Open Jumble");
    openLogWindowButton = new QPushButton("Open Log Window");
    quitButton = new QPushButton("Quit");

    connect(openTemperatureConverterButton, SIGNAL(clicked()), this, SLOT(openTemperatureConverterClicked()));

    connect(openJumbleButton, SIGNAL(clicked()), this, SLOT(openJumbleButtonClicked()));

    connect(openLogWindowButton, SIGNAL(clicked()), this, SLOT(openLogWindowButtonClicked()));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitButtonClicked()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(openTemperatureConverterButton, 3, 0, 1, 2);
    mainLayout->addWidget(openJumbleButton, 4, 0, 1, 2);
    mainLayout->addWidget(openLogWindowButton, 5, 0, 1, 2);
    mainLayout->addWidget(quitButton, 6, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle("Top of the Jumble");
}

void TopWindow::openTemperatureConverterClicked()
{
    QWidget *tempConverter = new TemperatureConverter;

    tempConverter->show();
}

void TopWindow::openJumbleButtonClicked()
{
    QWidget *jumbleTron = new JumbleTronWindow;
    jumbleTron->show();
}

void TopWindow::openLogWindowButtonClicked()
{
    QWidget *logWindowWindow = new LogWindow();
    logWindowWindow->show();
}

void TopWindow::quitButtonClicked()
{

    int result = QMessageBox::question(this, "Quit", "Do you want to quit the program?");

    if (result == QMessageBox::Yes)
    {
       exit(0);
    }
}
