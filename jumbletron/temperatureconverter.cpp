// temperatureconverter.cpp
// convert fahrenheit to celcius

#include <QtWidgets>

#include "temperatureconverter.h"
#include "jumbletronwindow.h"
#include "logwindow.h"


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

    connect(convertButton, SIGNAL(clicked()), this, SLOT(performConversion()));

    connect(fahrenheitDoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(fahrenheitChanged(double)));

    celciusLineEdit->setReadOnly(true);
    fahrenheitDoubleSpinBox->setRange(-1000000, 10000000);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fahrenheitLabel, 0, 0);
    mainLayout->addWidget(fahrenheitDoubleSpinBox, 0, 1);
    mainLayout->addWidget(celciusLabel, 1, 0);
    mainLayout->addWidget(celciusLineEdit, 1, 1);
    mainLayout->addWidget(convertButton, 2, 0, 1, 2);
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



