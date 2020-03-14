#ifndef PROJETMAINWINDOW_H
#define PROJETMAINWINDOW_H

#include <QMainWindow>
#include <raspicam_cv.h>
#include <iostream>
#include <QTimer>

namespace Ui {
class projetMainWindow;
}

class projetMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit projetMainWindow(QWidget *parent = nullptr);
    ~projetMainWindow();

private slots:

    void on_captureEtAffichageQTransform_clicked();

    void on_videoEnTempsReelButton_clicked();

    void on_arreterButton_clicked();

    void on_pauserButton_clicked();

private:
    Ui::projetMainWindow *ui;
    QImage cvMatToQImage2(const cv::Mat &inMat);
    raspicam::RaspiCam_Cv Camera_RaspicamCV;
    cv::Mat imageCvMat;
    QTimer *timer = new QTimer(this);
};

#endif // PROJETMAINWINDOW_H
