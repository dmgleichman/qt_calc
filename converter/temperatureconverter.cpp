#include "temperatureconverter.h"
#include "ui_temperatureconverter.h"

TemperatureConverter::TemperatureConverter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TemperatureConverter)
{
    ui->setupUi(this);
}

TemperatureConverter::~TemperatureConverter()
{
    delete ui;
}
