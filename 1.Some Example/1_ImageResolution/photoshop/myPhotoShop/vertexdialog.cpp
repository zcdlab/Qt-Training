#include "vertexdialog.h"
#include "ui_vertexdialog.h"

vertexDialog::vertexDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vertexDialog)
{
    ui->setupUi(this);
}

vertexDialog::~vertexDialog()
{
    delete ui;
}

void vertexDialog::on_okButton_clicked()
{
    emit vertexConfirm(ui->x1->value(),ui->x2->value(),ui->y1->value(),ui->y2->value(),ui->r->value(),ui->g->value(),ui->b->value());
    accept();
}

void vertexDialog::on_cancelButton_clicked()
{
    reject();
}
