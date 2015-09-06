#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionChange_Color->setDisabled(true);
    ui->actionDulplicate->setDisabled(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::createEvent()
{
    ui->actionOpen_a_Bitmap->setStatusTip("Open a bitmap");
    connect(ui->actionOpen_a_Bitmap,SIGNAL(triggered()),this,SLOT(openFile()));
}


void MainWindow::openFile()
{
    QFileDialog *myFileDialog =new QFileDialog;
    myFileDialog->setModal(true);
    QStringList myStringList;
    //myFileDialog->setFilters(myStringList);
    imagePath=myFileDialog->getOpenFileName(this,tr("Open a Bitmap"),"","Bitmap(*.bmp);;Any File(*)");
}
