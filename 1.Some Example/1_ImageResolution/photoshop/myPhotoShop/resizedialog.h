#ifndef RESIZEDIALOG_H
#define RESIZEDIALOG_H

#include <QDialog>

namespace Ui {
class reSizeDialog;
}

class reSizeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit reSizeDialog(QWidget *parent = 0);
    ~reSizeDialog();
    
private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::reSizeDialog *ui;

signals:
    void resizeConfirm(int x,int y, bool a, bool b, bool c);
};

#endif // RESIZEDIALOG_H
