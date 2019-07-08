#include <QtWidgets>

#include "logwindow.h"

LogWindow::LogWindow(QWidget *parent)
    : QWidget(parent)
{
    lineOfText = QString("");

    messageLabel = new QLabel("Message:");

    messageLineEdit = new QLineEdit;

    enterMessagePushButton = new QPushButton("Enter");

    loadFilePushButton = new QPushButton("Load");

    saveToFilePushButton = new QPushButton("Save");

    plainTextLogWindow = new QPlainTextEdit;

    connect(enterMessagePushButton, SIGNAL(clicked()), this, SLOT(addToLogWindow()));

    connect(loadFilePushButton, SIGNAL(clicked()), this, SLOT(loadFile()));

    connect(saveToFilePushButton, SIGNAL(clicked()), this, SLOT(saveLogToFile()));

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(messageLabel, 0, 0);
    mainLayout->addWidget(messageLineEdit, 0, 1, 1, 10);
    mainLayout->addWidget(enterMessagePushButton, 1, 0, 1, 1);
    mainLayout->addWidget(loadFilePushButton, 1, 1, 1, 1);
    mainLayout->addWidget(saveToFilePushButton, 1, 2, 1, 1);
    mainLayout->addWidget(plainTextLogWindow, 2, 0, 20, 30);
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

void LogWindow::loadFile()
{
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Open Document",
          QDir::currentPath(),
          "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");

    if( !filename.isNull() )
    {
      qDebug() << "Load file path:" << filename.toUtf8();
    }

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QString line = file.readLine();
        line = line.trimmed();      // remove new-line at end
        plainTextLogWindow->appendPlainText(line);
    }

}

void LogWindow::saveLogToFile()
{
    QString filename =  QFileDialog::getSaveFileName(
          this,
          "Save Document",
          QDir::currentPath(),
          "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");

    if( !filename.isNull() )
    {
      qDebug() << "Save file path:" << filename.toUtf8();
    }

    QString line;
    line = plainTextLogWindow->toPlainText();

    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite))
        return;

    QTextStream stream(&file);
    stream << "This is the log file:" << endl;

    stream << line << endl;

}
