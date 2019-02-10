#include "menu.h"
#include "ui_menu.h"
#include <QObject>
#include <QCloseEvent>
#include <QMessageBox>

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->setWindowTitle("Check");
    this->setStyleSheet("background-color : rgb(64, 224, 208)");


}

void Menu::setMenuAdmin()
{
    AdminMenu* correctLogin = new AdminMenu();
    this->setWindowTitle("Check");
    QObject::connect(correctLogin,SIGNAL(backWard()),this,SLOT(setLoginActive()));
    QObject::connect(correctLogin,SIGNAL(addProductClick()),this,SLOT(setAddProductActive()));
    QObject::connect(correctLogin,SIGNAL(addNewAdminClick()),this,SLOT(setAddAdminActive()));
    this->setCentralWidget(correctLogin);

}

void Menu::setLoginActive()
{
    login *loginAgin = new login();
    this->setWindowTitle("Check");
    QObject::connect(loginAgin,SIGNAL(correctPass()),this,SLOT(setLoginActive()));
    QObject::connect(loginAgin,SIGNAL(backclick()),this,SLOT(setBackActive()));
    this->setCentralWidget(loginAgin);
}

Menu::~Menu()
{
    delete ui;

}

void Menu::on_guest_clicked()
{
    cameraUi = new camera_ui();
    this->setWindowTitle("Check");
    cameraUi->setphase(1);
    QObject::connect(cameraUi,SIGNAL(backward()),this,SLOT(setBackActive()));
    this->setCentralWidget(cameraUi);
}

void Menu::on_admin_clicked()
{
    loginUi = new login();
    this->setCentralWidget(loginUi);
    this->setWindowTitle("Check");
    QObject::connect(loginUi,SIGNAL(correctPass()),this,SLOT(setMenuAdmin()));
    QObject::connect(loginUi,SIGNAL(backclick()),this,SLOT(setBackActive()));

}

void Menu::setBackActive(){
    ui->setupUi(this);
    this->setWindowTitle("Check");
}

void Menu::setAddProductActive()
{
    productAdd* productWindow = new productAdd();
    QObject::connect(productWindow,SIGNAL(backWard()),this,SLOT(setMenuAdmin()));
    this->setCentralWidget(productWindow);
    this->setWindowTitle("Check");
}

void Menu::setAddAdminActive()
{
    AddAdmin * newAdminWindow = new AddAdmin();
    QObject::connect(newAdminWindow,SIGNAL(backWard()),this,SLOT(setMenuAdmin()));
    this->setCentralWidget(newAdminWindow);
    this->setWindowTitle("Check");
}



void Menu::on_back_clicked()
{
    this->close();
}

void Menu::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this,"check",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
        this->close();
    }
}
