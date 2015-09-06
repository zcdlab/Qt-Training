#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QMessageBox>
#include <QFile>
#include <QInputDialog>
#include <QFileDialog>
#include <QTextStream>

#include <qt_windows.h>
#include "qextserial/qextserialport.h"
//#include "qextserial/win_qextserialport.h"
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

    QString getcomm(int index,QString keyorvalue); //读取键名

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
    void init_com();
    QTimer *timer;
    QStringList m_listCommand;  //待发送的命令
    wchar_t subkey[80];
    wchar_t keyname[256]; //键名数组
    char keyvalue[256];  //键值数组
    int indexnum;
    DWORD keysize,type,valuesize;
    HKEY hKey;



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
    //void on_actionQuitMenu_triggered();
    void sendMessege(QString buf);
    //end by
    //LED Button//
    void on_RED_pushButton_clicked();
    void on_Green_pushButton_clicked();
    void on_Blue_pushButton_clicked();
    void on_TurnOff_pushButton_clicked();
    void on_Yellow_pushButton_clicked();
    void on_Purple_pushButton_clicked();
    void on_Orange_pushButton_clicked();
    void on_Cyan_pushButton_clicked();
    void on_Red_horizontalSlider_valueChanged(int value);
    void on_Red_spinBox_valueChanged(const QString &arg1);

    void sleep(unsigned int msec);
    void on_Green_spinBox_valueChanged(const QString &arg1);
    void on_Blue_spinBox_valueChanged(const QString &arg1);
    void timeout();
};

#endif // MAINWINDOW_H
