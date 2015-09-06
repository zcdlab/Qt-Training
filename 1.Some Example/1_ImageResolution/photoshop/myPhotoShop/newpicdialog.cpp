#include "newpicdialog.h"
#include "ui_newpicdialog.h"

newPicDialog::newPicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newPicDialog)
{
    ui->setupUi(this);
}

newPicDialog::~newPicDialog()
{
    delete ui;
}

void newPicDialog::on_okButton_clicked()
{
    emit newPicConfirm(ui->width->value(),ui->height->value());
    accept();
}

void newPicDialog::on_cancelButton_clicked()
{
    reject();
}
