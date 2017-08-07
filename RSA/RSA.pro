#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T23:33:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
unix:LIBS+= -L/usr/lib -lgmpxx -lgmp
TARGET = RSA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    ifunc.h

FORMS    += mainwindow.ui
