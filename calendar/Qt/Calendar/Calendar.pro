#-------------------------------------------------
#
# Project created by QtCreator 2023-07-10T20:17:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calendar
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    pagelogin.cpp \
    user.cpp \
    md5.cpp \
    signup.cpp \
    addschedule.cpp \
    delschedule.cpp \
    modschedule.cpp \
    qstrans.cpp \
    schedule.cpp

HEADERS += \
        mainwindow.h \
    pagelogin.h \
    user.h \
    md5.h \
    signup.h \
    addschedule.h \
    delschedule.h \
    modschedule.h \
    qstrans.h \
    schedule.h

FORMS += \
        mainwindow.ui \
    pagelogin.ui \
    signup.ui \
    addschedule.ui \
    delschedule.ui \
    modschedule.ui

RESOURCES += \
    icon_regis.qrc \
    icon2.qrc
