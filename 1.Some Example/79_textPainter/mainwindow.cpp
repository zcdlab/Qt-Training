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

    painter.drawText(100,100,"helloworld");

    QRect rec(100,100,200,200);
    painter.drawRect(rec);
    painter.drawText(rec,Qt::AlignLeft|Qt::AlignVCenter,"Left");
    painter.drawText(rec,Qt::AlignCenter,"Center");
    painter.drawText(rec,Qt::AlignRight|Qt::AlignVCenter,"Right");


    QRect rec2(400,100,200,200);
    painter.drawRect(rec2);
    painter.drawText(rec2,"this will be clipped");

    QTextDocument doc;
    QRect rec3(0,0,250,250);
    painter.translate(20,20);
    doc.setTextWidth(rec3.width());

    doc.setHtml("<b><u>Hello</u></b> <br><br> <font face='Arial' color='red' size='6'> <i>World</i></font>");
    doc.drawContents(&painter,rec3);


}
