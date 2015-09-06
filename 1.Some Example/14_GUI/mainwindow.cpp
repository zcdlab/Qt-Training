#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i=0;i<9;i++)
    {
    ui->listWidget->addItem(QString::number(i)+"   Item here");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->currentItem()->setText("Fuzzy Bunny");
    QListWidgetItem *item= ui->listWidget->currentItem();
    item->setText("Fuzzy bunnys of doom");
    item->setTextColor(Qt::red);
}
