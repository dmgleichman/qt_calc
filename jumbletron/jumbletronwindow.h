#ifndef JUMBLETRONWINDOW_H
#define JUMBLETRONWINDOW_H

#include <QMainWindow>

namespace Ui {
class JumbleTronWindow;
}

class JumbleTronWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit JumbleTronWindow(QWidget *parent = nullptr);
    ~JumbleTronWindow();

private:
    Ui::JumbleTronWindow *ui;
};

#endif // JUMBLETRONWINDOW_H
