#include "tcpclient.h"
#include "ui_tcpclient.h"

tcpclient::tcpclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tcpclient)
{

    ui->setupUi(this);
    ////////////////界面初始化/////////////
    /// \brief setWindowTitle
    status=false;
    setWindowTitle(tr("智能实验室"));
    ui->lineEdit_ip->setText("192.168.23.1");
    ui->lineEdit_port->setText("8080");

}


void tcpclient::Connect()
{
    tcpSocket=new QTcpSocket(this);
    ip=ui->lineEdit_ip->text();
    port=ui->lineEdit_port->text().toInt();
    tcpSocket->connectToHost(ip,port);
    if(tcpSocket->waitForConnected(1000))
    {
        tcpSocket->write("hello server");
        ui->statusBar->showMessage("Connectted");
        ui->pushButton_connect->setText(tr("断开"));
    }
    else
    {
        ui->statusBar->showMessage("DisConnect");
    }
}

void tcpclient::dataReceived()
{
    while(tcpSocket->bytesAvailable()>0)
        {
        /////////////数据接收////////////
            QByteArray datagram;
            datagram.resize(tcpSocket->bytesAvailable());
            tcpSocket->read(datagram.data(),datagram.size());

        /////////////statueBar数据显示////////////
            QString msg=datagram.data();
            QString showStatue;
            showStatue="接收长度：";showStatue.append(datagram.size()+'0');
            showStatue+="接收数据为：";showStatue.append(msg);
            ui->statusBar->showMessage(showStatue);

        }

}

tcpclient::~tcpclient()
{
    delete ui;
}

void tcpclient::on_pushButton_connect_clicked()
{
    status=!status;
    if(status)
    {
    Connect();
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    }
    else
    {
    tcpSocket->close();
    ui->pushButton_connect->setText(tr("连接"));
    ui->statusBar->showMessage("DisConnect");
    }
}
