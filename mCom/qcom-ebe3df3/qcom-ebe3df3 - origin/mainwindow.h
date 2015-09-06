#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QMessageBox>
#include <QFile>
#include <QInputDialog>
#include <QFileDialog>
#include <QTextStream>

#include "qextserial/qextserialport.h"
#include "aboutdialog.h"
#include "QMainWindow"

//延时，TIME_OUT是串口读写的延时
#define TIME_OUT 10

//连续发送定时器计时间隔,200ms
#define OBO_TIMER_INTERVAL 200

//载入文件时，如果文件大小超过TIP_FILE_SIZE字节则提示文件过大是否继续打开
#define TIP_FILE_SIZE 5000
//载入文件最大长度限制在MAX_FILE_SIZE字节内
#define MAX_FILE_SIZE 10000

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startInit();

    QMenu   *mainMenu;
    QMenu   *aboutMenu;
    QAction *mainAction;
    QAction *proAction;
    QAction *quitAction;



protected:
    void changeEvent(QEvent *e);
    void setActionsEnabled(bool status);
    void setComboBoxEnabled(bool status);



private:
    Ui::MainWindow *ui;
    AboutDialog aboutdlg;
    QextSerialPort *myCom;
    QTimer *obotimer;
    unsigned int timerdly;
    unsigned int obotimerdly;
    QString write2fileName;    //写读取的串口数据到该文件

    void createMenuBar();
private slots:

    void on_actionWriteToFile_triggered();
    void on_actionCleanPort_triggered();
    void on_actionLoadfile_triggered();
    void on_delayspinBox_valueChanged(int );
    void on_actionAdd_triggered();
    void on_actionExit_triggered();
    void on_actionSave_triggered();
    void on_obocheckBox_clicked();
    void on_actionClearBytes_triggered();
    void on_actionAbout_triggered();
    void on_actionClose_triggered();
    void on_actionOpen_triggered();
    void on_clearUpBtn_clicked();
    void on_sendmsgBtn_clicked();
    void readMyCom();
    void sendMsg();


    void on_actionMainMenu_triggered();
    void on_actionProMenu_triggered();
    void on_actionQuitMenu_triggered();
    void sendMessege(QString buf);
    //end by

    void on_pushButton_clicked();
    void on_RED_pushButton_clicked();
    void on_RED_pushButton_2_clicked();
    void on_RED_pushButton_3_clicked();
};

#endif // MAINWINDOW_H
