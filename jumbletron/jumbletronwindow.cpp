#include "jumbletronwindow.h"
#include "ui_jumbletronwindow.h"

JumbleTronWindow::JumbleTronWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JumbleTronWindow)
{
    ui->setupUi(this);
}

JumbleTronWindow::~JumbleTronWindow()
{
    delete ui;
}
