#ifndef ELEMENTDIALOG_H
#define ELEMENTDIALOG_H

#include <QDialog>

namespace Ui {
class elementDialog;
}

class elementDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit elementDialog(QWidget *parent = 0);
    ~elementDialog();
    
private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::elementDialog *ui;

signals:
    void elementConfirm(int elements[]);
};

#endif // ELEMENTDIALOG_H
