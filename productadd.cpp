#include "productadd.h"
#include "ui_productadd.h"
#include "camera_ui.h"
#include<QFileDialog>
#include<QObject>
#include <QMessageBox>

productAdd::productAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::productAdd)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color : rgb(64, 224, 208)");
}

productAdd::~productAdd()
{
    delete ui;   
}

void productAdd::on_fileip_clicked()
{
    filename = QFileDialog::getOpenFileName(this,tr("Select image"),"C:\\",
                                            "All File(*.*);;PNG(*.png);;JPG(*.jpg);;JPEG(*.jpeg)");
    if(filename.isEmpty()){
        QMessageBox emptyinput;
        emptyinput.critical(0,"Error","invalid file");
        emptyinput.show();
    }
    ui->showfilename->setText(filename);
}


void productAdd::on_back_clicked()
{
    emit this->backWard();
}




void productAdd::on_cofirm_clicked()
{
    database_mange data;
    QMessageBox emptyinput;
    QString name =  ui->nameip->text();
    QString price = ui->priceip->text();
    QString corp = ui->corpip->text();
    bool check = name.isEmpty() || price.isEmpty() || corp.isEmpty()  ;
    if(check){
        emptyinput.critical(0,"Error","Name or Price or Corparation is empty.");
        emptyinput.show();
        return;
    }
    else if(filename.isEmpty()){
        emptyinput.critical(0,"Error","Product Image is empty.");
        emptyinput.show();
        return;
    }
    else if(code.isEmpty()){
        emptyinput.critical(0,"Error","Code is empty.");
        emptyinput.show();
        return;
    }
    Product item(code,name,price,corp,filename);
    QMessageBox showMessage;
    if(!data.sentProduct(item)){
        showMessage.critical(0,"Error","Same Product!!!");
        showMessage.show();
        return;
    }
    showMessage.information(0,"Check","Success");
    showMessage.show();
    return;
}

void productAdd::on_codeip_clicked()
{
    camera_ui forCodeip;
    forCodeip.setphase(2);
    forCodeip.setWindowTitle("Check");
    forCodeip.setModal(true);
    forCodeip.exec();
    code = forCodeip.havecode();
    ui->showcode->setText(code);
}
