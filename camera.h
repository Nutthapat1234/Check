#ifndef CAMERA_H
#define CAMERA_H


#include<QCameraImageCapture>
#include<QCamera>
#include<QObject>
#include"barcodelistener.h"

class Camera : public QObject
{

public:
    Camera(barcodelistener* instans);
    ~Camera();
    QCamera* openCamera(const QCameraInfo &cameraInfo);
    void capture();
    QString getcode(){return code;}
private slots:
    void imageCapture(int id,const QImage &img);
    void imageRemove(int id, const QString &fielname);

private:
    QString code;
    barcodelistener* cameraUse;
    QCamera *cameraObject;
    QCameraImageCapture *captureObject;

};

#endif // CAMERA_H
