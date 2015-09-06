#-------------------------------------------------
#
# Project created by QtCreator 2015-04-28T21:14:14
#
# 1.多个ui之间传递参数，
# 2.并且实现了QString -> char *
# 3.实现选中字符复制到粘贴板上
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QString
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    password.cpp

HEADERS  += mainwindow.h \
    password.h

FORMS    += mainwindow.ui \
    password.ui
