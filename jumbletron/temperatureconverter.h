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
    void openJumbleButtonClicked();
    void quitButtonClicked();
    void fahrenheitChanged(double fahr);
    void openLogWindowButtonClicked();

private:
    double fahrenheit;
    double celcius;

    QLabel *fahrenheitLabel;
    QLabel *celciusLabel;

    QDoubleSpinBox *fahrenheitDoubleSpinBox;
    QLineEdit *celciusLineEdit;

    QPushButton *convertButton;

    QPushButton *openJumbleButton;

    QPushButton *openLogWindowButton;

    QPushButton *quitButton;

};

#endif // TEMPERATURECONVERTER_H
