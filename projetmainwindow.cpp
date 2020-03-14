#include "projetmainwindow.h"
#include "ui_projetmainwindow.h"

projetMainWindow::projetMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::projetMainWindow)
{
    ui->setupUi(this);
}

projetMainWindow::~projetMainWindow()
{
    delete ui;
}
