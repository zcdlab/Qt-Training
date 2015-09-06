#ifndef MATRIXDIALOG_H
#define MATRIXDIALOG_H

#include <QDialog>

namespace Ui {
class matrixDialog;
}

class matrixDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit matrixDialog(QWidget *parent = 0);
    ~matrixDialog();
    
private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::matrixDialog *ui;

signals:
    void matrixConfirm(double a1,double a2,double a3,double b1,double b2,double b3,double c1,double c2,double c3);
};

#endif // MATRIXDIALOG_H
