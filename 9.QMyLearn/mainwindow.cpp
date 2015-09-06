#include <QtWidgets>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camera=new QCamera(this);
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);

    ui->horizontalLayout_View->addWidget(viewfinder);
    ui->label_Display->setScaledContents(true);

    camera->setViewfinder(viewfinder);
    camera->start();

    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));

    connect(ui->pushButton_Capture, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(ui->pushButton_Save, SIGNAL(clicked()), this, SLOT(saveImage()));
    connect(ui->pushButton_Quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::captureImage()
{
    ui->statusBar->showMessage(tr("正在捕获图片"), 1000);
    imageCapture->capture();
}

void MainWindow::displayImage(int /*id*/, QImage image)
{
    ui->label_Display->setPixmap(QPixmap::fromImage(image));
    ui->statusBar->showMessage(tr("捕获成功"), 5000);
}

void MainWindow::saveImage()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("保存到文件"), QDir::homePath(), tr("jpeg格式文件(*.jpg)"));
    if(fileName.isEmpty()) {
        ui->statusBar->showMessage(tr("保存操作已取消"), 5000);
        return;
    }
    const QPixmap* pixmap=ui->label_Display->pixmap();
    if(pixmap) {
        pixmap->save(fileName);
        ui->statusBar->showMessage(tr("保存成功"), 5000);
    }
}
