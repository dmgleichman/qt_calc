// top.h
// top level window

#ifndef TOP_H
#define TOP_H

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
QT_END_NAMESPACE


class TopWindow : public QWidget
{
    Q_OBJECT

public:
    TopWindow(QWidget *parent = nullptr);

private slots:
    void openJumbleButtonClicked();
    void openLogWindowButtonClicked();
    void openTemperatureConverterClicked();
    void quitButtonClicked();

private:

    QPushButton *openTemperatureConverterButton;

    QPushButton *openJumbleButton;

    QPushButton *openLogWindowButton;

    QPushButton *quitButton;

};

#endif // TOP_H
