#-------------------------------------------------
#
# Project created by QtCreator 2013-06-06T16:12:55
#这版本不能用 3.13做了修改 后来发觉不需要进行该修改
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpClient
TEMPLATE = app


SOURCES += main.cpp\
        tcpclient.cpp

HEADERS  += tcpclient.h

FORMS += \
    tcpclient.ui
RESOURCES += \
    images.qrc \
    images.qrc
