#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QLabel;
class QPlainTextEdit;
QT_END_NAMESPACE


class LogWindow : public QWidget
{
    Q_OBJECT

public:
    LogWindow(QWidget *parent = nullptr);

private slots:
    void addToLogWindow();

private:
    QString lineOfText;

    QLabel *messageLabel;

    QLineEdit *messageLineEdit;

    QPushButton *enterMessagePushButton;

    QPlainTextEdit *plainTextLogWindow;

};

#endif // LOGWINDOW_H
