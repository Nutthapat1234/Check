#include "account_mange.h"
#include "data.h"

password_mange Account_mange ::sec;
database_mange Account_mange ::data;



void Account_mange::signUp(QString name, QString username, QString password){

    QString endPass = sec.encode(password); // password encode
    User signUpUser(name,username,endPass);
    data.sentUser(signUpUser);
}

bool Account_mange::logIn(QString username, QString password){
    if(data.receivePass(username)){
        QString passFromdata = sec.decode(data.getPassword());
        if(password == passFromdata)
            return true;
    }
    return false;
}
