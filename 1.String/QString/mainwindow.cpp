#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include "password.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QString>
#include <QClipboard>

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

void MainWindow::on_pushButton_sure_clicked()
{
    QString str1=ui->textEdit_editer->toPlainText();
    QString str2=ui->lineEdit_password->text();


    mainPassword=uiPassword->passWord;
    qDebug()<<mainPassword;
    if(mainPassword.isEmpty())
    {
        uiPassword->show();

    }
    else if(str2==mainPassword)
    {
        QMessageBox::about(this, tr("Warning"),tr("Right password"));
        //ui->textEdit_editer->clear();
        //ui->textEdit_editer->setText("Right password and dosomething!");


        /*QString to Char* 的方法*/
        QByteArray ba = str1.toLatin1();
        char* cstr=(char*)malloc(ba.length()+1);
        memset(cstr,0,ba.length());
        memcpy(cstr,ba.data(),ba.length());
        cstr[ba.length()]='\0';
        for(int i=0;i<ba.length();i++)
        {
            cstr[i]=cstr[i]-5-i;
        }
        cstr[ba.length()]='\0';
        QString str1(cstr);
        ui->textEdit_editer->setText(str1);
    }
    else
    {
        QMessageBox::about(this, tr("Warning"),tr("Wrong password"));
        //ui->textEdit_editer->clear();
        ui->textEdit_editer->setText("Wrong password and check the application output to check the password!");
    }
}

void MainWindow::on_pushButton_Encrypt_clicked()
{
    QString str1=ui->textEdit_editer->toPlainText();
    QByteArray ba = str1.toLatin1();
    char* cstr=(char*)malloc(ba.length()+1);
    memset(cstr,0,ba.length());
    memcpy(cstr,ba.data(),ba.length());
    cstr[ba.length()]='\0';
    for(int i=0;i<ba.length();i++)
    {
        cstr[i]=cstr[i]+5+i;
    }
    cstr[ba.length()]='\0';
    QString str3(cstr);
    ui->textEdit_editer->setText(str3);
}

void MainWindow::on_pushButton_copy_clicked()
{
    QClipboard *cb =QApplication::clipboard();
    cb->setText(ui->textEdit_editer->toPlainText());
}
