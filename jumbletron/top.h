// top.h
// top level window

#ifndef TOP_H
#define TOP_H

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QPlainTextEdit;
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
    void openChartDisplayButtonClicked();
    void openAppLayoutButtonClicked();
    void openUdpClientButtonClicked();
    void quitButtonClicked();

private:

    QLabel * actionsLabel;

    QPushButton *openTemperatureConverterButton;

    QPushButton *openJumbleButton;

    QPushButton *openLogWindowButton;

    QPushButton *openChartDisplayButton;

    QPushButton *openAppLayoutButton;

    QPushButton *openUdpClientButton;

    QPushButton *quitButton;

    QLabel * statusLabel;

    QPlainTextEdit *topStatusWindow;

};

#endif // TOP_H
