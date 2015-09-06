#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T13:21:18
#
#简单的使用了 listWidget 取得widget 数目，根据数目进行多个随机数目的选择，并根据随机数来选取获奖者，打印出来
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lottery
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
