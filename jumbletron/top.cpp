// top.cpp
// top level button choices

#include <QtWidgets>

#include "temperatureconverter.h"
#include "jumbletronwindow.h"
#include "logwindow.h"
#include "chart_display.h"
#include "top.h"

TopWindow::TopWindow(QWidget *parent)
    : QWidget(parent)
{

    actionsLabel = new QLabel("Actions:");

    openTemperatureConverterButton = new QPushButton("Temperature Converter");
    openJumbleButton = new QPushButton("Open Jumble");
    openLogWindowButton = new QPushButton("Open Log Window");
    openChartDisplayButton = new QPushButton("Open Chart Display");
    quitButton = new QPushButton("Quit");

    statusLabel = new QLabel("Status:");
    topStatusWindow = new QPlainTextEdit;

    connect(openTemperatureConverterButton, SIGNAL(clicked()), this, SLOT(openTemperatureConverterClicked()));

    connect(openJumbleButton, SIGNAL(clicked()), this, SLOT(openJumbleButtonClicked()));

    connect(openLogWindowButton, SIGNAL(clicked()), this, SLOT(openLogWindowButtonClicked()));

    connect(openChartDisplayButton, SIGNAL(clicked()), this, SLOT(openChartDisplayButtonClicked()));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitButtonClicked()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(actionsLabel, 1, 0, 1, 5);
    mainLayout->addWidget(openTemperatureConverterButton, 2, 0, 1, 5);
    mainLayout->addWidget(openJumbleButton, 3, 0, 1, 5);
    mainLayout->addWidget(openLogWindowButton, 4, 0, 1, 5);
    mainLayout->addWidget(openChartDisplayButton, 5, 0, 1, 5);
    mainLayout->addWidget(quitButton, 10, 0, 1, 5);

    mainLayout->addWidget(statusLabel, 1, 10, 1, 1);
    mainLayout->addWidget(topStatusWindow, 2, 10, 10, 50);

    setLayout(mainLayout);

    setWindowTitle("Top of the Jumble");
}

void TopWindow::openTemperatureConverterClicked()
{
    topStatusWindow->appendPlainText("Opening temperature converter window");

    QWidget *tempConverter = new TemperatureConverter;

    tempConverter->show();
}

void TopWindow::openJumbleButtonClicked()
{
    topStatusWindow->appendPlainText("Opening the JumbleTron Window");

    QWidget *jumbleTron = new JumbleTronWindow;

    jumbleTron->show();
}

void TopWindow::openLogWindowButtonClicked()
{
    topStatusWindow->appendPlainText("Opening the Log Window");

    QWidget *logWindowWindow = new LogWindow();

    logWindowWindow->show();
}

void TopWindow::openChartDisplayButtonClicked()
{
    topStatusWindow->appendPlainText("Opening Chart Display Window");

    QWidget *chartDisplayWindow = new ChartDisplay();

    chartDisplayWindow->show();
}

void TopWindow::quitButtonClicked()
{

    topStatusWindow->appendPlainText("User pressed quit button");

    int result = QMessageBox::question(this, "Quit", "Do you want to quit the program?");

    if (result == QMessageBox::Yes)
    {
       exit(0);
    }
    else
    {
        topStatusWindow->appendPlainText("User does not want to quit");
    }
}
