#ifndef GRAYELEMENTDIALOG_H
#define GRAYELEMENTDIALOG_H

#include <QDialog>

namespace Ui {
class grayElementDialog;
}

class grayElementDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit grayElementDialog(QWidget *parent = 0);
    ~grayElementDialog();
    
private:
    Ui::grayElementDialog *ui;

signals:
    void elementConfirm(int elements[]);
private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
};

#endif // GRAYELEMENTDIALOG_H
