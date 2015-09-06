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

public slots:
    void dataReceived();
    void Connect();
private slots:
    void on_pushButton_connect_clicked();
};

#endif // TCPCLIENT_H
