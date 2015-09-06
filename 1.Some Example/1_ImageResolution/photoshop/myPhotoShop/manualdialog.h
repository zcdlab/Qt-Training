#ifndef MANUALDIALOG_H
#define MANUALDIALOG_H

#include <QDialog>

namespace Ui {
class manualDialog;
}

class manualDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit manualDialog(QWidget *parent = 0);
    ~manualDialog();
    
private slots:

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::manualDialog *ui;
};

#endif // MANUALDIALOG_H
