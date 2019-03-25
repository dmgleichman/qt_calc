#include <QtWidgets>

#include "temperatureconverter.h"
#include "jumbletronwindow.h"


TemperatureConverter::TemperatureConverter(QWidget *parent)
    : QWidget(parent)
{
    fahrenheit = 0;
    celcius = 0;

    fahrenheitLabel = new QLabel("Fahrenheit:");
    celciusLabel = new QLabel("Celcius:");

    fahrenheitLineEdit = new QLineEdit;
    celciusLineEdit = new QLineEdit;

    convertButton = new QPushButton("Convert");
    openJumbleButton = new QPushButton("Open Jumble");
    quitButton = new QPushButton("Quit");

    connect(convertButton, SIGNAL(clicked()),
            this, SLOT(convertButtonClicked()));

    connect(openJumbleButton, SIGNAL(clicked()),
            this, SLOT(openJumbleButtonClicked()));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitButtonClicked()));

    celciusLineEdit->setReadOnly(true);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fahrenheitLabel, 0, 0);
    mainLayout->addWidget(fahrenheitLineEdit, 0, 1);
    mainLayout->addWidget(celciusLabel, 1, 0);
    mainLayout->addWidget(celciusLineEdit, 1, 1);
    mainLayout->addWidget(convertButton, 2, 0, 1, 2);
    mainLayout->addWidget(openJumbleButton, 3, 0, 1, 2);
    mainLayout->addWidget(quitButton, 4, 0, 1, 2);
    setLayout(mainLayout);

    fahrenheitLineEdit->setText(QString::number(fahrenheit));

    setWindowTitle("Converter");
}

void TemperatureConverter::convertButtonClicked()
{
    fahrenheit = fahrenheitLineEdit->text().toDouble();

    celcius = (fahrenheit - 32.0) * 5.0 / 9.0;

    celciusLineEdit->setText(QString::number(celcius));
}

 void TemperatureConverter::openJumbleButtonClicked()
 {
     QWidget *jumbleTron = new JumbleTronWindow;
     jumbleTron->show();
 }

 void TemperatureConverter::quitButtonClicked()
 {

     int result = QMessageBox::question(this, "Quit", "Do you want to quit the program?");

     if (result == QMessageBox::Yes)
     {
        exit(0);
     }
 }
