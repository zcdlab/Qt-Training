#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mThread=new Thread(this);
    connect(mThread,SIGNAL(numberChanged(int)),this,SLOT(onNumberChanged(int)));
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onNumberChanged(int num)
{
    ui->label->setText(QString::number(num));
}

void MainWindow::on_pushButton_clicked()
{
    mThread->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    mThread->stop=true;
}

void MainWindow::on_pushButton_3_clicked()
{
    mThread->wait();
}
