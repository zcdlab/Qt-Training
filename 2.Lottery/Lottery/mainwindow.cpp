#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

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

void MainWindow::on_pushButton_Roll_Up_clicked()
{
    /*随机选择一个
    int index=(qrand()%(ui->listWidget->count()));
    ui->lineEdit_winner->setText(ui->listWidget->item(index)->text());
    */
    /*随机选择多个*/

    int WinnerNum=0;
    WinnerNum=ui->lineEdit_Num->text().toInt();
    if(WinnerNum!=0)
    {
    int compare[ui->listWidget->count()-1];
    int num=(qrand()%(ui->listWidget->count()));
    int index;
    int Selected=0;
    QString show;

    for(int count=0;count<num;count++)
    {
        compare[count]=count+1;
    }


    for(int count=0;1;count++)
    {
        index=(qrand()%(ui->listWidget->count()));
        if(compare[index]!=0)
        {
        compare[index]=0;
        show.append(ui->listWidget->item(index)->text());
        Selected++;
            if(Selected>=WinnerNum)
            {
                break;
            }
            else
            {
            show.append(" 、 ");
            }
        }
    }
    ui->lineEdit_winner->setText(show);
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("Please check the number of Winner!"));
    }
}
