#include <QtWidgets>

#include "temperatureconverter.h"

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

    connect(convertButton, SIGNAL(clicked()),
            this, SLOT(buttonClicked()));

    celciusLineEdit->setReadOnly(true);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fahrenheitLabel, 0, 0);
    mainLayout->addWidget(fahrenheitLineEdit, 0, 1);
    mainLayout->addWidget(celciusLabel, 1, 0);
    mainLayout->addWidget(celciusLineEdit, 1, 1);
    mainLayout->addWidget(convertButton, 2, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle("Converter");
}

void TemperatureConverter::buttonClicked()
{
    fahrenheit = fahrenheitLineEdit->text().toDouble();

    celcius = (fahrenheit - 32.0) * 5.0 / 9.0;

    celciusLineEdit->setText(QString::number(celcius));
}
