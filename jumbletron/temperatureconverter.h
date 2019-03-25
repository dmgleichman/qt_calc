#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QLabel;
QT_END_NAMESPACE


class TemperatureConverter : public QWidget
{
    Q_OBJECT

public:
    TemperatureConverter(QWidget *parent = nullptr);

private slots:
    void convertButtonClicked();
    void openJumbleButtonClicked();
    void quitButtonClicked();

private:
    double fahrenheit;
    double celcius;

    QLabel *fahrenheitLabel;
    QLabel *celciusLabel;

    QLineEdit *fahrenheitLineEdit;
    QLineEdit *celciusLineEdit;

    QPushButton *convertButton;

    QPushButton *openJumbleButton;

    QPushButton *quitButton;

};

#endif // TEMPERATURECONVERTER_H
