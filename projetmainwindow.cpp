#include "projetmainwindow.h"
#include "ui_projetmainwindow.h"
#include <opencv2/videoio/legacy/constants_c.h>

using namespace std;
using namespace cv;

projetMainWindow::projetMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::projetMainWindow)
{
    ui->setupUi(this);
    Camera_RaspicamCV.set(CV_CAP_PROP_FORMAT, CV_16FC3);
    Camera_RaspicamCV.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    Camera_RaspicamCV.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

    // Ouvrir la caméra
    cout<<"Ouvre la caméra..."<<endl;
    if (!Camera_RaspicamCV.open()) {
        cout<<"Erreur d'ouvrir la caméra !"<<endl;
    }
}

projetMainWindow::~projetMainWindow()
{
    Camera_RaspicamCV.release();
    delete ui;
}

QImage projetMainWindow::cvMatToQImage2(const cv::Mat &inMat)
{
    switch ( inMat.type() )
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_ARGB32 );

        return image;
    }

        // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_RGB888 );

        return image.rgbSwapped();
    }

        // 8-bit, 1 channel
    case CV_8UC1:
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_Grayscale8 );
#else
        static QVector<QRgb>  sColorTable;

        // only create our color table the first time
        if ( sColorTable.isEmpty() )
        {
            sColorTable.resize( 256 );

            for ( int i = 0; i < 256; ++i )
            {
                sColorTable[i] = qRgb( i, i, i );
            }
        }

        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_Indexed8 );

        image.setColorTable( sColorTable );
#endif

        return image;
    }

    default:

        break;
    }

    return QImage();
}

void projetMainWindow::on_captureEtAffichageQTransform_clicked()
{
    cv::Mat imageCVMat_;

    // Commencer à prendre la photo
    Camera_RaspicamCV.grab();
    Camera_RaspicamCV.retrieve(imageCVMat_);
    ui->picture->setPixmap(QPixmap::fromImage(cvMatToQImage2(imageCVMat_)));
}

void projetMainWindow::on_videoEnTempsReelButton_clicked()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(on_captureEtAffichageQTransform_clicked()));
    timer->start();
}

void projetMainWindow::on_arreterButton_clicked()
{
    timer->disconnect();
}

void projetMainWindow::on_pauserButton_clicked()
{
    timer->stop();
}
