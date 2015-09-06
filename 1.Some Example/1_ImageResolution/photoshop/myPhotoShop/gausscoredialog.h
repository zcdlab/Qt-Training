#ifndef GAUSSCOREDIALOG_H
#define GAUSSCOREDIALOG_H

#include <QDialog>

namespace Ui {
class gaussCoreDialog;
}

class gaussCoreDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit gaussCoreDialog(QWidget *parent = 0);
    ~gaussCoreDialog();
    
private:
    Ui::gaussCoreDialog *ui;
signals:
    void gaussConfirm(double x, int n);
private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
};

#endif // GAUSSCOREDIALOG_H
