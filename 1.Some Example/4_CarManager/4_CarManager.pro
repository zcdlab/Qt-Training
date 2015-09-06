#-------------------------------------------------
#
# Project created by QtCreator 2014-08-27T11:17:45
#
#-------------------------------------------------

QT       += core gui

QT       += sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4_CarManager
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    connection.h

FORMS    += widget.ui
