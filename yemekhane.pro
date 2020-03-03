#-------------------------------------------------
#
# Project created by QtCreator 2019-08-30T10:53:28
#
#-------------------------------------------------

QT       += core gui printsupport
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yemekhane
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        depourunekle.cpp \
        depourunkayit.cpp \
        main.cpp \
        mainwindow.cpp \
        pastane.cpp \
        pastaneurunekle.cpp \
        personelekle.cpp \
        personelkayit.cpp \
        personellogin.cpp \
        personelpanel.cpp \
        yemekhane.cpp \
        yemekhaneurunekle.cpp \
        yonetimlogin.cpp \
        yonetimpanel.cpp

HEADERS += \
        depourunekle.h \
        depourunkayit.h \
        mainwindow.h \
        pastane.h \
        pastaneurunekle.h \
        personelekle.h \
        personelkayit.h \
        personellogin.h \
        personelpanel.h \
        yemekhane.h \
        yemekhaneurunekle.h \
        yonetimlogin.h \
        yonetimpanel.h

FORMS += \
        depourunekle.ui \
        depourunkayit.ui \
        mainwindow.ui \
        pastane.ui \
        pastaneurunekle.ui \
        personelekle.ui \
        personelkayit.ui \
        personellogin.ui \
        personelpanel.ui \
        yemekhane.ui \
        yemekhaneurunekle.ui \
        yonetimlogin.ui \
        yonetimpanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
