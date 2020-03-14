#include "projetmainwindow.h"
#include <iostream>
#include "main.h"
#include <QTransform>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    projetMainWindow w;
    w.show();

    return a.exec();
}
