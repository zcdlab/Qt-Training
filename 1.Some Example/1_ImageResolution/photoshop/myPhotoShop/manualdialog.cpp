#include "manualdialog.h"
#include "ui_manualdialog.h"

manualDialog::manualDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manualDialog)
{
    ui->setupUi(this);
}

manualDialog::~manualDialog()
{
    delete ui;
}
void manualDialog::on_okButton_clicked()
{
    done(ui->spinBox->value());
}

void manualDialog::on_cancelButton_clicked()
{
    done(-1);
}
