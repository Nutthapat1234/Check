#ifndef ITEM_H
#define ITEM_H

#include<QString>
#include<vector>

using namespace std;

class Product
{
public:
    Product(QString c,QString n, QString p, QString cor,QString pi);
    QString getName();
    QString getPrice();
    QString getPathImage();
    QString getCorporation();
    QString getCode();

private:
    QString name;
    QString price;
    QString pathImage;
    QString corparation;
    QString code;
};


class User
{
public:
    User(QString n,QString un,QString p);
    QString getName();
    QString getUsername();
    QString getPassword();
private:
    QString name;
    QString username;
    QString password;
};

#endif // ITEM_H
