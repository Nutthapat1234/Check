#include "camera_ui.h"
#include "ui_camera_ui.h"
#include "productshow.h"
#include<QCameraInfo>

camera_ui::camera_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::camera_ui),
    cameraToshow(new Camera(this))
{
    ui->setupUi(this);
    setCamera();
}

camera_ui::~camera_ui()
{
    delete ui;
    delete cameraToshow;
}

inline void camera_ui::setCamera(){
    cameraToshow->openCamera(QCameraInfo::defaultCamera())->setViewfinder(ui->cameaShow);
}

void camera_ui::on_pushButton_clicked()
{
    cameraToshow->capture();
}

QString camera_ui::getcode(){
    return cameraToshow->getcode();
}

void camera_ui::haveProduct(QString code){
    qDebug()<<code;
    if(!(code == "")){
        if( connection->receiveProduct(code)){
            productshow showitem;
            showitem.showProductdetail(connection->getProduct());
            showitem.setModal(true);
            showitem.exec();

        }
    }
}

QString camera_ui::havecode(){
    return cameraToshow->getcode();
}

void camera_ui::showcode(){
    ui->showcode->setText(cameraToshow->getcode());
}

void camera_ui::onCoderead(QString code){
    qDebug() << "BARCODE : " << code;
    if(phase == 1){
       haveProduct(code);
    }
    else if(phase == 2){
        showcode();
    }
}

void camera_ui::on_pushButton_2_clicked()
{
    if(phase == 1)
        emit this->backward();
    if(phase == 2)
        this->close();
}
