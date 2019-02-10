#ifndef BACODELISTENER_H
#define BACODELISTENER_H

#include<QString>

class barcodelistener
{
public:
    virtual void onCoderead(QString code) = 0;
};



#endif // BACODELISTENER_H
