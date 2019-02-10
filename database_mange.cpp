#include "database_mange.h"
#include<QDebug>
#include<QString>


using namespace std;

database_mange::database_mange(){}
database_mange::~database_mange(){
    if(item != NULL)
        delete item;
}


void database_mange::connectDatabase(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\build-Check_application-Desktop_Qt_5_10_1_MinGW_32bit-Release\\sqlite\\check.db");
    if(!db.open()){
        qDebug()<<"Error : Connection with database fail.";
    }

}

bool database_mange::sentUser(User data){
    connectDatabase();
    QSqlQuery query(db);
    query.prepare("INSERT INTO CHECK_USER (name , username , password ) "
                  "VALUES (:name,:username,:password)");
    query.bindValue(QString(":name"),data.getName());
    query.bindValue(QString(":username"), data.getUsername());
    query.bindValue(QString(":password"), data.getPassword());
    bool success = query.exec();
    if(!success){
        db.close();
        QSqlDatabase::removeDatabase("C:\\sqlite\\check.db");
        return false ;
    }
    db.close();
    QSqlDatabase::removeDatabase("C:\\sqlite\\check.db");
    return true;
}

bool database_mange::sentProduct(Product data){
    connectDatabase();
    QSqlQuery query(db);
    query.prepare("INSERT INTO CHECK_PRODUCT (code,name,price,corparation,pathImage)"
                  "VALUES (:code,:name,:price,:corparation,:pathImage)");
    query.bindValue(QString(":code"),data.getCode());
    query.bindValue(QString(":name"), data.getName());
    query.bindValue(QString(":price"), data.getPrice());
    query.bindValue(QString(":corparation"),data.getCorporation());
    query.bindValue(QString(":pathImage"), data.getPathImage());
    bool success = query.exec();
    if(!success){
        db.close();
        QSqlDatabase::removeDatabase("QSQLITE");
        return false ;
    }
    db.close();
    QSqlDatabase::removeDatabase("QSQLITE");
    return true;
}

bool database_mange::receivePass(QString username)
{
    connectDatabase();
    QSqlQuery query(db);
    query.prepare("SELECT password FROM CHECK_USER WHERE username = :un ");
    query.bindValue(QString(":un"),username);
    bool success = query.exec();
    if(success){
        while(query.next()){
            passFromdatabase =  query.value(0).toString();
        }
        db.close();
        QSqlDatabase::removeDatabase("QSQLITE");
        return true;
    }
    db.close();
    QSqlDatabase::removeDatabase("QSQLITE");
    return false;
}

bool database_mange::receiveProduct(QString code){
    connectDatabase();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM CHECK_PRODUCT WHERE code = :code ");
    query.bindValue(QString(":code"),code);
    bool success = query.exec();
    if(success){
        QString c,n,p,cor,pi;
        while(query.next()){
            c = query.value(0).toString();
            n = query.value(1).toString();
            p = query.value(2).toString();
            cor = query.value(3).toString();
            pi = query.value(4).toString();

        }
        if(c.isEmpty() || n.isEmpty()|| p.isEmpty() || cor.isEmpty() || pi.isEmpty())
            return false;
        item = new Product(c,n,p,cor,pi);
        db.close();
        QSqlDatabase::removeDatabase("QSQLITE");
        return true;
    }
    db.close();
    QSqlDatabase::removeDatabase("QSQLITE");
    return false;
}

QString database_mange::getPassword(){
    if(passFromdatabase.isEmpty())
        return QString();
    return passFromdatabase;
}

Product* database_mange::getProduct(){
    return item;
}
