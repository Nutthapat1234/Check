#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "password_mange.h"
#include "database_mange.h"
#include "productadd.h"
#include "adminmenu.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
signals:
    void correctPass();
    void backclick();
private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    int time_click = 0;
    Ui::login *ui;
    password_mange passSet;
    database_mange dataSet;
};

#endif // LOGIN_H
