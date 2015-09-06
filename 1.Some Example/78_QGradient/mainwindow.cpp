#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QLinearGradient lgrad(25,100,150,175);
    QRadialGradient rgrad(QPoint(100,100),100);
    QConicalGradient cgrad(QPoint(100,100),100);

    lgrad.setColorAt(0.0,Qt::red);
    lgrad.setColorAt(0.5,Qt::green);
    lgrad.setColorAt(1.0,Qt::blue);


    QRect rect(10,10,200,200);
    painter.fillRect(rect,lgrad);
    painter.fillRect(rect,rgrad);
    painter.fillRect(rect,cgrad);
}
