#include "productshow.h"
#include "ui_productshow.h"
#include <QImage>
#include <QPixmap>

productshow::productshow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::productshow)
{
    ui->setupUi(this);
}

productshow::~productshow()
{
    delete ui;
}

void productshow::showProductdetail(Product *itemtoshow){
   ui->showname->setText(itemtoshow->getName());
   ui->showprice->setText(itemtoshow->getPrice());
   ui->showcorp->setText(itemtoshow->getCorporation());
   QImage itemImage;
   itemImage.load(itemtoshow->getPathImage());
   ui->showpicture->setPixmap(QPixmap::fromImage(itemImage.scaled(QSize(300,300))));
}
