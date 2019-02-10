QT       += core gui
QT       += sql
QT       += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(QZXing\QZXing.pri)

TARGET = Check_application
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    menu.cpp \
    password_mange.cpp \
    database_mange.cpp \
    data.cpp \
    account_mange.cpp \
    camera.cpp \
    camera_ui.cpp \
    productadd.cpp \
    productshow.cpp \
    login.cpp \
    addadmin.cpp \
    adminmenu.cpp


FORMS += \
    menu.ui \
    camera_ui.ui \
    productadd.ui \
    productshow.ui \
    login.ui \
    addadmin.ui \
    adminmenu.ui

HEADERS += \
    menu.h \
    password_mange.h \
    database_mange.h \
    data.h \
    account_mange.h \
    camera.h \
    camera_ui.h \
    productadd.h \
    productshow.h \
    barcodelistener.h \
    login.h \
    addadmin.h \
    adminmenu.h

RC_ICONS = icon.ico

DISTFILES += \
    Image/arrow.png \
    Image/capture.png \
    Image/check.png \
    Image/icon.png \
    Image/key.png \
    Image/person.png \
    Image/show.png


