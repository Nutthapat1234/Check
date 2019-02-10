#include "camera.h"
#include<QCameraInfo>
#include"QZXing.h"
#include<QObject>



Camera::Camera(barcodelistener* instans){
    cameraUse = instans;
}
Camera::~Camera(){
    cameraObject->stop();
}


QCamera* Camera::openCamera(const QCameraInfo &cameraInfo){
    cameraObject = new QCamera;
    cameraObject->setCaptureMode(QCamera::CaptureStillImage);


    captureObject = new QCameraImageCapture(cameraObject);
    QObject::connect(captureObject,&QCameraImageCapture::imageSaved,this,&Camera::imageRemove);
    QObject::connect(captureObject,&QCameraImageCapture::imageCaptured,this,&Camera::imageCapture);


    cameraObject->start();
    return cameraObject;
}

void Camera::capture(){
    captureObject->capture("C:\\Users\\Check_application\\Image");
}

inline void Camera::imageCapture(int id, const QImage &img)
{
    Q_UNUSED(id);
    static QZXing decode;
    decode.setDecoder( QZXing::DecoderFormat_QR_CODE | QZXing::DecoderFormat_EAN_13 | QZXing::DecoderFormat_EAN_8 |
                       QZXing::DecoderFormat_UPC_A | QZXing::DecoderFormat_UPC_E |QZXing::DecoderFormat_UPC_EAN_EXTENSION);
    code = decode.decodeImage(img);
    qDebug()<<code;
    cameraUse->onCoderead(code);
}

void Camera::imageRemove(int id, const QString &fielname){

   QByteArray ba = fielname.toLatin1();
   const char *removeF = ba.data();
   remove(removeF);

}

