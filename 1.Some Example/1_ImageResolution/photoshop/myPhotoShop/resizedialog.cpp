#include "resizedialog.h"
#include "ui_resizedialog.h"

reSizeDialog::reSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reSizeDialog)
{
    ui->setupUi(this);
}

reSizeDialog::~reSizeDialog()
{
    delete ui;
}

void reSizeDialog::on_okButton_clicked()
{
    emit resizeConfirm(ui->xSpinBox->value(), ui->ySpinBox->value(),ui->radioButton->isChecked(),ui->radioButton_2->isChecked(),ui->radioButton_3->isChecked());
    accept();
}

void reSizeDialog::on_cancelButton_clicked()
{
    reject();
}
