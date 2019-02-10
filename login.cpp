#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QMessageBox>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color : rgb(64,224,208)");
    ui->usernameip->setPlaceholderText(QString("Username"));
    ui->passip->setPlaceholderText(QString("Password"));
}


login::~login()
{
    delete ui;
}




void login::on_pushButton_6_clicked()
{
    QString username =  ui->usernameip->text();
    QString pass = ui->passip->text();
    if(dataSet.receivePass(username)){
        if(username.isEmpty() || pass.isEmpty()){
            QMessageBox emptyinput;
            emptyinput.critical(0,"Error","Name or username or password is empty.");
            emptyinput.show();
        }
        else if(pass == passSet.decode(dataSet.getPassword())){
            emit this->correctPass();
        }
        else{
            QMessageBox emptyinput;
            emptyinput.critical(0,"Error","Name or passeord is incorrect");
            emptyinput.show();
        }
    }
}

void login::on_pushButton_5_clicked()
{
     emit this->backclick();
}

void login::on_pushButton_3_clicked()
{
    time_click += 1;
    if(time_click%2 == 1){
        ui->passip->setEchoMode(QLineEdit::Normal);
    }
    else if (time_click %2 == 0){
        ui->passip->setEchoMode(QLineEdit::Password);
    }
    if(time_click >= 10)
        time_click = 0;
}
