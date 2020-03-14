#include "projetmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    projetMainWindow w;
    w.show();

    return a.exec();
}
