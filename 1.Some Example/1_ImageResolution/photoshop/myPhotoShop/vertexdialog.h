#ifndef VERTEXDIALOG_H
#define VERTEXDIALOG_H

#include <QDialog>

namespace Ui {
class vertexDialog;
}

class vertexDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit vertexDialog(QWidget *parent = 0);
    ~vertexDialog();
    
private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::vertexDialog *ui;

signals:
    void vertexConfirm(int x1,int x2,int y1,int y2,int r,int g,int b);
};

#endif // VERTEXDIALOG_H
