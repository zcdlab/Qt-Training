#-------------------------------------------------
#
# Project created by QtCreator 2015-05-02T15:00:25
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1_Example
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/E:/Qt/Qt5.4.0/Tools/mingw491_32/lib/ -lglut
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/E:/Qt/Qt5.4.0/Tools/mingw491_32/lib/ -lglutd

INCLUDEPATH += $$PWD/E:/Qt/Qt5.4.0/Tools/mingw491_32/include
DEPENDPATH += $$PWD/E:/Qt/Qt5.4.0/Tools/mingw491_32/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/E:/Qt/Qt5.4.0/Tools/mingw491_32/lib/ -lglut32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/E:/Qt/Qt5.4.0/Tools/mingw491_32/lib/ -lglut32d

INCLUDEPATH += $$PWD/E:/Qt/Qt5.4.0/Tools/mingw491_32/include
DEPENDPATH += $$PWD/E:/Qt/Qt5.4.0/Tools/mingw491_32/include
