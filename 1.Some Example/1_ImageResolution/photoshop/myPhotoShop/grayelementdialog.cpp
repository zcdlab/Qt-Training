#include "grayelementdialog.h"
#include "ui_grayelementdialog.h"

grayElementDialog::grayElementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::grayElementDialog)
{
    ui->setupUi(this);
}

grayElementDialog::~grayElementDialog()
{
    delete ui;
}

void grayElementDialog::on_okButton_clicked()
{
    int theElements[25];
    theElements[0] = ui->spinBox->value();
    theElements[1] = ui->spinBox_2->value();
    theElements[2] = ui->spinBox_3->value();
    theElements[3] = ui->spinBox_4->value();
    theElements[4] = ui->spinBox_5->value();
    theElements[5] = ui->spinBox_6->value();
    theElements[6] = ui->spinBox_7->value();
    theElements[7] = ui->spinBox_8->value();
    theElements[8] = ui->spinBox_9->value();
    theElements[9] = ui->spinBox_10->value();
    theElements[10] = ui->spinBox_11->value();
    theElements[11] = ui->spinBox_12->value();
    theElements[12] = ui->spinBox_13->value();
    theElements[13] = ui->spinBox_14->value();
    theElements[14] = ui->spinBox_15->value();
    theElements[15] = ui->spinBox_16->value();
    theElements[16] = ui->spinBox_17->value();
    theElements[17] = ui->spinBox_18->value();
    theElements[18] = ui->spinBox_19->value();
    theElements[19] = ui->spinBox_20->value();
    theElements[20] = ui->spinBox_21->value();
    theElements[21] = ui->spinBox_22->value();
    theElements[22] = ui->spinBox_23->value();
    theElements[23] = ui->spinBox_24->value();
    theElements[24] = ui->spinBox_25->value();
    emit elementConfirm(theElements);
    accept();
}

void grayElementDialog::on_cancelButton_clicked()
{
    reject();
}
