#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QLabel *Radius_label,*Area_label;
    QLineEdit *Radius_lineEdit;
    QPushButton *Calc_pushButton;


private slots:
    void showArea();


};

#endif // DIALOG_H
