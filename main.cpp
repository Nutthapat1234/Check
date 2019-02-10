#include <QApplication>
#include "menu.h"
#include "password_mange.h"
#include "database_mange.h"
#include "data.h"
#include "account_mange.h"
#include "camera.h"
#include "addadmin.h"
#include<camera_ui.h>


#include<QScopedPointer>
#include<QCameraImageCapture>
#include<QCameraInfo>
#include<QCamera>
#include<iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu final_check;
    final_check.show();
    return a.exec();


}
