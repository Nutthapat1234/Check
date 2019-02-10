#ifndef CAMERA_UI_H
#define CAMERA_UI_H

#include <QDialog>
#include <QCameraViewfinder>
#include<QScopedPointer>
#include<QString>
#include "camera.h"
#include "database_mange.h"
#include "barcodelistener.h"

namespace Ui {
class camera_ui;
}

class camera_ui : public QDialog , public barcodelistener
{
    Q_OBJECT

public:
    explicit camera_ui(QWidget *parent = 0);
    void setCamera();
    void haveProduct(QString code);
    void setphase(int check){phase = check ;}
    QString havecode();
    void showcode();
    void onCoderead(QString code);
    ~camera_ui();
signals:
    void backward();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    int phase;
    Ui::camera_ui *ui;
    Camera *cameraToshow;
    database_mange *connection = new database_mange();
    QString getcode();
};

#endif // CAMERA_UI_H
