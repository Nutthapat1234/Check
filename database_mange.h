#ifndef DATABASE_MANGE_H
#define DATABASE_MANGE_H

#include<QSqlDatabase>
#include<QtSql>
#include "data.h"


class database_mange
{
public:
    database_mange();
    ~database_mange();
    bool sentUser(User data);
    bool sentProduct(Product data);
    bool receivePass(QString username);
    bool receiveProduct(QString code);
    QString getPassword();
    Product* getProduct();
private:
    void connectDatabase();
    Product *item = NULL;
    QString passFromdatabase;
    QSqlDatabase db;
};

#endif // DATABASE_MANGE_H
