#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QLabel;
class QDoubleSpinBox;
QT_END_NAMESPACE


class TemperatureConverter : public QWidget
{
    Q_OBJECT

public:
    TemperatureConverter(QWidget *parent = nullptr);

private slots:
    void performConversion();
    void fahrenheitChanged(double fahr);

private:
    double fahrenheit;
    double celcius;

    QLabel *fahrenheitLabel;
    QLabel *celciusLabel;

    QDoubleSpinBox *fahrenheitDoubleSpinBox;
    QLineEdit *celciusLineEdit;

    QPushButton *convertButton;

};

#endif // TEMPERATURECONVERTER_H
