#ifndef PASSWORD_MANGE_H
#define PASSWORD_MANGE_H

#include<QString>
#include<Vector>
using namespace std;

class password_mange
{
public:
    password_mange();
    QString encode(QString p);
    QString decode(QString p);

private:
    void gen_key();
    QString password;
    QString encode_pass ;
    QString decoded_pass ;
    QString key = "CHECK";
    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    vector<QString> keys = {};

};

#endif // PASSWORD_MANGE_H
