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

    fahrenheitDoubleSpinBox = new QDoubleSpinBox;
    celciusLineEdit = new QLineEdit;

    convertButton = new QPushButton("Convert");
    openJumbleButton = new QPushButton("Open Jumble");
    quitButton = new QPushButton("Quit");

    connect(convertButton, SIGNAL(clicked()), this, SLOT(performConversion()));

    connect(fahrenheitDoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(fahrenheitChanged(double)));

    connect(openJumbleButton, SIGNAL(clicked()),
            this, SLOT(openJumbleButtonClicked()));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitButtonClicked()));

    celciusLineEdit->setReadOnly(true);
    fahrenheitDoubleSpinBox->setRange(-1000000, 10000000);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fahrenheitLabel, 0, 0);
    mainLayout->addWidget(fahrenheitDoubleSpinBox, 0, 1);
    mainLayout->addWidget(celciusLabel, 1, 0);
    mainLayout->addWidget(celciusLineEdit, 1, 1);
    mainLayout->addWidget(convertButton, 2, 0, 1, 2);
    mainLayout->addWidget(openJumbleButton, 3, 0, 1, 2);
    mainLayout->addWidget(quitButton, 4, 0, 1, 2);
    setLayout(mainLayout);

    fahrenheitDoubleSpinBox->setValue(fahrenheit);

    setWindowTitle("Converter");
}

void TemperatureConverter::performConversion()
{
    fahrenheit = fahrenheitDoubleSpinBox->value();

    celcius = (fahrenheit - 32.0) * 5.0 / 9.0;

    celciusLineEdit->setText(QString::number(celcius));
}

void TemperatureConverter::fahrenheitChanged(double a)
{
    fahrenheit = a;

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
