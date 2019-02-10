#include "data.h"


Product::Product(QString c,QString n, QString p, QString cor,QString pi)
    :name(n),price(p),pathImage(pi),corparation(cor),code(c){}
QString Product::getName(){return name;}
QString Product::getPrice(){return price;}
QString Product::getPathImage(){return pathImage;}
QString Product::getCorporation(){return corparation;}
QString Product::getCode(){return code;}


User::User(QString n, QString un, QString p):name(n),username(un),password(p){}
QString User::getName(){return name;}
QString User::getUsername(){return username;}
QString User::getPassword(){return password;}
