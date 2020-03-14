#ifndef PROJETMAINWINDOW_H
#define PROJETMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class projetMainWindow;
}

class projetMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit projetMainWindow(QWidget *parent = nullptr);
    ~projetMainWindow();

private:
    Ui::projetMainWindow *ui;
};

#endif // PROJETMAINWINDOW_H
