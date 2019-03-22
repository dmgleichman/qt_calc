#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <QMainWindow>

namespace Ui {
class TemperatureConverter;
}

class TemperatureConverter : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemperatureConverter(QWidget *parent = nullptr);
    ~TemperatureConverter();

private:
    Ui::TemperatureConverter *ui;
};

#endif // TEMPERATURECONVERTER_H
