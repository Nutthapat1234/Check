#include "adminmenu.h"
#include "ui_adminmenu.h"

AdminMenu::AdminMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminMenu)
{
    ui->setupUi(this);
}

AdminMenu::~AdminMenu()
{
    delete ui;
}

void AdminMenu::on_pushButton_3_clicked()
{
    emit this->backWard();
}

void AdminMenu::on_pushButton_clicked()
{
    emit this->addProductClick();
}

void AdminMenu::on_pushButton_2_clicked()
{
    emit this->addNewAdminClick();
}
