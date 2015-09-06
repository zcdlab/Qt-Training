#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QMainWindow>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class tcpclient;
}

class tcpclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit tcpclient(QWidget *parent = 0);
    ~tcpclient();



private:
    Ui::tcpclient *ui;
    bool status;
    QString ip;
    int port;
    QHostAddress *serverIP;
    QString userName;
    QTcpSocket *tcpSocket;


    QString Lux1;
    QString Lux2;
    QString Lux3;
    QString Lux4;
    QString Lux5;

    QString Temp1;
    QString Temp2;
    QString Temp3;
    QString Temp4;
    QString Temp5;

    QString Humdity1;
    QString Humdity2;
    QString Humdity3;
    QString Humdity4;
    QString Humdity5;

    QString Fire1;
    QString Fire2;
    QString Fire3;
    QString Fire4;
    QString Fire5;

    QString Relay11;
    QString Relay12;
    QString Relay21;
    QString Relay22;
    QString Relay31;
    QString Relay32;
    QString Relay41;
    QString Relay42;
    QString Relay51;
    QString Relay52;


public slots:
    void dataReceived();
    void Connect();
private slots:
    void on_pushButton_connect_clicked();
    void on_pushButton_light_fire_110_clicked();
    void on_pushButton_light_fire_111_clicked();
    void on_pushButton_light_fire_120_clicked();
    void on_pushButton_light_fire_121_clicked();
    void on_pushButton_light_fire_220_clicked();
    void on_pushButton_light_fire_211_clicked();
    void on_pushButton_light_fire_210_clicked();
    void on_pushButton_light_fire_221_clicked();
    void on_pushButton_light_fire_310_clicked();
    void on_pushButton_light_fire_311_clicked();
    void on_pushButton_light_fire_320_clicked();
    void on_pushButton_light_fire_321_clicked();
    void on_pushButton_light_fire_410_clicked();
    void on_pushButton_light_fire_411_clicked();
    void on_pushButton_light_fire_420_clicked();
    void on_pushButton_light_fire_421_clicked();
    void on_pushButton_light_fire_510_clicked();
    void on_pushButton_light_fire_511_clicked();
    void on_pushButton_light_fire_520_clicked();
    void on_pushButton_light_fire_521_clicked();
};

#endif // TCPCLIENT_H
