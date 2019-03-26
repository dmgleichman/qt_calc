#include <QtWidgets>

#include "logwindow.h"

LogWindow::LogWindow(QWidget *parent)
    : QWidget(parent)
{
    lineOfText = QString("");

    messageLabel = new QLabel("Message:");

    messageLineEdit = new QLineEdit;

    enterMessagePushButton = new QPushButton("Enter");

    plainTextLogWindow = new QPlainTextEdit;

    connect(enterMessagePushButton, SIGNAL(clicked()), this, SLOT(addToLogWindow()));

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(messageLabel, 0, 0);
    mainLayout->addWidget(messageLineEdit, 0, 1);
    mainLayout->addWidget(enterMessagePushButton, 1, 0);
    mainLayout->addWidget(plainTextLogWindow, 2, 0, 4, 5);
    setLayout(mainLayout);

    setWindowTitle("Log Window");

}

void LogWindow::addToLogWindow()
{
    lineOfText = messageLineEdit->text();
    messageLineEdit->setText("");

    if (lineOfText.size() > 0)
    {
        plainTextLogWindow->appendPlainText(lineOfText);
    }
}
