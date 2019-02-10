#include "addadmin.h"
#include "ui_addadmin.h"
#include "password_mange.h"
#include "database_mange.h"
#include "data.h"
#include <QMessageBox>

AddAdmin::AddAdmin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddAdmin)
{
    ui->setupUi(this);
    ui->nameip->setPlaceholderText(QString("Name"));
    ui->usernameip->setPlaceholderText(QString("Username"));
    ui->passip->setPlaceholderText(QString("Password"));
    ui->re_passip->setPlaceholderText(QString("Re-password"));
}

AddAdmin::~AddAdmin()
{
    delete ui;
}

void AddAdmin::on_pushButton_clicked()
{
    password_mange passSet;
    database_mange dataSet;
    bool check = ui->nameip->text().isEmpty() || ui->usernameip->text().isEmpty() || ui->passip->text().isEmpty();
    if(check){
        QMessageBox emptyinput;
        emptyinput.critical(0,"Error","Name or username or password is empty.");
        emptyinput.show();
        return;
    }
    else if(ui->passip->text() != ui->re_passip->text()){
        QMessageBox mismatch;
        mismatch.critical(0,"Error","password and re-password are mismatch.");
        mismatch.show();
        return;
    }
    else if(ui->passip->text() == ui->re_passip->text())
    {
            User newAdmin(ui->nameip->text(),ui->usernameip->text(),
            passSet.encode(ui->passip->text()));
            QMessageBox UsedUser;
            if(!dataSet.sentUser(newAdmin)){
                UsedUser.critical(0,"Error","User already used");
                UsedUser.show();
                return;
            }
            UsedUser.information(0,"Check","Success");
            UsedUser.show();
            return;
     }

}
void AddAdmin::on_pushButton_6_clicked()
{
    emit this->backWard();
}

void AddAdmin::on_pushButton_5_clicked()
{
    time_click += 1;
    if(time_click%2 == 1){
        ui->passip->setEchoMode(QLineEdit::Normal);
        ui->re_passip->setEchoMode(QLineEdit::Normal);
    }
    else if (time_click %2 == 0){
        ui->passip->setEchoMode(QLineEdit::Password);
        ui->re_passip->setEchoMode(QLineEdit::Password);
    }
    if(time_click >= 10)
        time_click = 0;
}
