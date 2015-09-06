#ifndef NEWPICDIALOG_H
#define NEWPICDIALOG_H

#include <QDialog>

namespace Ui {
class newPicDialog;
}

class newPicDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit newPicDialog(QWidget *parent = 0);
    ~newPicDialog();
    
private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::newPicDialog *ui;
signals:
    void newPicConfirm(int x, int y);
};

#endif // NEWPICDIALOG_H
