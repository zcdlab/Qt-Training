#include "matrixdialog.h"
#include "ui_matrixdialog.h"

matrixDialog::matrixDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrixDialog)
{
    ui->setupUi(this);
}

matrixDialog::~matrixDialog()
{
    delete ui;
}

void matrixDialog::on_okButton_clicked()
{
    emit matrixConfirm(ui->a1->value(),ui->a2->value(),ui->a3->value(),ui->b1->value(),ui->b2->value(),ui->b3->value(),ui->c1->value(),ui->c2->value(),ui->c3->value());
    accept();
}

void matrixDialog::on_cancelButton_clicked()
{
    reject();
}
