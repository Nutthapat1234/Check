#ifndef ACCOUNT_MANGE_H
#define ACCOUNT_MANGE_H

#include<QString>
#include<QJsonDocument>
#include "password_mange.h"
#include "database_mange.h"
using namespace std;
class Account_mange
{
public:
    static void signUp(QString name,QString username,QString password);
    static bool logIn(QString username,QString password);
private:
    static password_mange sec ; // sec from security
    static database_mange data;
};

#endif // ACCOUNT_MANGE_H
