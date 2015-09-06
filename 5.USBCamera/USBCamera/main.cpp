#include "mainwindow.h"
#include <QApplication>

#include <QtMultimedia/QCamera>
#include <QtMultimedia/QCameraImageCapture>

#include <windows.h>
#include <glut.h>


void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,160.0);
}
void lineSegment()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE);
    glVertex2i(180,15);
    glVertex2i(10,145);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("Example of OpenGL");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();


    return a.exec();
}
