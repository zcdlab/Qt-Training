#include "gausscoredialog.h"
#include "ui_gausscoredialog.h"

gaussCoreDialog::gaussCoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gaussCoreDialog)
{
    ui->setupUi(this);
}

gaussCoreDialog::~gaussCoreDialog()
{
    delete ui;
}

void gaussCoreDialog::on_okButton_clicked()
{
     emit gaussConfirm(ui->a->value(), ui->N->value());
     accept();
}

void gaussCoreDialog::on_cancelButton_clicked()
{
    reject();
}
