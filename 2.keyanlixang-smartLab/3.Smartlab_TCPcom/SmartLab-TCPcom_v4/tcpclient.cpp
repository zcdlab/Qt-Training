#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QPalette>
#include <QPixmap>

tcpclient::tcpclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tcpclient)
{

    ui->setupUi(this);
    ////////////////界面初始化/////////////
    /// \brief setWindowTitle
    status=false;
    setWindowTitle(tr("智能实验室"));
    tcpclient::setFixedSize(1299,608);
    setWindowIcon(QIcon(":images/MainIcon.ico"));
    QPalette palette;  //创建一个调色板的对象
    QFrame framePix;
    framePix.resize(1299,608);
    QPixmap pixmap(":images/1316481604JarP5K.png");
    palette.setBrush(framePix.backgroundRole(),QBrush( pixmap));
    framePix.setPalette(palette);
    framePix.show();
    ui->lineEdit_ip->setText("192.168.23.1");
    ui->lineEdit_port->setText("8080");

    ui->pushButton_light_fire_110->setVisible(false);
    ui->pushButton_light_fire_110->setEnabled(false);
    ui->pushButton_light_fire_111->setVisible(true);
    ui->pushButton_light_fire_111->setEnabled(true);
    ui->pushButton_light_fire_120->setVisible(false);
    ui->pushButton_light_fire_120->setEnabled(false);
    ui->pushButton_light_fire_121->setVisible(true);
    ui->pushButton_light_fire_121->setEnabled(true);


    ui->pushButton_light_fire_210->setVisible(false);
    ui->pushButton_light_fire_210->setEnabled(false);
    ui->pushButton_light_fire_211->setVisible(true);
    ui->pushButton_light_fire_211->setEnabled(true);
    ui->pushButton_light_fire_220->setVisible(false);
    ui->pushButton_light_fire_220->setEnabled(false);
    ui->pushButton_light_fire_221->setVisible(true);
    ui->pushButton_light_fire_221->setEnabled(true);


    ui->pushButton_light_fire_310->setVisible(false);
    ui->pushButton_light_fire_310->setEnabled(false);
    ui->pushButton_light_fire_311->setVisible(true);
    ui->pushButton_light_fire_311->setEnabled(true);
    ui->pushButton_light_fire_320->setVisible(false);
    ui->pushButton_light_fire_320->setEnabled(false);
    ui->pushButton_light_fire_321->setVisible(true);
    ui->pushButton_light_fire_321->setEnabled(true);


    ui->pushButton_light_fire_410->setVisible(false);
    ui->pushButton_light_fire_410->setEnabled(false);
    ui->pushButton_light_fire_411->setVisible(true);
    ui->pushButton_light_fire_411->setEnabled(true);
    ui->pushButton_light_fire_420->setVisible(false);
    ui->pushButton_light_fire_420->setEnabled(false);
    ui->pushButton_light_fire_421->setVisible(true);
    ui->pushButton_light_fire_421->setEnabled(true);


    ui->pushButton_light_fire_510->setVisible(false);
    ui->pushButton_light_fire_510->setEnabled(false);
    ui->pushButton_light_fire_511->setVisible(true);
    ui->pushButton_light_fire_511->setEnabled(true);
    ui->pushButton_light_fire_520->setVisible(false);
    ui->pushButton_light_fire_520->setEnabled(false);
    ui->pushButton_light_fire_521->setVisible(true);
    ui->pushButton_light_fire_521->setEnabled(true);

}


void tcpclient::Connect()
{
    tcpSocket=new QTcpSocket(this);
    ip=ui->lineEdit_ip->text();
    port=ui->lineEdit_port->text().toInt();
    tcpSocket->connectToHost(ip,port);
    QString ipShow="ip地址：";ipShow+=ip;
    QString portShow="端口号:";portShow+=ui->lineEdit_port->text();

    if(tcpSocket->waitForConnected(1000))
    {
        tcpSocket->write("hello server");
        ui->statusBar->showMessage("Connectted");
        ui->pushButton_connect->setText(tr("断开"));
        ui->menuIP->setTitle(ipShow);
        ui->menu_2->setTitle(portShow);
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

        /////////////statueBar显示////////////
            QString msg=datagram.data();
            QString showStatue;
            showStatue="接收长度：";showStatue.append(datagram.size()+'0');
            showStatue+="接收数据为：";showStatue.append(msg);
            ui->statusBar->showMessage(showStatue);

            ///////////数据分别控件显示/////////////
///<光强#温#湿度#灯#火 |光强#温#湿度#灯#火 |光强#温#湿度#灯#火 |光强#温#湿度#灯#火 |光强#温#湿度#灯#火>
///<11111#11#11#11#0|22222#22#22#00#0|33333#33#33#10#0|44444#44#44#01#0|55555#55#55#00#0>///
            ///////////节点一//////////
            Lux1=msg.mid(1,5);
            ui->lcdNumber_lux_1->display(Lux1);

            Temp1=msg.mid(7,8);
            ui->lcdNumber_Temp_1->display(Temp1);

            Humdity1=msg.mid(10,11);
            ui->lcdNumber_Humidity_1->display(Humdity1);

            Relay11=msg[13];
            Relay12=msg[14];

            Fire1=msg[16];
            if(Fire1=="0")
            {
                ui->Label_FireResult_1->setStyleSheet("color:RED");
                ui->Label_FireResult_1->setText("发现火焰");
            }
            else
            {
                ui->Label_FireResult_1->setStyleSheet("color:BLACK");
                ui->Label_FireResult_1->setText(" 正常 ");
            }

            ///////////节点二//////////
            Lux2=msg.mid(18,22);
            ui->lcdNumber_lux_2->display(Lux2);

            Temp2=msg.mid(24,25);
            ui->lcdNumber_Temp_2->display(Temp2);

            Humdity2=msg.mid(27,28);
            ui->lcdNumber_Humidity_2->display(Humdity2);

            Relay21=msg[30];
            Relay22=msg[31];

            Fire2=msg[33];
            if(Fire2=="0")
            {
                ui->Label_FireResult_2->setStyleSheet("color:RED");
                ui->Label_FireResult_2->setText("发现火焰");
            }
            else
            {
                ui->Label_FireResult_2->setStyleSheet("color:BLACK");
                ui->Label_FireResult_2->setText(" 正常 ");
            }

            ///////////节点三//////////
            Lux3=msg.mid(35,39);
            ui->lcdNumber_lux_3->display(Lux3);

            Temp3=msg.mid(41,42);
            ui->lcdNumber_Temp_3->display(Temp3);

            Humdity3=msg.mid(44,45);
            ui->lcdNumber_Humidity_3->display(Humdity3);

            Relay31=msg[47];
            Relay32=msg[48];

            Fire3=msg[50];
            if(Fire3=="0")
            {
                ui->Label_FireResult_3->setStyleSheet("color:RED");
                ui->Label_FireResult_3->setText("发现火焰");
            }
            else
            {
                ui->Label_FireResult_3->setStyleSheet("color:BLACK");
                ui->Label_FireResult_3->setText(" 正常 ");
            }

            ///////////节点四//////////
            Lux4=msg.mid(52,56);
            ui->lcdNumber_lux_4->display(Lux4);

            Temp4=msg.mid(58,59);
            ui->lcdNumber_Temp_4->display(Temp4);

            Humdity4=msg.mid(61,62);
            ui->lcdNumber_Humidity_4->display(Humdity4);

            Relay41=msg[64];
            Relay42=msg[65];


            Fire4=msg[67];
            if(Fire4=="0")
            {
                ui->Label_FireResult_4->setStyleSheet("color:RED");
                ui->Label_FireResult_4->setText("发现火焰");
            }
            else
            {
                ui->Label_FireResult_4->setStyleSheet("color:BLACK");
                ui->Label_FireResult_4->setText(" 正常 ");
            }

            ///////////节点五//////////
            Lux5=msg.mid(69,73);
            ui->lcdNumber_lux_5->display(Lux5);

            Temp5=msg.mid(75,76);
            ui->lcdNumber_Temp_5->display(Temp5);

            Humdity5=msg.mid(78,79);
            ui->lcdNumber_Humidity_5->display(Humdity5);

            Relay51=msg[81];
            Relay52=msg[82];

            Fire5=msg[84];
            if(Fire5=="0")
            {
                ui->Label_FireResult_5->setStyleSheet("color:RED");
                ui->Label_FireResult_5->setText("发现火焰");
            }
            else
            {
                ui->Label_FireResult_5->setStyleSheet("color:BLACK");
                ui->Label_FireResult_5->setText(" 正常 ");
            }

            if(Fire1=="0"||Fire2=="0"||Fire3=="0"||Fire4=="0"||Fire5=="0")
            {
                ui->label_final->setStyleSheet("color:RED");
                ui->label_final->setText("起火");
            }
            else
            {
                ui->label_final->setStyleSheet("color:BLACK");
                ui->label_final->setText("良好");
            }
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
    QString ipShow="ip地址：";\
    QString portShow="端口号:";
    ui->menuIP->setTitle(ipShow);
    ui->menu_2->setTitle(portShow);
    ui->pushButton_connect->setText(tr("连接"));
    ui->statusBar->showMessage("DisConnect");
    }
}
///////////////////点灯 槽函数////////////
void tcpclient::on_pushButton_light_fire_110_clicked()
{
     tcpSocket->write("!z111");
    ui->pushButton_light_fire_110->setVisible(false);
    ui->pushButton_light_fire_110->setEnabled(false);
    ui->pushButton_light_fire_111->setVisible(true);
    ui->pushButton_light_fire_111->setEnabled(true);
}

void tcpclient::on_pushButton_light_fire_111_clicked()
{
    tcpSocket->write("!z110");
     ui->pushButton_light_fire_110->setVisible(true);
     ui->pushButton_light_fire_110->setEnabled(true);
     ui->pushButton_light_fire_111->setVisible(false);
     ui->pushButton_light_fire_111->setEnabled(false);

}

void tcpclient::on_pushButton_light_fire_120_clicked()
{
    tcpSocket->write("!z121");
    ui->pushButton_light_fire_120->setVisible(false);
    ui->pushButton_light_fire_120->setEnabled(false);
    ui->pushButton_light_fire_121->setVisible(true);
    ui->pushButton_light_fire_121->setEnabled(true);
}

void tcpclient::on_pushButton_light_fire_121_clicked()
{
    tcpSocket->write("!z120");
    ui->pushButton_light_fire_120->setVisible(true);
    ui->pushButton_light_fire_120->setEnabled(true);
    ui->pushButton_light_fire_121->setVisible(false);
    ui->pushButton_light_fire_121->setEnabled(false);

}

void tcpclient::on_pushButton_light_fire_210_clicked()
{
    tcpSocket->write("!z211");
    ui->pushButton_light_fire_210->setVisible(true);
    ui->pushButton_light_fire_210->setEnabled(true);
    ui->pushButton_light_fire_211->setVisible(false);
    ui->pushButton_light_fire_211->setEnabled(false);
}

void tcpclient::on_pushButton_light_fire_211_clicked()
{
    tcpSocket->write("!z210");
    ui->pushButton_light_fire_210->setVisible(false);
    ui->pushButton_light_fire_210->setEnabled(false);
    ui->pushButton_light_fire_211->setVisible(true);
    ui->pushButton_light_fire_211->setEnabled(true);

}

void tcpclient::on_pushButton_light_fire_220_clicked()
{
    tcpSocket->write("!z221");
    ui->pushButton_light_fire_220->setVisible(true);
    ui->pushButton_light_fire_220->setEnabled(true);
    ui->pushButton_light_fire_221->setVisible(false);
    ui->pushButton_light_fire_221->setEnabled(false);

}


void tcpclient::on_pushButton_light_fire_221_clicked()
{
    tcpSocket->write("!z220");
    ui->pushButton_light_fire_220->setVisible(false);
    ui->pushButton_light_fire_220->setEnabled(false);
    ui->pushButton_light_fire_221->setVisible(true);
    ui->pushButton_light_fire_221->setEnabled(true);

}

void tcpclient::on_pushButton_light_fire_310_clicked()
{
    tcpSocket->write("!z311");
    ui->pushButton_light_fire_310->setVisible(true);
    ui->pushButton_light_fire_310->setEnabled(true);
    ui->pushButton_light_fire_311->setVisible(false);
    ui->pushButton_light_fire_311->setEnabled(false);

}

void tcpclient::on_pushButton_light_fire_311_clicked()
{
    tcpSocket->write("!z310");
    ui->pushButton_light_fire_310->setVisible(false);
    ui->pushButton_light_fire_310->setEnabled(false);
    ui->pushButton_light_fire_311->setVisible(true);
    ui->pushButton_light_fire_311->setEnabled(true);

}

void tcpclient::on_pushButton_light_fire_320_clicked()
{
    tcpSocket->write("!z321");
    ui->pushButton_light_fire_320->setVisible(true);
    ui->pushButton_light_fire_320->setEnabled(true);
    ui->pushButton_light_fire_321->setVisible(false);
    ui->pushButton_light_fire_321->setEnabled(false);

}

void tcpclient::on_pushButton_light_fire_321_clicked()
{
    tcpSocket->write("!z320");
    ui->pushButton_light_fire_320->setVisible(false);
    ui->pushButton_light_fire_320->setEnabled(false);
    ui->pushButton_light_fire_321->setVisible(true);
    ui->pushButton_light_fire_321->setEnabled(true);

}

void tcpclient::on_pushButton_light_fire_410_clicked()
{
    tcpSocket->write("!z411");
    ui->pushButton_light_fire_410->setVisible(true);
    ui->pushButton_light_fire_410->setEnabled(true);
    ui->pushButton_light_fire_411->setVisible(false);
    ui->pushButton_light_fire_411->setEnabled(false);

}

void tcpclient::on_pushButton_light_fire_411_clicked()
{
    tcpSocket->write("!z410");
    ui->pushButton_light_fire_410->setVisible(false);
    ui->pushButton_light_fire_410->setEnabled(false);
    ui->pushButton_light_fire_411->setVisible(true);
    ui->pushButton_light_fire_411->setEnabled(true);

}

void tcpclient::on_pushButton_light_fire_420_clicked()
{
    tcpSocket->write("!z421");
    ui->pushButton_light_fire_420->setVisible(true);
    ui->pushButton_light_fire_420->setEnabled(true);
    ui->pushButton_light_fire_421->setVisible(false);
    ui->pushButton_light_fire_421->setEnabled(false);

}

void tcpclient::on_pushButton_light_fire_421_clicked()
{
    tcpSocket->write("!z420");
    ui->pushButton_light_fire_420->setVisible(false);
    ui->pushButton_light_fire_420->setEnabled(false);
    ui->pushButton_light_fire_421->setVisible(true);
    ui->pushButton_light_fire_421->setEnabled(true);

}

void tcpclient::on_pushButton_light_fire_510_clicked()
{
    tcpSocket->write("!z511");
    ui->pushButton_light_fire_510->setVisible(true);
    ui->pushButton_light_fire_510->setEnabled(true);
    ui->pushButton_light_fire_511->setVisible(false);
    ui->pushButton_light_fire_511->setEnabled(false);

}

void tcpclient::on_pushButton_light_fire_511_clicked()
{
    tcpSocket->write("!z510");
    ui->pushButton_light_fire_510->setVisible(false);
    ui->pushButton_light_fire_510->setEnabled(false);
    ui->pushButton_light_fire_511->setVisible(true);
    ui->pushButton_light_fire_511->setEnabled(true);

}

void tcpclient::on_pushButton_light_fire_520_clicked()
{
    tcpSocket->write("!z521");
    ui->pushButton_light_fire_520->setVisible(true);
    ui->pushButton_light_fire_520->setEnabled(true);
    ui->pushButton_light_fire_521->setVisible(false);
    ui->pushButton_light_fire_521->setEnabled(false);

}

void tcpclient::on_pushButton_light_fire_521_clicked()
{
    tcpSocket->write("!z520");
    ui->pushButton_light_fire_520->setVisible(false);
    ui->pushButton_light_fire_520->setEnabled(false);
    ui->pushButton_light_fire_521->setVisible(true);
    ui->pushButton_light_fire_521->setEnabled(true);
}
