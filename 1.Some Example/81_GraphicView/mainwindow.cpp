#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene =new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);
    QPen bluePen(Qt::blue);

   bluePen.setWidth(6);
   ellipse=scene->addEllipse(10,10,100,100,bluePen,redBrush);
   rectangle=scene->addRect(-100,-100,50,50,bluePen,greenBrush);
   rectangle->setFlag(QGraphicsItem::ItemIsMovable);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->rotate(-1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->rotate(+1);
}

void MainWindow::on_pushButton_2_pressed()
{
    ui->graphicsView->rotate(-1);
}

void MainWindow::on_pushButton_pressed()
{
    ui->graphicsView->rotate(+1);
}
