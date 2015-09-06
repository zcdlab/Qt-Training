#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "password.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_sure_clicked();

    void on_pushButton_Encrypt_clicked();

    void on_pushButton_copy_clicked();

private:
    Ui::MainWindow *ui;
    password* uiPassword=new password(this);
    QString mainPassword;

};

#endif // MAINWINDOW_H
