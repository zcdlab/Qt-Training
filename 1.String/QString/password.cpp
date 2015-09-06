#include "password.h"
#include "ui_password.h"

password::password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
}

password::~password()
{
    delete ui;
}

void password::on_pushButton_passWord_clicked()
{
    passWord=ui->lineEdit_firstPassword->text();

    this->close();
}
