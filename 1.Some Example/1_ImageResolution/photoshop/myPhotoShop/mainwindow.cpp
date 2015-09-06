#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resizedialog.h"
#include "manualDialog.h"
#include "matrixDialog.h"
#include "vertexdialog.h"
#include "gausscoredialog.h"
#include "elementdialog.h"
#include "grayelementdialog.h"
#include "newpicdialog.h"
#include <QFileDialog>
#include <qpainter.h>
#include <QPaintEvent>
#include <qmath.h>
#include <iostream>
#include <QtCore>

#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for(int i = 0; i < 256; i++)
        grayValue[i] = 0;
    ui->setupUi(this);
    ui->oldScrollArea->setBackgroundRole(QPalette::Dark);
    ui->oldScrollArea->widget()->setMinimumSize(498,498);
    ui->newScrollArea->setBackgroundRole(QPalette::Dark);
    ui->newScrollArea->widget()->setMinimumSize(498,498);
    havePic1 = false;
    havePic2 = false;
    testTime = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openPicture_triggered()
{
    QString File_Name =
    QFileDialog::getOpenFileName(this,tr("Open file"),"", tr("JPG(*.jpg);;BMP(*.bmp);;GIF(*.gif);;ALL files(*.*)"));
    if(File_Name!="")
    {
        QImage image(File_Name);

        QPixmap pixmap = QPixmap::fromImage(image);
        ui->picture1->setGeometry(pixmap.width()>498?0:(498-pixmap.width())/2,pixmap.height()>498?0:(498-pixmap.height())/2,pixmap.width(),pixmap.height());
//        ui->picture1->setMinimumSize(pixmap.width(),pixmap.height());
//        cout << pixmap.width() << " " << pixmap.height()<<endl;

        ui->oldScrollArea->widget()->setMinimumSize(pixmap.width()>498?pixmap.width():498,pixmap.height()>498?pixmap.height():498);
//        cout << ui->oldScrollArea->widget()->minimumWidth() << " " << ui->oldScrollArea->widget()->minimumHeight() << endl;
        ui->picture1->setPixmap(pixmap);
        havePic1 = true;
    }
}

void MainWindow::on_drawHistogram_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    QPixmap pixmap (*ui->picture1->pixmap());
    ui->picture2->setGeometry(pixmap.width()>498?0:(498-pixmap.width())/2,pixmap.height()>498?0:(498-pixmap.height())/2,pixmap.width(),pixmap.height());
    ui->newScrollArea->widget()->setMinimumSize(pixmap.width()>498?pixmap.width():498,pixmap.height()>498?pixmap.height():498);

    QImage image;

    QImage gray(pixmap.width(),pixmap.height(),QImage::Format_Indexed8);
    QVector<QRgb> colorTable;
    for(int i = 0; i < 256; i++)
        colorTable.push_back(QColor(i,i,i).rgb());
    gray.setColorTable(colorTable);
    image = pixmap.toImage();
    for( int i = 0; i < 256; i++ )
        grayValue[i] = 0;
    for (int i = 0; i < pixmap.width();i++)
    {
        for(int j = 0; j < pixmap.height();j++)
        {
            QRgb pixel = image.pixel(i,j);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            int temp = qGray(r,g,b);
            grayValue[temp]++;
            gray.setPixel(i,j,temp);
        }
    }
    ui->picture2->setPixmap(QPixmap::fromImage(gray));
    havePic2 = true;
    update();
}


//#include <QDebug>
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
//    if(grayValue[0] == null)
//        return;
//    qDebug() << "0";
    double max = 1;
    for(int i = 0;i < 256;i++)
    {
        if (max < grayValue[i])
            max = grayValue[i];
    }
//    painter.drawLine(100,710,100,580);
    painter.drawLine(100,710,100,580);
    painter.drawLine(100,710,640,710);
    for(int i = 0;i < 256;i++)
    {
//        cout << grayValue[i] << endl;
        double temp = (grayValue[i] / max) * 100.0;
        painter.drawLine(110+2*i,710,110+ 2*i,710- 1.1 * temp);
        painter.drawLine(110+2*i+1,710,110+ 2*i+1,710- 1.1 * temp);
    }
}

void MainWindow::on_reSize_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    reSizeDialog resize;
    connect(&resize, SIGNAL(resizeConfirm(int,int,bool,bool,bool)), this, SLOT(resizeConfirm(int,int,bool,bool,bool)));
    resize.exec();
}

void MainWindow::resizeConfirm(int x, int y, bool a, bool b, bool c)
{
    if(!(a||b||c))
    {
        QMessageBox::information(this, "", "Please Choose The Algorithm");
        return;
    }
    QPixmap pixmap (*ui->picture1->pixmap());
    ui->picture2->setGeometry(x>498?0:(498-x)/2,y>498?0:(498-y)/2,x,y);
    ui->newScrollArea->widget()->setMinimumSize(x>498?x:498,y>498?y:498);

    QImage image;
    QImage newPic(x,y,QImage::Format_ARGB32);
    image = pixmap.toImage();
    for (int i = 0; i < x;i++)
    {
        for(int j = 0; j < y;j++)
        {
            QRgb pixel;
            qreal theX = (qreal(i)/qreal(x))*qreal(pixmap.width());
            qreal theY = (qreal(j)/qreal(y))*qreal(pixmap.height());
            if(a)
            {
                pixel = nearest(image, theX, theY);
            }
            else if(b)
            {
                pixel = bilinear(image, theX, theY);
            }
            else
            {
                pixel = bicubic(image, theX, theY);
            }
            newPic.setPixel(i,j,pixel);
        }
    }
    ui->picture2->setPixmap(QPixmap::fromImage(newPic));
    havePic2 = true;
}

QRgb MainWindow::nearest(QImage image, qreal x, qreal y)
{
    return image.pixel(qRound(x),qRound(y));
}

QRgb MainWindow::bilinear(QImage image, qreal x, qreal y)
{
    qreal a = x - qFloor(x);
    qreal b = y - qFloor(y);
    int x1 = qFloor(x);
    int y1 = qFloor(y);
    int x2 = qCeil(x);
    int y2 = qCeil(y);
    QRgb pixel1 = image.pixel(x1,y1);
    QRgb pixel2 = image.pixel(x1,y2);
    QRgb pixel3 = image.pixel(x2,y1);
    QRgb pixel4 = image.pixel(x2,y2);
    QRgb pixel = qRgb(qRound((1-a)*(1-b)*qRed(pixel1)+(1-a)*b*qRed(pixel2)+a*(1-b)*qRed(pixel3)+a*b*qRed(pixel4)),
                      qRound((1-a)*(1-b)*qGreen(pixel1)+(1-a)*b*qGreen(pixel2)+a*(1-b)*qGreen(pixel3)+a*b*qGreen(pixel4)),
                      qRound((1-a)*(1-b)*qBlue(pixel1)+(1-a)*b*qBlue(pixel2)+a*(1-b)*qBlue(pixel3)+a*b*qBlue(pixel4)));
    return pixel;
}

QRgb MainWindow::bicubic(QImage image, qreal x, qreal y)
{
    QRgb pixel = qRgb(0,0,0);
    return pixel;
}

void MainWindow::on_actionManual_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    manualDialog manual;
    int threshold = manual.exec();

    if(threshold == -1)
        return;
    paintTwo(threshold);
    ui->theThreshold->setText(tr("%1").arg(threshold));
//    QMessageBox::information(this, "", tr("%1").arg(threshold));
}

void MainWindow::on_actionOtsu_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    updateGrayValue();
    for(int i = 0; i < 256; i++)
    {
//        cout << grayValue[i]<<endl;
        wValue[i] = double(grayValue[i])/double(totalPixel);
//        cout << wValue[i]<<endl;
    }
    int t = otsuReturn();
//    ui->x->setText(tr("%1").arg(t));
    paintTwo(t);
    ui->theThreshold->setText(tr("%1").arg(t));
}

void MainWindow::paintTwo(int threshold)
{
    QPixmap pixmap (*ui->picture1->pixmap());
    ui->picture2->setGeometry(pixmap.width()>498?0:(498-pixmap.width())/2,pixmap.height()>498?0:(498-pixmap.height())/2,pixmap.width(),pixmap.height());
    ui->newScrollArea->widget()->setMinimumSize(pixmap.width()>498?pixmap.width():498,pixmap.height()>498?pixmap.height():498);

    QImage image;

    QImage newPic(pixmap.width(),pixmap.height(),QImage::Format_Indexed8);
    QVector<QRgb> colorTable;
    colorTable.push_back(QColor(0,0,0).rgb());
    colorTable.push_back(QColor(255,255,255).rgb());
    newPic.setColorTable(colorTable);
    image = pixmap.toImage();
    for (int i = 0; i < pixmap.width();i++)
    {
        for(int j = 0; j < pixmap.height();j++)
        {
            QRgb pixel = image.pixel(i,j);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            int temp = qGray(r,g,b);
            if(temp >= threshold)
                newPic.setPixel(i,j,1);
            else
                newPic.setPixel(i,j,0);
        }
    }
    ui->picture2->setPixmap(QPixmap::fromImage(newPic));
    havePic2 = true;
}

void MainWindow::updateGrayValue()
{
    QPixmap pixmap (*ui->picture1->pixmap());
    for(int i = 0; i < 256; i++)
        grayValue[i] = 0;
    QImage image;
    image = pixmap.toImage();
    for (int i = 0; i < pixmap.width();i++)
    {
        for(int j = 0; j < pixmap.height();j++)
        {
            QRgb pixel = image.pixel(i,j);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            int temp = qGray(r,g,b);
            grayValue[temp]++;
        }
    }
    totalPixel = pixmap.width()*pixmap.height();
}

int MainWindow::otsuReturn()
{
    double result = 0;
    int t = -1;
    for(int i = 0; i < 256; i++)
    {
        double w0 = 0;
        double w1 = 0;
        for(int j = 0; j < i; j++)
            w0 = w0 + wValue[j];
        for(int j = i; j < 256; j++)
            w1 = w1 + wValue[j];
        double u0 = 0;
        double u1 = 0;
        for(int j = 0; j < i; j++)
            u0 = u0 + j*wValue[j];
        for(int j = i; j < 256; j++)
            u1 = u1 + j*wValue[j];
        double u = 0;
        for(int j = 0; j < 256; j++)
            u = u + j*wValue[j];
        double variance = w0*(u0-u)*(u0-u)+w1*(u1-u)*(u1-u);
        if(variance > result)
        {
            result = variance;
            t = i;
        }
    }
    return t;
}

void MainWindow::on_actionEntropy_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    updateGrayValue();
    int t = entropyReturn();
//    ui->x->setText(tr("%1").arg(t));
    paintTwo(t);
    ui->theThreshold->setText(tr("%1").arg(t));
}

int MainWindow::entropyReturn()
{
//    for(int i = 0; i < 256; i++)
//        cout << i << ":" << grayValue[i]  << endl;
    double result = 0;
    int t = -1;
    for( int i = 0; i < 256; i++ )
    {
        double n0 = 0;
        for(int j = 0; j < i; j++)
        {
            n0 = n0 + grayValue[j];
        }
        double n1 = totalPixel - n0;
        for(int j = 0; j < i; j++)
            wValue[j] = grayValue[j]/n0;
        for(int j = i; j < 256; j++)
            wValue[j] = grayValue[j]/n1;
        double h = 0;
        for(int j = 0; j < 256; j++)
        {
//            cout << i << ":" << qLn(wValue[j]) << endl;
            if(wValue[j]!=0)
                h = h - wValue[j]*qLn(wValue[j]);
        }
        if(h > result)
        {
            result = h;
            t = i;
        }
    }
    return t;
}

void MainWindow::on_Roberts_x_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(0,0,0,0,-1,0,0,0,1);
    getGrayTable();
    multiplyGrayTable(false);
    paintOverGrayConvolution();
}

void MainWindow::on_Roberts_y_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(0,0,0,0,-1,0,0,0,1);
    getGrayTable();
    multiplyGrayTable(true);
    paintOverGrayConvolution();
}

void MainWindow::on_prewitt_x_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(-1,-1,-1,0,0,0,1,1,1);
    getGrayTable();
    multiplyGrayTable(false);
    paintOverGrayConvolution();
}

void MainWindow::on_prewitt_y_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(-1,-1,-1,0,0,0,1,1,1);
    getGrayTable();
    multiplyGrayTable(true);
    paintOverGrayConvolution();
}

void MainWindow::on_sobel_x_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(-1,-2,-1,0,0,0,1,2,1);
    getGrayTable();
    multiplyGrayTable(false);
    paintOverGrayConvolution();
}

void MainWindow::on_sobel_y_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(-1,-2,-1,0,0,0,1,2,1);
    getGrayTable();
    multiplyGrayTable(true);
    paintOverGrayConvolution();
}

void MainWindow::on_Roberts_RGB_x_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
//    cout << "1" << endl;
    setMatrix(0,0,0,0,-1,0,0,0,1);
    getRGBTable();
    multiplyRGBTable(false);
    paintOverRGBConvolution();
}

void MainWindow::on_Roberts_RGB_y_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(0,0,0,0,-1,0,0,0,1);
    getRGBTable();
    multiplyRGBTable(true);
    paintOverRGBConvolution();
}

void MainWindow::on_prewitt_RGB_x_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(-1,-1,-1,0,0,0,1,1,1);
    getRGBTable();
    multiplyRGBTable(false);
    paintOverRGBConvolution();
}

void MainWindow::on_prewitt_RGB_y_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(-1,-1,-1,0,0,0,1,1,1);
    getRGBTable();
    multiplyRGBTable(true);
    paintOverRGBConvolution();
}

void MainWindow::on_sobel_RGB_x_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(-1,-2,-1,0,0,0,1,2,1);
    getRGBTable();
    multiplyRGBTable(false);
    paintOverRGBConvolution();
}

void MainWindow::on_sobel_RGB_y_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    setMatrix(-1,-2,-1,0,0,0,1,2,1);
    getRGBTable();
    multiplyRGBTable(true);
    paintOverRGBConvolution();
}

void MainWindow::setMatrix(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3)
{
    matrix[0][0] = a1;
    matrix[0][1] = a2;
    matrix[0][2] = a3;
    matrix[1][0] = b1;
    matrix[1][1] = b2;
    matrix[1][2] = b3;
    matrix[2][0] = c1;
    matrix[2][1] = c2;
    matrix[2][2] = c3;
}

void MainWindow::getGrayTable()
{
    QPixmap pixmap (*ui->picture1->pixmap());
    QImage image;
    image = pixmap.toImage();
    width = pixmap.width();
    height = pixmap.height();
    grayTable = new int[(height+2)*(width+2)];

    for (int i = 0; i < height;i++)
    {
        for(int j = 0; j < width;j++)
        {
            QRgb pixel = image.pixel(j,i);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            int temp = qGray(r,g,b);
            grayTable[(i+1)*(width+2)+j+1] = temp;
        }
    }
    for(int i = 1; i <= height; i++)
    {
        grayTable[i*(width+2)] = grayTable[i*(width+2)+1];
        grayTable[i*(width+2)+width+1] = grayTable[i*(width+2)+width];
    }
    for(int i = 1; i <= width; i++)
    {
        grayTable[i] = grayTable[i+width+2];
        grayTable[(height+1)*(width+2)+i] = grayTable[height*(width+2)+i];
    }
    grayTable[0] = grayTable[width+3];
    grayTable[width+1] = grayTable[2*width+2];
    grayTable[(height+1)*(width+2)] = grayTable[height*(width+2)+1];
    grayTable[(height+1)*(width+2)+width+1] = grayTable[height*(width+2)+width];
/*
    for(int i = 0; i < height+1; i++)
    {
        cout << i << ":";
        for(int j = 0; j < width+1; j++)
        {
            if(grayTable[i*(width+2)+j]>255||grayTable[i*(width+2)+j]<0)
                cout << 111 << " ";
        }
        cout << endl;
    }
    */
}

void MainWindow::getRGBTable()
{
    QPixmap pixmap (*ui->picture1->pixmap());
    QImage image;
    image = pixmap.toImage();
    width = pixmap.width();
    height = pixmap.height();
    rTable = new int[(height+2)*(width+2)];
    gTable = new int[(height+2)*(width+2)];
    bTable = new int[(height+2)*(width+2)];

    for (int i = 0; i < height;i++)
    {
        for(int j = 0; j < width;j++)
        {
            QRgb pixel = image.pixel(j,i);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            rTable[(i+1)*(width+2)+j+1] = r;
            gTable[(i+1)*(width+2)+j+1] = g;
            bTable[(i+1)*(width+2)+j+1] = b;
        }
    }
    for(int i = 1; i <= height; i++)
    {
        rTable[i*(width+2)] = rTable[i*(width+2)+1];
        rTable[i*(width+2)+width+1] = rTable[i*(width+2)+width];
        gTable[i*(width+2)] = gTable[i*(width+2)+1];
        gTable[i*(width+2)+width+1] = gTable[i*(width+2)+width];
        bTable[i*(width+2)] = bTable[i*(width+2)+1];
        bTable[i*(width+2)+width+1] = bTable[i*(width+2)+width];
    }
    for(int i = 1; i <= width; i++)
    {
        rTable[i] = rTable[i+width+2];
        rTable[(height+1)*(width+2)+i] = rTable[height*(width+2)+i];
        gTable[i] = gTable[i+width+2];
        gTable[(height+1)*(width+2)+i] = gTable[height*(width+2)+i];
        bTable[i] = bTable[i+width+2];
        bTable[(height+1)*(width+2)+i] = bTable[height*(width+2)+i];
    }
    rTable[0] = rTable[width+3];
    rTable[width+1] = rTable[2*width+2];
    rTable[(height+1)*(width+2)] = rTable[height*(width+2)+1];
    rTable[(height+1)*(width+2)+width+1] = rTable[height*(width+2)+width];
    gTable[0] = gTable[width+3];
    gTable[width+1] = gTable[2*width+2];
    gTable[(height+1)*(width+2)] = gTable[height*(width+2)+1];
    gTable[(height+1)*(width+2)+width+1] = gTable[height*(width+2)+width];
    bTable[0] = bTable[width+3];
    bTable[width+1] = bTable[2*width+2];
    bTable[(height+1)*(width+2)] = bTable[height*(width+2)+1];
    bTable[(height+1)*(width+2)+width+1] = bTable[height*(width+2)+width];
}

void MainWindow::getGrayPicture(int N)
{
    QPixmap pixmap (*ui->picture1->pixmap());
    QImage image;
    image = pixmap.toImage();
    width = pixmap.width();
    height = pixmap.height();
    grayTable = new int[(height+2*N)*(width+2*N)];

    for (int i = 0; i < height;i++)
    {
        for(int j = 0; j < width;j++)
        {
            QRgb pixel = image.pixel(j,i);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            int temp = qGray(r,g,b);
            grayTable[(i+N)*(width+2*N)+j+N] = temp;
        }
    }
}

void MainWindow::getGrayTableN(int N)
{
    for(int j = 0; j < N; j++)
    {
        for(int i = N; i < height+N; i++)
        {
            grayTable[i*(width+2*N)+j] = grayTable[i*(width+2*N)+N];
        }
    }
    for(int j = width+N; j < width+2*N; j++)
    {
        for(int i = N; i < height+N; i++)
        {
            grayTable[i*(width+2*N)+j] = grayTable[i*(width+2*N)+width+N-1];
        }
    }
    for(int j = 0; j < N; j++)
    {
        for(int i = N; i < width+N; i++)
        {
            grayTable[j*(width+2*N)+i] = grayTable[N*(width+2*N)+i];;
        }
    }
    for(int j = height+N; j < height+2*N; j++)
    {
        for(int i = N; i < width+N; i++)
        {
            grayTable[j*(width+2*N)+i] = grayTable[(height+N-1)*(width+2*N)+i];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grayTable[i*(width+2*N)+j] = grayTable[N*(width+2*N)+N];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = width+N; j < width+2*N; j++)
        {
            grayTable[i*(width+2*N)+j] = grayTable[N*(width+2*N)+width+N-1];
        }
    }
    for(int i = height+N; i < height+2*N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grayTable[i*(width+2*N)+j] = grayTable[(height+N-1)*(width+2*N)+N];
        }
    }
    for(int i = height+N; i < height+2*N; i++)
    {
        for(int j = width+N; j < width+2*N; j++)
        {
            grayTable[i*(width+2*N)+j] = grayTable[(height+N-1)*(width+2*N)+width+N-1];
        }
    }
}

void MainWindow::getRGBTableN(int N)
{
    QPixmap pixmap (*ui->picture1->pixmap());
    QImage image;
    image = pixmap.toImage();
    width = pixmap.width();
    height = pixmap.height();
    rTable = new int[(height+2*N)*(width+2*N)];
    gTable = new int[(height+2*N)*(width+2*N)];
    bTable = new int[(height+2*N)*(width+2*N)];

    for (int i = 0; i < height;i++)
    {
        for(int j = 0; j < width;j++)
        {
            QRgb pixel = image.pixel(j,i);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            rTable[(i+N)*(width+2*N)+j+N] = r;
            gTable[(i+N)*(width+2*N)+j+N] = g;
            bTable[(i+N)*(width+2*N)+j+N] = b;
        }
    }
    for(int j = 0; j < N; j++)
    {
        for(int i = N; i < height+N; i++)
        {
            rTable[i*(width+2*N)+j] = rTable[i*(width+2*N)+N];
            gTable[i*(width+2*N)+j] = gTable[i*(width+2*N)+N];
            bTable[i*(width+2*N)+j] = bTable[i*(width+2*N)+N];
        }
    }
    for(int j = width+N; j < width+2*N; j++)
    {
        for(int i = N; i < height+N; i++)
        {
            rTable[i*(width+2*N)+j] = rTable[i*(width+2*N)+width+N-1];
            gTable[i*(width+2*N)+j] = gTable[i*(width+2*N)+width+N-1];
            bTable[i*(width+2*N)+j] = bTable[i*(width+2*N)+width+N-1];
        }
    }
    for(int j = 0; j < N; j++)
    {
        for(int i = N; i < width+N; i++)
        {
            rTable[j*(width+2*N)+i] = rTable[N*(width+2*N)+i];
            gTable[j*(width+2*N)+i] = gTable[N*(width+2*N)+i];
            bTable[j*(width+2*N)+i] = bTable[N*(width+2*N)+i];
        }
    }
    for(int j = height+N; j < height+2*N; j++)
    {
        for(int i = N; i < width+N; i++)
        {
            rTable[j*(width+2*N)+i] = rTable[(height+N-1)*(width+2*N)+i];
            gTable[j*(width+2*N)+i] = gTable[(height+N-1)*(width+2*N)+i];
            bTable[j*(width+2*N)+i] = bTable[(height+N-1)*(width+2*N)+i];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            rTable[i*(width+2*N)+j] = rTable[N*(width+2*N)+N];
            gTable[i*(width+2*N)+j] = gTable[N*(width+2*N)+N];
            bTable[i*(width+2*N)+j] = bTable[N*(width+2*N)+N];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = width+N; j < width+2*N; j++)
        {
            rTable[i*(width+2*N)+j] = rTable[N*(width+2*N)+width+N-1];
            gTable[i*(width+2*N)+j] = gTable[N*(width+2*N)+width+N-1];
            bTable[i*(width+2*N)+j] = bTable[N*(width+2*N)+width+N-1];
        }
    }
    for(int i = height+N; i < height+2*N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            rTable[i*(width+2*N)+j] = rTable[(height+N-1)*(width+2*N)+N];
            gTable[i*(width+2*N)+j] = gTable[(height+N-1)*(width+2*N)+N];
            bTable[i*(width+2*N)+j] = bTable[(height+N-1)*(width+2*N)+N];
        }
    }
    for(int i = height+N; i < height+2*N; i++)
    {
        for(int j = width+N; j < width+2*N; j++)
        {
            rTable[i*(width+2*N)+j] = rTable[(height+N-1)*(width+2*N)+width+N-1];
            gTable[i*(width+2*N)+j] = gTable[(height+N-1)*(width+2*N)+width+N-1];
            bTable[i*(width+2*N)+j] = bTable[(height+N-1)*(width+2*N)+width+N-1];
        }
    }
}

void MainWindow::multiplyGrayTable( bool flag )
{
    resultGrayTable = new int[height*width];
    if(flag)
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                resultGrayTable[i*width+j] = grayTable[i*(width+2)+j]*matrix[0][0]
                                           + grayTable[i*(width+2)+j+1]*matrix[0][1]
                                           + grayTable[i*(width+2)+j+2]*matrix[0][2]
                                           + grayTable[(i+1)*(width+2)+j]*matrix[1][0]
                                           + grayTable[(i+1)*(width+2)+j+1]*matrix[1][1]
                                           + grayTable[(i+1)*(width+2)+j+2]*matrix[1][2]
                                           + grayTable[(i+2)*(width+2)+j]*matrix[2][0]
                                           + grayTable[(i+2)*(width+2)+j+1]*matrix[2][1]
                                           + grayTable[(i+2)*(width+2)+j+2]*matrix[2][2];

                if(resultGrayTable[i*width+j]>255)
                {
                    resultGrayTable[i*width+j] = 255;
                }
                else if(resultGrayTable[i*width+j]<0)
                {
                    resultGrayTable[i*width+j] = 0;
                }

//                cout << resultRTable[i*width+j]<<" "<<resultGTable[i*width+j]<<" "<<resultBTable[i*width+j]<<endl;
            }
        }
    }
    else
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                resultGrayTable[i*width+j] = grayTable[i*(width+2)+j]*matrix[0][0]
                                           + grayTable[i*(width+2)+j+1]*matrix[1][0]
                                           + grayTable[i*(width+2)+j+2]*matrix[2][0]
                                           + grayTable[(i+1)*(width+2)+j]*matrix[0][1]
                                           + grayTable[(i+1)*(width+2)+j+1]*matrix[1][1]
                                           + grayTable[(i+1)*(width+2)+j+2]*matrix[2][1]
                                           + grayTable[(i+2)*(width+2)+j]*matrix[0][2]
                                           + grayTable[(i+2)*(width+2)+j+1]*matrix[1][2]
                                           + grayTable[(i+2)*(width+2)+j+2]*matrix[2][2];
                if(resultGrayTable[i*width+j]>255)
                {
                    resultGrayTable[i*width+j] = 255;
                }
                else if(resultGrayTable[i*width+j]<0)
                {
                    resultGrayTable[i*width+j] = 0;
                }
//                cout << resultGrayTable[i*width+j] << endl;
//                cout << resultRTable[i*width+j]<<" "<<resultGTable[i*width+j]<<" "<<resultBTable[i*width+j]<<endl;
            }
        }
    }
}

void MainWindow::multiplyRGBTable( bool flag )
{
    resultRTable = new int[height*width];
    resultGTable = new int[height*width];
    resultBTable = new int[height*width];
    if(flag)
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                resultRTable[i*width+j] = rTable[i*(width+2)+j]*matrix[0][0]
                                        + rTable[i*(width+2)+j+1]*matrix[0][1]
                                        + rTable[i*(width+2)+j+2]*matrix[0][2]
                                        + rTable[(i+1)*(width+2)+j]*matrix[1][0]
                                        + rTable[(i+1)*(width+2)+j+1]*matrix[1][1]
                                        + rTable[(i+1)*(width+2)+j+2]*matrix[1][2]
                                        + rTable[(i+2)*(width+2)+j]*matrix[2][0]
                                        + rTable[(i+2)*(width+2)+j+1]*matrix[2][1]
                                        + rTable[(i+2)*(width+2)+j+2]*matrix[2][2];
                resultGTable[i*width+j] = gTable[i*(width+2)+j]*matrix[0][0]
                                        + gTable[i*(width+2)+j+1]*matrix[0][1]
                                        + gTable[i*(width+2)+j+2]*matrix[0][2]
                                        + gTable[(i+1)*(width+2)+j]*matrix[1][0]
                                        + gTable[(i+1)*(width+2)+j+1]*matrix[1][1]
                                        + gTable[(i+1)*(width+2)+j+2]*matrix[1][2]
                                        + gTable[(i+2)*(width+2)+j]*matrix[2][0]
                                        + gTable[(i+2)*(width+2)+j+1]*matrix[2][1]
                                        + gTable[(i+2)*(width+2)+j+2]*matrix[2][2];
                resultBTable[i*width+j] = bTable[i*(width+2)+j]*matrix[0][0]
                                        + bTable[i*(width+2)+j+1]*matrix[0][1]
                                        + bTable[i*(width+2)+j+2]*matrix[0][2]
                                        + bTable[(i+1)*(width+2)+j]*matrix[1][0]
                                        + bTable[(i+1)*(width+2)+j+1]*matrix[1][1]
                                        + bTable[(i+1)*(width+2)+j+2]*matrix[1][2]
                                        + bTable[(i+2)*(width+2)+j]*matrix[2][0]
                                        + bTable[(i+2)*(width+2)+j+1]*matrix[2][1]
                                        + bTable[(i+2)*(width+2)+j+2]*matrix[2][2];
                if(resultRTable[i*width+j]>255)
                    resultRTable[i*width+j] = 255;
                else if(resultRTable[i*width+j]<0)
                    resultRTable[i*width+j] = 0;
                if(resultGTable[i*width+j]>255)
                    resultGTable[i*width+j] = 255;
                else if(resultGTable[i*width+j]<0)
                    resultGTable[i*width+j] = 0;
                if(resultBTable[i*width+j]>255)
                    resultBTable[i*width+j] = 255;
                else if(resultBTable[i*width+j]<0)
                    resultBTable[i*width+j] = 0;
//                cout << resultRTable[i*width+j]<<" "<<resultGTable[i*width+j]<<" "<<resultBTable[i*width+j]<<endl;
            }
        }
//        cout << 1 << endl;
    }
    else
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                resultRTable[i*width+j] = rTable[i*(width+2)+j]*matrix[0][0]
                                        + rTable[i*(width+2)+j+1]*matrix[1][0]
                                        + rTable[i*(width+2)+j+2]*matrix[2][0]
                                        + rTable[(i+1)*(width+2)+j]*matrix[0][1]
                                        + rTable[(i+1)*(width+2)+j+1]*matrix[1][1]
                                        + rTable[(i+1)*(width+2)+j+2]*matrix[2][1]
                                        + rTable[(i+2)*(width+2)+j]*matrix[0][2]
                                        + rTable[(i+2)*(width+2)+j+1]*matrix[1][2]
                                        + rTable[(i+2)*(width+2)+j+2]*matrix[2][2];
                resultGTable[i*width+j] = gTable[i*(width+2)+j]*matrix[0][0]
                                        + gTable[i*(width+2)+j+1]*matrix[1][0]
                                        + gTable[i*(width+2)+j+2]*matrix[2][0]
                                        + gTable[(i+1)*(width+2)+j]*matrix[0][1]
                                        + gTable[(i+1)*(width+2)+j+1]*matrix[1][1]
                                        + gTable[(i+1)*(width+2)+j+2]*matrix[2][1]
                                        + gTable[(i+2)*(width+2)+j]*matrix[0][2]
                                        + gTable[(i+2)*(width+2)+j+1]*matrix[1][2]
                                        + gTable[(i+2)*(width+2)+j+2]*matrix[2][2];
                resultBTable[i*width+j] = bTable[i*(width+2)+j]*matrix[0][0]
                                        + bTable[i*(width+2)+j+1]*matrix[1][0]
                                        + bTable[i*(width+2)+j+2]*matrix[2][0]
                                        + bTable[(i+1)*(width+2)+j]*matrix[0][1]
                                        + bTable[(i+1)*(width+2)+j+1]*matrix[1][1]
                                        + bTable[(i+1)*(width+2)+j+2]*matrix[2][1]
                                        + bTable[(i+2)*(width+2)+j]*matrix[0][2]
                                        + bTable[(i+2)*(width+2)+j+1]*matrix[1][2]
                                        + bTable[(i+2)*(width+2)+j+2]*matrix[2][2];
                if(resultRTable[i*width+j]>255)
                    resultRTable[i*width+j] = 255;
                else if(resultRTable[i*width+j]<0)
                    resultRTable[i*width+j] = 0;
                if(resultGTable[i*width+j]>255)
                    resultGTable[i*width+j] = 255;
                else if(resultGTable[i*width+j]<0)
                    resultGTable[i*width+j] = 0;
                if(resultBTable[i*width+j]>255)
                    resultBTable[i*width+j] = 255;
                else if(resultBTable[i*width+j]<0)
                    resultBTable[i*width+j] = 0;
//                cout << resultRTable[i*width+j]<<" "<<resultGTable[i*width+j]<<" "<<resultBTable[i*width+j]<<endl;
            }
        }
//        cout << 1 << endl;
    }
}

void MainWindow::multiplyRGBTableN( int N, bool flag )
{
    resultRTable = new int[height*width];
    resultGTable = new int[height*width];
    resultBTable = new int[height*width];
    if(flag)
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                resultRTable[i*width+j] = 0;
                resultGTable[i*width+j] = 0;
                resultBTable[i*width+j] = 0;
                for(int p = 0; p < 2*N+1; p++)
                {
                    for(int q = 0; q < 2*N+1; q++)
                    {
                        resultRTable[i*width+j] = resultRTable[i*width+j] + rTable[(i+p)*(width+2*N)+j+q]*matrixTable[p*(2*N+1)+q];
                        resultGTable[i*width+j] = resultGTable[i*width+j] + gTable[(i+p)*(width+2*N)+j+q]*matrixTable[p*(2*N+1)+q];
                        resultBTable[i*width+j] = resultBTable[i*width+j] + bTable[(i+p)*(width+2*N)+j+q]*matrixTable[p*(2*N+1)+q];
                    }
                }
                if(resultRTable[i*width+j]>255)
                    resultRTable[i*width+j] = 255;
                else if(resultRTable[i*width+j]<0)
                    resultRTable[i*width+j] = 0;
                if(resultGTable[i*width+j]>255)
                    resultGTable[i*width+j] = 255;
                else if(resultGTable[i*width+j]<0)
                    resultGTable[i*width+j] = 0;
                if(resultBTable[i*width+j]>255)
                    resultBTable[i*width+j] = 255;
                else if(resultBTable[i*width+j]<0)
                    resultBTable[i*width+j] = 0;
//                cout << resultRTable[i*width+j]<<" "<<resultGTable[i*width+j]<<" "<<resultBTable[i*width+j]<<endl;
            }
        }
//        cout << 1 << endl;
    }
    else
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                resultRTable[i*width+j] = 0;
                resultGTable[i*width+j] = 0;
                resultBTable[i*width+j] = 0;
                for(int p = 0; p < 2*N+1; p++)
                {
                    for(int q = 0; q < 2*N+1; q++)
                    {
                        resultRTable[i*width+j] = resultRTable[i*width+j] + rTable[(i+p)*(width+2*N)+j+q]*matrixTable[q*(2*N+1)+p];
                        resultGTable[i*width+j] = resultGTable[i*width+j] + gTable[(i+p)*(width+2*N)+j+q]*matrixTable[q*(2*N+1)+p];
                        resultBTable[i*width+j] = resultBTable[i*width+j] + bTable[(i+p)*(width+2*N)+j+q]*matrixTable[q*(2*N+1)+p];
                    }
                }
                if(resultRTable[i*width+j]>255)
                    resultRTable[i*width+j] = 255;
                else if(resultRTable[i*width+j]<0)
                    resultRTable[i*width+j] = 0;
                if(resultGTable[i*width+j]>255)
                    resultGTable[i*width+j] = 255;
                else if(resultGTable[i*width+j]<0)
                    resultGTable[i*width+j] = 0;
                if(resultBTable[i*width+j]>255)
                    resultBTable[i*width+j] = 255;
                else if(resultBTable[i*width+j]<0)
                    resultBTable[i*width+j] = 0;
            }
        }
//        cout << 1 << endl;
    }
}

int MainWindow::maxGrayNumber(int element[], int pixel[])
{
    int max = -1;
    for(int i = 0; i < 25; i++)
    {
        if(element[i+2] != -1 && pixel[i]+element[i+2] > max )
            max = pixel[i]+element[i];
    }
    if(max > 255)
        return 255;
    else
        return max;
}

int MainWindow::minGrayNumber(int element[], int pixel[])
{
    int min = 256;
    for(int i = 0; i < 25; i++)
    {
        if(element[i+2] != -1 && abs(pixel[i]-element[i+2]) < min )
            min = abs(pixel[i]-element[i+2]);
    }
    if(min == 256)
        return -1;
    else
        return min;
}

int MainWindow::maxNumber(int element[], int pixel[])
{
    int max = -1;
    for(int i = 0; i < 25; i++)
    {
        if(element[i+2] == 1 && pixel[i] > max )
            max = pixel[i];
    }
    return max;
}

int MainWindow::minNumber(int element[], int pixel[])
{
    int min = 256;
    for(int i = 0; i < 25; i++)
    {
        if(element[i+2] == 1 && pixel[i] < min )
            min = pixel[i];
    }
    if(min == 256)
        return -1;
    else
        return min;
}

void MainWindow::getGrayDilation(int elements[], int N)
{
    resultGrayTable = new int[height*width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int elementsTable[25];
            for(int p = 0; p < 2*N+1; p++)
            {
                for(int q = 0; q < 2*N+1; q++)
                {
                    elementsTable[p*(2*N+1)+q] = grayTable[(i+p)*(width+2*N)+j+q];
                }
            }
            resultGrayTable[i*width+j] = maxGrayNumber(elements, elementsTable);
        }
    }
}

void MainWindow::getDilation(int elements[], int N)
{
    resultGrayTable = new int[height*width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int elementsTable[25];
            for(int p = 0; p < 2*N+1; p++)
            {
                for(int q = 0; q < 2*N+1; q++)
                {
                    elementsTable[p*(2*N+1)+q] = grayTable[(i+p)*(width+2*N)+j+q];
                }
            }
            resultGrayTable[i*width+j] = maxNumber(elements, elementsTable);
        }
    }
}

void MainWindow::getGrayErosion(int elements[], int N)
{
    resultGrayTable = new int[height*width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int elementsTable[25];
            for(int p = 0; p < 2*N+1; p++)
            {
                for(int q = 0; q < 2*N+1; q++)
                {
                    elementsTable[p*(2*N+1)+q] = grayTable[(i+p)*(width+2*N)+j+q];
                }
            }
            resultGrayTable[i*width+j] = minGrayNumber(elements, elementsTable);
        }
    }
//        cout << 1 << endl;
}

void MainWindow::getErosion(int elements[], int N)
{
    resultGrayTable = new int[height*width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int elementsTable[25];
            for(int p = 0; p < 2*N+1; p++)
            {
                for(int q = 0; q < 2*N+1; q++)
                {
                    elementsTable[p*(2*N+1)+q] = grayTable[(i+p)*(width+2*N)+j+q];
                }
            }
            resultGrayTable[i*width+j] = minNumber(elements, elementsTable);
        }
    }
//        cout << 1 << endl;
}

void MainWindow::paintOverGrayConvolution()
{
    ui->picture2->setGeometry(width>498?0:(498-width)/2,height>498?0:(498-height)/2,width,height);
    ui->newScrollArea->widget()->setMinimumSize(width>498?width:498,height>498?height:498);

    QImage gray(width,height,QImage::Format_Indexed8);
    QVector<QRgb> colorTable;
    for(int i = 0; i < 256; i++)
        colorTable.push_back(QColor(i,i,i).rgb());
    gray.setColorTable(colorTable);
    for (int i = 0; i < width;i++)
    {
        for(int j = 0; j < height;j++)
        {
            gray.setPixel(i,j,resultGrayTable[j*width+i]);
        }
    }

    ui->picture2->setPixmap(QPixmap::fromImage(gray));
    havePic2 = true;
//    cout << "nihao" << endl;
}

void MainWindow::paintOverRGBConvolution()
{
    ui->picture2->setGeometry(width>498?0:(498-width)/2,height>498?0:(498-height)/2,width,height);
    ui->newScrollArea->widget()->setMinimumSize(width>498?width:498,height>498?height:498);

    QImage newPic(width,height,QImage::Format_ARGB32);
    for (int i = 0; i < width;i++)
    {
        for(int j = 0; j < height;j++)
        {
//            cout << resultRTable[j*width+i] << " " <<resultGTable[j*width+i]<<" "<<resultBTable[j*width+i]<<endl;
            QRgb pixel = qRgb(resultRTable[j*width+i],resultGTable[j*width+i],resultBTable[j*width+i]);
//            cout << qRed(pixel);
//            QRgb pixel = qRgb(rTable[(j+1)*(width+2)+i+1],gTable[(j+1)*(width+2)+(i+1)],bTable[(j+1)*(width+2)+(i+1)]);
            newPic.setPixel(i,j,pixel);
        }
    }
    ui->picture2->setPixmap(QPixmap::fromImage(newPic));
    havePic2 = true;
//    cout << "nihao" << endl;
}

void MainWindow::on_actionMedian_filter_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    getRGBTable();
    makeMedianTable();
    paintOverRGBConvolution();
}

void MainWindow::makeMedianTable()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    resultRTable = new int[height*width];
    resultGTable = new int[height*width];
    resultBTable = new int[height*width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            resultRTable[i*width+j] = medianValue(rTable[i*(width+2)+j],
                                                  rTable[i*(width+2)+j+1],
                                                  rTable[i*(width+2)+j+2],
                                                  rTable[(i+1)*(width+2)+j],
                                                  rTable[(i+1)*(width+2)+j+1],
                                                  rTable[(i+1)*(width+2)+j+2],
                                                  rTable[(i+2)*(width+2)+j],
                                                  rTable[(i+2)*(width+2)+j+1],
                                                  rTable[(i+2)*(width+2)+j+2]);
            resultGTable[i*width+j] = medianValue(gTable[i*(width+2)+j],
                                                  gTable[i*(width+2)+j+1],
                                                  gTable[i*(width+2)+j+2],
                                                  gTable[(i+1)*(width+2)+j],
                                                  gTable[(i+1)*(width+2)+j+1],
                                                  gTable[(i+1)*(width+2)+j+2],
                                                  gTable[(i+2)*(width+2)+j],
                                                  gTable[(i+2)*(width+2)+j+1],
                                                  gTable[(i+2)*(width+2)+j+2]);
            resultBTable[i*width+j] = medianValue(bTable[i*(width+2)+j],
                                                  bTable[i*(width+2)+j+1],
                                                  bTable[i*(width+2)+j+2],
                                                  bTable[(i+1)*(width+2)+j],
                                                  bTable[(i+1)*(width+2)+j+1],
                                                  bTable[(i+1)*(width+2)+j+2],
                                                  bTable[(i+2)*(width+2)+j],
                                                  bTable[(i+2)*(width+2)+j+1],
                                                  bTable[(i+2)*(width+2)+j+2]);
//          cout << resultRTable[i*width+j]<<" "<<resultGTable[i*width+j]<<" "<<resultBTable[i*width+j]<<endl;
        }
    }
//  cout << 1 << endl;

}

double MainWindow::medianValue(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3)
{
    double array[9];
    array[0] = a1;
    array[1] = a2;
    array[2] = a3;
    array[3] = b1;
    array[4] = b2;
    array[5] = b3;
    array[6] = c1;
    array[7] = c2;
    array[8] = c3;
    for(int i = 0; i < 9; i++)
    {
        int temp = i;
        int result = 0;
        for(int j = i; j < 9; j++)
        {
            if(array[j]>result)
            {
                result = array[j];
                temp = j;
            }
        }
        int arrayTemp = array[i];
        array[i] = array[temp];
        array[temp] = arrayTemp;
    }
//    cout << array[4] << endl;
    return array[4];
}

void MainWindow::on_matrixBySelf_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    matrixDialog matrixs;
    connect(&matrixs, SIGNAL(matrixConfirm(double,double,double,double,double,double,double,double,double)), this, SLOT(matrixConfirm(double,double,double,double,double,double,double,double,double)));
    matrixs.exec();
}

void MainWindow::matrixConfirm(double a1,double a2,double a3,double b1,double b2,double b3,double c1,double c2,double c3)
{
    setMatrix(a1,a2,a3,b1,b2,b3,c1,c2,c3);
    getRGBTable();
    multiplyRGBTable(true);
//    multiplyRGBTable(false);
    paintOverRGBConvolution();
}

void MainWindow::on_actionMean_filter_triggered()
{
    if(!havePic1)
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    double mean = 1.0/9.0;
    setMatrix(mean,mean,mean,mean,mean,mean,mean,mean,mean);
    getRGBTable();
    multiplyRGBTable(true);
//    multiplyRGBTable(false);
    paintOverRGBConvolution();
}

void MainWindow::on_newPicture_triggered()
{
    newPicDialog newThePic;
    connect(&newThePic, SIGNAL(newPicConfirm(int,int)), this, SLOT(newPicConfirm(int,int)));
    newThePic.exec();
}

void MainWindow::on_action_add_triggered()
{
    if(!(havePic1&&havePic2))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    QPixmap pixmap1 (*ui->picture1->pixmap());
    QPixmap pixmap2 (*ui->picture2->pixmap());
    int newWidth = max(pixmap1.width(),pixmap2.width());
    int newHeight = max(pixmap1.height(),pixmap2.height());
    ui->picture2->setGeometry(newWidth>498?0:(498-newWidth)/2,newHeight>498?0:(498-newHeight)/2,newWidth,newHeight);
    ui->newScrollArea->widget()->setMinimumSize(newWidth>498?newWidth:498,newHeight>498?newHeight:498);

    QImage image(newWidth,newHeight,QImage::Format_ARGB32);
    QImage image1 = pixmap1.toImage();
    QImage image2 = pixmap2.toImage();
    for (int i = 0; i < newWidth;i++)
    {
        for(int j = 0; j < newHeight;j++)
        {
            QRgb pixel1;
            QRgb pixel2;
            if(i>=image1.width()||j>=image1.height())
                pixel1 = qRgb(0,0,0);
            else
                pixel1 = image1.pixel(i,j);
            if(i>=image2.width()||j>=image2.height())
                pixel2 = qRgb(0,0,0);
            else
                pixel2 = image2.pixel(i,j);
            int r;
            int g;
            int b;
            if(qRed(pixel1)+qRed(pixel2)>255)
                r = 255;
            else
                r = qRed(pixel1)+qRed(pixel2);
            if(qGreen(pixel1)+qGreen(pixel2)>255)
                g = 255;
            else
                g = qGreen(pixel1)+qGreen(pixel2);
            if(qBlue(pixel1)+qBlue(pixel2)>255)
                b = 255;
            else
                b = qBlue(pixel1)+qBlue(pixel2);
            QRgb pixel = qRgb(r,g,b);
            image.setPixel(i,j,pixel);
        }
    }
    ui->picture2->setPixmap(QPixmap::fromImage(image));
    havePic2 = true;
}

void MainWindow::on_action_minus_triggered()
{
    if(!(havePic1&&havePic2))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    QPixmap pixmap1 (*ui->picture1->pixmap());
    QPixmap pixmap2 (*ui->picture2->pixmap());
    int newWidth = max(pixmap1.width(),pixmap2.width());
    int newHeight = max(pixmap1.height(),pixmap2.height());
    ui->picture2->setGeometry(newWidth>498?0:(498-newWidth)/2,newHeight>498?0:(498-newHeight)/2,newWidth,newHeight);
    ui->newScrollArea->widget()->setMinimumSize(newWidth>498?newWidth:498,newHeight>498?newHeight:498);

    QImage image(newWidth,newHeight,QImage::Format_ARGB32);
    QImage image1 = pixmap1.toImage();
    QImage image2 = pixmap2.toImage();
    for (int i = 0; i < newWidth;i++)
    {
        for(int j = 0; j < newHeight;j++)
        {
            QRgb pixel1;
            QRgb pixel2;
            if(i>=image1.width()||j>=image1.height())
                pixel1 = qRgb(0,0,0);
            else
                pixel1 = image1.pixel(i,j);
            if(i>=image2.width()||j>=image2.height())
                pixel2 = qRgb(0,0,0);
            else
                pixel2 = image2.pixel(i,j);
            int r;
            int g;
            int b;
            if(qRed(pixel1)-qRed(pixel2)<0)
                r = 255;
            else
                r = qRed(pixel1)-qRed(pixel2);
            if(qGreen(pixel1)-qGreen(pixel2)<0)
                g = 255;
            else
                g = qGreen(pixel1)-qGreen(pixel2);
            if(qBlue(pixel1)-qBlue(pixel2)<0)
                b = 255;
            else
                b = qBlue(pixel1)-qBlue(pixel2);
            QRgb pixel = qRgb(r,g,b);
            image.setPixel(i,j,pixel);
        }
    }
    ui->picture2->setPixmap(QPixmap::fromImage(image));
    havePic2 = true;
}

void MainWindow::on_action_multiply_triggered()
{
    if(!(havePic1&&havePic2))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    QPixmap pixmap1 (*ui->picture1->pixmap());
    QPixmap pixmap2 (*ui->picture2->pixmap());
    int newWidth = max(pixmap1.width(),pixmap2.width());
    int newHeight = max(pixmap1.height(),pixmap2.height());
    ui->picture2->setGeometry(newWidth>498?0:(498-newWidth)/2,newHeight>498?0:(498-newHeight)/2,newWidth,newHeight);
    ui->newScrollArea->widget()->setMinimumSize(newWidth>498?newWidth:498,newHeight>498?newHeight:498);

    QImage image(newWidth,newHeight,QImage::Format_ARGB32);
    QImage image1 = pixmap1.toImage();
    QImage image2 = pixmap2.toImage();
    for (int i = 0; i < newWidth;i++)
    {
        for(int j = 0; j < newHeight;j++)
        {
            QRgb pixel1;
            QRgb pixel2;
            if(i>=image1.width()||j>=image1.height())
                pixel1 = qRgb(0,0,0);
            else
                pixel1 = image1.pixel(i,j);
            if(i>=image2.width()||j>=image2.height())
                pixel2 = qRgb(0,0,0);
            else
                pixel2 = image2.pixel(i,j);
            QRgb pixel = qRgb(sqrt(double(qRed(pixel1)*qRed(pixel2))),sqrt(double(qGreen(pixel1)*qGreen(pixel2))),sqrt(double(qBlue(pixel1)*qBlue(pixel2))));
            image.setPixel(i,j,pixel);
        }
    }
    ui->picture2->setPixmap(QPixmap::fromImage(image));
    havePic2 = true;
}

void MainWindow::on_action_openPicture2_triggered()
{
    QString File_Name =
    QFileDialog::getOpenFileName(this,tr("打开文件"),"", tr("JPG(*.jpg);;BMP(*.bmp);;GIF(*.gif);;ALL files(*.*)"));
    if(File_Name!="")
    {
        QImage image(File_Name);
        QPixmap pixmap = QPixmap::fromImage(image);
        ui->picture2->setGeometry(pixmap.width()>498?0:(498-pixmap.width())/2,pixmap.height()>498?0:(498-pixmap.height())/2,pixmap.width(),pixmap.height());
        ui->picture2->setPixmap(pixmap);
        ui->newScrollArea->widget()->setMinimumSize(pixmap.width()>498?pixmap.width():498,pixmap.height()>498?pixmap.height():498);
        havePic2 = true;
    }
}

void MainWindow::on_action_vertex_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    vertexDialog vertexs;
    connect(&vertexs, SIGNAL(vertexConfirm(int,int,int,int,int,int,int)), this, SLOT(vertexConfirm(int,int,int,int,int,int,int)));
    vertexs.exec();
}

void MainWindow::vertexConfirm(int x1,int x2,int y1,int y2,int r,int g,int b)
{
    if(x1>x2)
    {
        QMessageBox::information(this, "", tr("Set Width Wrongly"));
        return;
    }
    if(y1>y2)
    {
        QMessageBox::information(this, "", tr("Set Height Wrongly"));
        return;
    }
    QPixmap pixmap (*ui->picture1->pixmap());
    ui->picture2->setGeometry(pixmap.width()>498?0:(498-pixmap.width())/2,pixmap.height()>498?0:(498-pixmap.height())/2,pixmap.width(),pixmap.height());
    ui->newScrollArea->widget()->setMinimumSize(pixmap.width()>498?pixmap.width():498,pixmap.height()>498?pixmap.height():498);

    QImage image;
    image = pixmap.toImage();
    for (int i = x1; i <= x2;i++)
    {
        for(int j = y1; j < y2;j++)
        {
            QRgb pixel = qRgb(r,g,b);
            image.setPixel(i,j,pixel);
        }
    }
    ui->picture2->setPixmap(QPixmap::fromImage(image));
    havePic2 = true;
}

void MainWindow::on_actionGaussian_filter_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    gaussCoreDialog gauss;
    connect(&gauss, SIGNAL(gaussConfirm(double,int)), this, SLOT(gaussConfirm(double,int)));
    gauss.exec();
}

void MainWindow::gaussConfirm(double x, int N)
{
    float m_b2 = x;
    float *Ftemp = new float[(2 * N + 1)*(2 * N + 1)];
    float *Itemp = new float[(2 * N + 1)*(2 * N + 1)];
    for(int i=0;i<N+1;i++)               //取模板大小(2N+1) (2N+1)的右下角部分
    {    for(int j=0;j<N+1;j++)
        {
            float t=(float)(i*i+j*j)/m_b2;        // m_b2表示平滑尺度
            Ftemp[i*(N+1)+j]=(float)(1.0/exp(t/2));
        }
    }
    int C=(int)ceil(1/Ftemp[(N+1)*(N+1)-1]+0.5);     //计算归一化系数
    for(int i=0;i<N+1;i++)    //给模板右下角付值
    {
        for(int j=0;j<N+1;j++)
        {
            Itemp[(N+i)*(2*N+1)+(N+j)] =int(Ftemp[i*(N+1)+j]*C+0.5);
        }
    }
    for(int i=N;i<2*N+1;i++)                         //给模板左下角付值
    {
        for(int j=0;j<N+1;j++)
        {
            Itemp[i*(2*N+1)+j] =Itemp[i*(2*N+1)+(2*N-j)];
        }
    }
    for(int i=0;i<N;i++)                                 //给模板上半部分付值
    {
        for(int j=0;j<2*N+1;j++)
        {
            Itemp[i*(2*N+1)+j] =Itemp[(2*N-i)*(2*N+1)+j];
        }
    }
/*
    for(int i=0;i<2*N+1;i++)               //计算总的系数
    {
        for(j=0;j<2*N+1;j++)
        {
            Cof +=(float )Itemp[i*(2*N+1)+j];
        }
    }
    Cof=(float)( 1.0/Cof);
*/
    matrixTable = new double[(2*N+1)*(2*N+1)];
    double total = 0;
    for( int i = 0; i < 2*N+1; i++ )
    {
        for(int j = 0; j < 2*N+1;j++)
        {
            matrixTable[i*(2*N+1)+j] = Itemp[i*3+j];
            total = total + matrixTable[i*(2*N+1)+j];
        }
    }
    for( int i = 0; i < 2*N+1; i++ )
    {
        for(int j = 0; j < 2*N+1;j++)
            matrixTable[i*(2*N+1)+j] = matrixTable[i*(2*N+1)+j]/total;
    }
    delete[] Ftemp;
    delete[] Itemp;

    getRGBTableN(N);
    multiplyRGBTableN(N,true);
//    multiplyRGBTable(false);
    paintOverRGBConvolution();
}

void MainWindow::on_makeDone_clicked()
{
    if(!(havePic2))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    QPixmap pixmap (*ui->picture2->pixmap());
    ui->picture1->setGeometry(pixmap.width()>498?0:(498-pixmap.width())/2,pixmap.height()>498?0:(498-pixmap.height())/2,pixmap.width(),pixmap.height());
//    cout << pixmap.width() << " " << pixmap.height() << endl;
    ui->oldScrollArea->widget()->setMinimumSize(pixmap.width()>498?pixmap.width():498,pixmap.height()>498?pixmap.height():498);
    ui->picture1->setPixmap(pixmap);
}

void MainWindow::newPicConfirm(int x, int y)
{
//    cout << x << " " << y << endl;
    ui->picture1->setGeometry(x>498?0:(498-x)/2,y>498?0:(498-y)/2,x,y);
//    ui->picture1->setMinimumSize(x,y);
//    cout << pixmap.width() << " " << pixmap.height() << endl;
    ui->oldScrollArea->widget()->setMinimumSize(x>498?x:498,y>498?y:498);
//    cout << ui->oldScrollArea->widget()->minimumWidth() << " " << ui->oldScrollArea->widget()->minimumHeight() << endl;

    QImage newPic(x,y,QImage::Format_Indexed8);
    QVector<QRgb> colorTable;
    colorTable.push_back(QColor(255,255,255).rgb());
    newPic.setColorTable(colorTable);
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
            newPic.setPixel(i,j,0);
    }
    ui->picture1->setPixmap(QPixmap::fromImage(newPic));
}

void MainWindow::on_actionTest_triggered()
{
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    timer->start(10);
}

void MainWindow::timerUpDate()
{
    QPixmap pixmap (*ui->picture1->pixmap());
    QImage image = pixmap.toImage();
    QPainter painter(&image);
    painter.setBrush(QColor(0,0,0));
    painter.drawEllipse(QPoint(50+testTime,50),10,10);
//        painter.drawLine(0,0,200,200);
    painter.end();
    pixmap = QPixmap::fromImage(image);
    ui->picture1->setPixmap(pixmap);
    testTime++;
}

void MainWindow::on_clockwise_triggered()
{
    QPixmap oldPixmap(*ui->picture1->pixmap());
    QImage oldPic = oldPixmap.toImage();
    QImage newPic(oldPixmap.height(),oldPixmap.width(),QImage::Format_ARGB32);
    for(int i = 0; i < oldPixmap.width(); i++)
    {
        for(int j = 0; j < oldPixmap.height(); j++)
        {
            QRgb pixel = oldPic.pixel(i,j);
            newPic.setPixel(oldPic.height()-j-1,i,pixel);
        }
    }
    ui->picture2->setGeometry(oldPixmap.height()>498?0:(498-oldPixmap.height())/2,oldPixmap.width()>498?0:(498-oldPixmap.width())/2,oldPixmap.height(),oldPixmap.width());
    ui->newScrollArea->widget()->setMinimumSize(oldPixmap.height()>498?oldPixmap.height():498,oldPixmap.width()>498?oldPixmap.width():498);
    ui->picture2->setPixmap(QPixmap::fromImage(newPic));
    havePic2 = true;
}

void MainWindow::on_anticlockwise_triggered()
{
    QPixmap oldPixmap(*ui->picture1->pixmap());
    QImage oldPic = oldPixmap.toImage();
    QImage newPic(oldPixmap.height(),oldPixmap.width(),QImage::Format_ARGB32);
    for(int i = 0; i < oldPixmap.width(); i++)
    {
        for(int j = 0; j < oldPixmap.height(); j++)
        {
            QRgb pixel = oldPic.pixel(i,j);
            newPic.setPixel(j,oldPic.width()-i-1,pixel);
        }
    }
    ui->picture2->setGeometry(oldPixmap.height()>498?0:(498-oldPixmap.height())/2,oldPixmap.width()>498?0:(498-oldPixmap.width())/2,oldPixmap.height(),oldPixmap.width());
    ui->newScrollArea->widget()->setMinimumSize(oldPixmap.height()>498?oldPixmap.height():498,oldPixmap.width()>498?oldPixmap.width():498);
    ui->picture2->setPixmap(QPixmap::fromImage(newPic));
    havePic2 = true;
}

void MainWindow::grayDilationConfirm(int elements[])
{
    getGrayPicture(2);
    getGrayTableN(2);
    getGrayDilation(elements, 2);
    paintOverGrayConvolution();
    havePic2 = true;
}

void MainWindow::grayErosionConfirm(int elements[])
{
    getGrayPicture(2);
    getGrayTableN(2);
    getGrayErosion(elements, 2);
    paintOverGrayConvolution();
    havePic2 = true;
}

void MainWindow::grayOpenConfirm(int elements[])
{
    getGrayPicture(2);
    getGrayTableN(2);
    getGrayErosion(elements, 2);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            grayTable[(i+2)*(width+4)+j+2] = resultGrayTable[i*width+j];
    }
    getGrayTableN(2);
    getGrayDilation(elements, 2);
    paintOverGrayConvolution();
    havePic2 = true;
}

void MainWindow::grayCloseConfirm(int elements[])
{
    getGrayPicture(2);
    getGrayTableN(2);
    getGrayDilation(elements, 2);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            grayTable[(i+2)*(width+4)+j+2] = resultGrayTable[i*width+j];
    }
    getGrayTableN(2);
    getGrayErosion(elements, 2);
    paintOverGrayConvolution();
    havePic2 = true;
}

void MainWindow::binaryDilationConfirm(int elements[])
{
    getGrayPicture(2);
    getGrayTableN(2);
    getDilation(elements, 2);
    paintOverGrayConvolution();
    havePic2 = true;
}

void MainWindow::binaryErosionConfirm(int elements[])
{
    getGrayPicture(2);
    getGrayTableN(2);
    getErosion(elements, 2);
    paintOverGrayConvolution();
    havePic2 = true;
}

void MainWindow::binaryOpenConfirm(int elements[])
{
    getGrayPicture(2);
    getGrayTableN(2);
    getErosion(elements, 2);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            grayTable[(i+2)*(width+4)+j+2] = resultGrayTable[i*width+j];
    }
    getGrayTableN(2);
    getDilation(elements, 2);
    paintOverGrayConvolution();
    havePic2 = true;
}

void MainWindow::binaryCloseConfirm(int elements[])
{
    getGrayPicture(2);
    getGrayTableN(2);
    getDilation(elements, 2);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            grayTable[(i+2)*(width+4)+j+2] = resultGrayTable[i*width+j];
    }
    getGrayTableN(2);
    getErosion(elements, 2);
    paintOverGrayConvolution();
    havePic2 = true;
}

void MainWindow::on_grayDilation_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    grayElementDialog grayEleMent;
    connect(&grayEleMent, SIGNAL(elementConfirm(int[])), this, SLOT(grayDilationConfirm(int[])));
    grayEleMent.exec();
}

void MainWindow::on_binaryDilation_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    elementDialog eleMent;
    connect(&eleMent, SIGNAL(elementConfirm(int[])), this, SLOT(binaryDilationConfirm(int[])));
    eleMent.exec();
}

void MainWindow::on_grayErosion_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    grayElementDialog grayEleMent;
    connect(&grayEleMent, SIGNAL(elementConfirm(int[])), this, SLOT(grayErosionConfirm(int[])));
    grayEleMent.exec();
}

void MainWindow::on_binaryErosion_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    elementDialog eleMent;
    connect(&eleMent, SIGNAL(elementConfirm(int[])), this, SLOT(binaryErosionConfirm(int[])));
    eleMent.exec();
}

void MainWindow::on_grayOpen_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    grayElementDialog grayEleMent;
    connect(&grayEleMent, SIGNAL(elementConfirm(int[])), this, SLOT(grayOpenConfirm(int[])));
    grayEleMent.exec();
}

void MainWindow::on_binaryOpen_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    elementDialog eleMent;
    connect(&eleMent, SIGNAL(elementConfirm(int[])), this, SLOT(binaryOpenConfirm(int[])));
    eleMent.exec();
}

void MainWindow::on_grayClose_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    grayElementDialog grayEleMent;
    connect(&grayEleMent, SIGNAL(elementConfirm(int[])), this, SLOT(grayCloseConfirm(int[])));
    grayEleMent.exec();
}

void MainWindow::on_binaryClose_triggered()
{
    if(!(havePic1))
    {
        QMessageBox::information(this, "", "Haven't import the picture");
        return;
    }
    elementDialog eleMent;
    connect(&eleMent, SIGNAL(elementConfirm(int[])), this, SLOT(binaryCloseConfirm(int[])));
    eleMent.exec();
}
