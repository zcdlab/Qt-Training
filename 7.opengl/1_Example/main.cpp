#include "mainwindow.h"
#include <QApplication>

#ifdef WIN32

#include <windows.h>
#include <GL/glut.h>

#else

#include <GLUT/glut.h>

#endif

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  glutInit(&argc, argv);

  return a.exec();
}
