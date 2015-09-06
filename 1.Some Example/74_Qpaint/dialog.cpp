#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::paintEvent(QPaintEvent *e)
{
    /*
    QPainter painter(this);
    QPen    paintpen(Qt::green);
    paintpen.setWidth(6);

    QPen    linepen(Qt::red);
    linepen.setWidth(2);

    QPoint p1;
    p1.setX(10);
    p1.setY(10);

    QPoint p2;
    p2.setX(100);
    p2.setY(100);

    painter.setPen(paintpen);
    painter.drawLine(p1,p2);
    */

    QPainter painter(this);
    QRect rect(10,1000,100,10);
    QPen pen(Qt::red);
    pen.setWidth(3);
    rect.setWidth(10);
    painter.setPen(pen);
    painter.drawRect(rect);
    painter.drawEllipse(rect);

}
