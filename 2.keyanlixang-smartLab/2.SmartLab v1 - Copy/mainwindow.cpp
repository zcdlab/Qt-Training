#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMenuBar"
#include "QTimer"

QString Human;
QString Sound;
QString Temp;
QString Humidity;
QString Lux;
QString MQ2;
QString MQ7;
QString Red;
QString Green;
QString Blue;
QString Red_SpinBox="000";
QString Green_SpinBox="000";
QString Blue_SpinBox="000";
QString ALL_SpinBox;
QString Fire;
QString LED1="1";
QString LED2="1";
QString LED3="1";
QString LED4="1";
long Red_Innovation;
long Green_Innovation;
long Blue_Innovation;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    MainWindow::setWindowTitle(tr("智能实验室系统"));
    MainWindow::setFixedSize(969,620);
    setWindowIcon(QIcon(":images/MainIcon.ico"));
    ui->setupUi(this);
    startInit();
    myCom = NULL;
    createMenuBar();
    //自动加入串口 本软件自动查询注册表来自动添加串口
    init_com();
    ui->statusBar->showMessage(tr("By The Creative Man(TCM)&Enjoy it!"));
    on_actionOpen_triggered();
}
void MainWindow::init_com()
{
    QString path="HKEY_LOCAL_MACHINE\\HARDWARE\\DEVICEMAP\\SERIALCOMM";
    QSettings *settings=new QSettings(path,QSettings::NativeFormat);
    QStringList key=settings->allKeys();
    QStringList comlist ;
    QStringList Baudlist ;
    QStringList Paritylist ;
    QStringList DataBitslist;
    QStringList StopBitslist;
    QStringList ControlFlowlist;

    int kk = key.size();
    int i;
    comlist.clear();
    for(i=0;i<kk;i++)
    {
        comlist << getcomm(i,"value");
    }
    ui->portNameComboBox->addItems(comlist);

    //波特率
    Baudlist.clear();
    Baudlist<< "300" << "600" << "2400" << "4800" << "9600"<< "19200" <<
             "56000" << "57600" << "115200"<<"128000"<<"256000"<< "921600";
    ui->baudRateComboBox->addItems(Baudlist);
    ui->baudRateComboBox->setCurrentText("19200");


}







QString MainWindow::getcomm(int index,QString keyorvalue)
{
    QString commresult="";
    QString strkey="HARDWARE\\DEVICEMAP\\SERIALCOMM";//子键路径
    int a=strkey.toWCharArray(subkey);
    subkey[a]=L'\0';
    if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,subkey,0,KEY_READ|KEY_QUERY_VALUE,&hKey)!=0)
    {
        QString error="Cannot open regedit!";
    }

    QString keymessage="";//键名
    QString message="";
    QString valuemessage="";//键值
    indexnum=index;//要读取键值的索引号

    keysize=sizeof(keyname);
    valuesize=sizeof(keyvalue);

    if(::RegEnumValue(hKey,indexnum,keyname,&keysize,0,&type,(BYTE*)keyvalue,&valuesize)==0)
    {
        //读取键名
        for(int i=0;i<keysize;i++)
        {
            message=QString::fromStdWString(keyname);
            keymessage.append(message);
        }
        //读取键值
        for(int j=0;j<valuesize;j++)
        {
            if(keyvalue[j]!=0x00)
            {
                valuemessage.append(keyvalue[j]);
            }
        }

        if(keyorvalue=="key")
        {
            commresult=keymessage;
        }
        if(keyorvalue=="value")
        {
            commresult=valuemessage;
        }
    }
    else
    {
        commresult="nokey";
    }
    ::RegCloseKey(hKey);//关闭注册表
    return commresult;
}


MainWindow::~MainWindow()
{
    if(myCom != NULL){
        if(myCom->isOpen()){
            myCom->close();
        }
        delete myCom;
    }
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::startInit(){
    setActionsEnabled(false);
    ui->delayspinBox->setEnabled(false);
    ui->sendmsgBtn->setEnabled(false);
    ui->sendMsgLineEdit->setEnabled(false);
    ui->obocheckBox->setEnabled(false);
    ui->actionAdd->setEnabled(true);
    ui->toolButton_fire->setVisible(false);
    ui->toolButton_fire2->setVisible(true);
    ui->pushButton_light_fire->setVisible(true);
    ui->pushButton_light_fire->setEnabled(true);
    ui->pushButton_light_fire_2->setVisible(false);
    ui->pushButton_light_fire_2->setEnabled(false);
    ui->pushButton_light_fire_4->setVisible(true);
    ui->pushButton_light_fire_4->setEnabled(true);
    ui->pushButton_light_fire_3->setVisible(false);
    ui->pushButton_light_fire_3->setEnabled(false);
    ui->pushButton_light_fire_6->setVisible(true);
    ui->pushButton_light_fire_6->setEnabled(true);
    ui->pushButton_light_fire_5->setVisible(false);
    ui->pushButton_light_fire_5->setEnabled(false);
    ui->pushButton_light_fire_8->setVisible(false);
    ui->pushButton_light_fire_8->setEnabled(false);
    ui->pushButton_light_fire_7->setVisible(true);
    ui->pushButton_light_fire_7->setEnabled(true);

    //初始化连续发送计时器计时间隔
    obotimerdly = OBO_TIMER_INTERVAL;

    //设置连续发送计时器
    obotimer = new QTimer(this);
    connect(obotimer, SIGNAL(timeout()), this, SLOT(sendMsg()));


}

void MainWindow::setActionsEnabled(bool status)
{
    ui->actionSave->setEnabled(status);
    ui->actionClose->setEnabled(status);
    ui->actionLoadfile->setEnabled(status);
    ui->actionCleanPort->setEnabled(status);
    ui->actionWriteToFile->setEnabled(status);
}

void MainWindow::setComboBoxEnabled(bool status)
{
    ui->portNameComboBox->setEnabled(status);
    ui->baudRateComboBox->setEnabled(status);
    ui->dataBitsComboBox->setEnabled(status);
    ui->parityComboBox->setEnabled(status);
    ui->stopBitsComboBox->setEnabled(status);
}

//打开串口
void MainWindow::on_actionOpen_triggered()
{
    QString portName = ui->portNameComboBox->currentText();   //获取串口名
#ifdef Q_OS_LINUX
    myCom = new QextSerialPort("/dev/" + portName);
#elif defined (Q_OS_WIN)
    myCom = new QextSerialPort(portName);
#endif
    connect(myCom, SIGNAL(readyRead()), this, SLOT(readMyCom()));

    //设置波特率
    myCom->setBaudRate((BaudRateType)ui->baudRateComboBox->currentText().toInt());

    //设置数据位
    myCom->setDataBits((DataBitsType)ui->dataBitsComboBox->currentText().toInt());

    //设置校验
    switch(ui->parityComboBox->currentIndex()){
    case 0:
         myCom->setParity(PAR_NONE);
         break;
    case 1:
        myCom->setParity(PAR_ODD);
        break;
    case 2:
        myCom->setParity(PAR_EVEN);
        break;
    default:
        myCom->setParity(PAR_NONE);
        qDebug("set to default : PAR_NONE");
        break;
    }

    //设置停止位
    switch(ui->stopBitsComboBox->currentIndex()){
    case 0:
        myCom->setStopBits(STOP_1);
        break;
    case 1:
 #ifdef Q_OS_WIN
        myCom->setStopBits(STOP_1_5);
 #endif
        break;
    case 2:
        myCom->setStopBits(STOP_2);
        break;
    default:
        myCom->setStopBits(STOP_1);
        qDebug("set to default : STOP_1");
        break;
    }    

    //设置数据流控制
    myCom->setFlowControl(FLOW_OFF);
    //设置延时
    myCom->setTimeout(TIME_OUT);

    if(myCom->open(QIODevice::ReadWrite)){
        QMessageBox *messagebox=new QMessageBox();
        messagebox->setText(tr("当前打开的是：")+ portName+"\n"+tr("\n若使用的不是当前串口，请关闭串口后重新选择。"));
        messagebox->setWindowTitle(tr("串口打开成功"));
        QObjectList objChildList=messagebox->children();
        for (int i = 0; i < objChildList.size(); i++)        {
        QObject *pObj= objChildList.at(i);
        if (pObj->inherits("QWidget"))        {
        QWidget *pWidget = (QWidget*)pObj;
        pWidget->setStyleSheet("background-color: transparent");
        }
        }
        messagebox->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,stop: 0 rgba(255, 255, 255, 100%),stop: 1 rgba(10, 144, 255, 100%));");
        messagebox->show();
        timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),messagebox,SLOT(close()));
        timer->start(1000);
        //界面控制
		ui->sendmsgBtn->setEnabled(true);
        setComboBoxEnabled(false);
        ui->sendMsgLineEdit->setEnabled(true);
        ui->actionOpen->setEnabled(false);
        ui->sendMsgLineEdit->setFocus();
        ui->obocheckBox->setEnabled(true);
        ui->actionAdd->setEnabled(false);
        setActionsEnabled(true);
    }else{
        QMessageBox::critical(this, tr("打开失败"), tr("未能打开串口 ") + portName + tr("\n该串口设备不存在或已被占用"), QMessageBox::Ok);
        return;
    }
}


//关闭串口
void MainWindow::on_actionClose_triggered()
{
    myCom->close();
    delete myCom;
    myCom = NULL;
    ui->sendmsgBtn->setEnabled(false);
    setComboBoxEnabled(true);
    ui->actionOpen->setEnabled(true);
    ui->sendMsgLineEdit->setEnabled(false);
    ui->obocheckBox->setEnabled(false);
    ui->actionAdd->setEnabled(true);
    setActionsEnabled(false);
    ui->actionWriteToFile->setChecked(false);
    ui->statusBar->showMessage(tr("串口已经关闭"));
}

//关于
void MainWindow::on_actionAbout_triggered()
{
    aboutdlg.show();
    // 在主窗口中间显示
    int x =this->x() + (this->width() - aboutdlg.width()) / 2;
    int y =this->y() + (this->height() - aboutdlg.height()) / 2;
    aboutdlg.move(x, y);
    ui->statusBar->showMessage(tr("关于"));
}

//读取数据
void MainWindow::readMyCom()
{
    QByteArray temp ;
    QByteArray shiftElement ;
    QByteArray shiftResult ;
    QString buf;

    //if(!temp.isEmpty()){
    if(myCom->bytesAvailable() >=29 )
      {
            shiftElement=myCom->readAll();
            temp=shiftElement;
            for (int i = 0; i != shiftElement.length (); i++)//读取的24位数据循环移位，再相应输出到LCDNumberWidget显示
            {
                if(shiftElement[i]=='<')

                {
                    for(int j=0;j<29;j++)
                    {
                        if(i+j>=29)
                        shiftResult[j]=shiftElement[i+j-29];

                        else
                        shiftResult[j]=shiftElement[i+j];
                    }
                break;
                }
            }
            ui->textBrowser->setTextColor(Qt::black);
            if(ui->ccradioButton->isChecked())
            {
                buf = shiftResult;
            }
            else if(ui->chradioButton->isChecked())
            {
                QString str;
                for(int i = 0; i < temp.count(); i++)
                {
                    QString s;
                    s.sprintf("0x%02x, ", (unsigned char)temp.at(i));
                    buf += s;
                }
            }

        if(!write2fileName.isEmpty())
        {
            QFile file(write2fileName);
            //如果打开失败则给出提示并退出函数
            if(!file.open(QFile::WriteOnly | QIODevice::Text))
            {
                QMessageBox::warning(this, tr("写入文件"), tr("打开文件 %1 失败, 无法写入\n%2").arg(write2fileName).arg(file.errorString()), QMessageBox::Ok);
                return;
            }
            QTextStream out(&file);
            out<<buf;
            file.close();
        }

        Lux=buf.mid(1,5);
        ui->Lux_lcdNumber->display(Lux);
        Temp=buf.mid(7,2);
        ui->lcdNumber_Temp->display(Temp);
        Humidity=buf.mid(9,2);
        ui->lcdNumber_Humidity->display(Humidity);
        MQ2=buf.mid(15,5);
        ui->lcdNumber_MQ2->display(MQ2);
        MQ7=buf.mid(22,5);
        ui->lcdNumber_MQ7->display(MQ7);
        Fire=buf.mid(12,1);
        if(Fire=="1")
            {
                ui->label_fire->setText("检测到火焰");
                ui->toolButton_fire->setVisible(true);
                ui->toolButton_fire2->setVisible(false);
            }
       else
            {
                ui->label_fire->setText("无火势发现");
                ui->toolButton_fire->setVisible(false);
                ui->toolButton_fire2->setVisible(true);
            }
        LED1=buf.mid(13,1);
        LED2=buf.mid(20,1);
        LED3=buf.mid(27,1);
        if(LED1=="1")
        {
            ui->pushButton_light_fire->setVisible(false);
            ui->pushButton_light_fire->setEnabled(false);
            ui->pushButton_light_fire_2->setVisible(true);
            ui->pushButton_light_fire_2->setEnabled(true);
        }
        else if(LED1=="0")
        {
            ui->pushButton_light_fire->setVisible(true);
            ui->pushButton_light_fire->setEnabled(true);
            ui->pushButton_light_fire_2->setVisible(false);
            ui->pushButton_light_fire_2->setEnabled(false);
        }
        if(LED2=="1")
        {
            ui->pushButton_light_fire_3->setVisible(true);
            ui->pushButton_light_fire_3->setEnabled(true);
            ui->pushButton_light_fire_4->setVisible(false);
            ui->pushButton_light_fire_4->setEnabled(false);
        }
        else if(LED2=="0")
        {
            ui->pushButton_light_fire_3->setVisible(false);
            ui->pushButton_light_fire_3->setEnabled(false);
            ui->pushButton_light_fire_4->setVisible(true);
            ui->pushButton_light_fire_4->setEnabled(true);
        }
        if(LED3=="1")
        {

            ui->pushButton_light_fire_5->setVisible(true);
            ui->pushButton_light_fire_5->setEnabled(true);
            ui->pushButton_light_fire_6->setVisible(false);
            ui->pushButton_light_fire_6->setEnabled(false);
        }
        else if(LED3=="0")
        {
            ui->pushButton_light_fire_5->setVisible(false);
            ui->pushButton_light_fire_5->setEnabled(false);
            ui->pushButton_light_fire_6->setVisible(true);
            ui->pushButton_light_fire_6->setEnabled(true);
        }


        ui->textBrowser->setText(ui->textBrowser->document()->toPlainText() + buf);
        QTextCursor cursor = ui->textBrowser->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textBrowser->setTextCursor(cursor);
        ui->recvbyteslcdNumber->display(ui->recvbyteslcdNumber->value() + temp.size());
        ui->statusBar->showMessage(tr("成功读取%1字节数据").arg(temp.size()));
    }
}

//发送数据
void MainWindow::sendMsg()
{
    QByteArray buf;
    if(ui->sendAsHexcheckBox->isChecked()){
        QString str;
        bool ok;
        char data;
        QStringList list;
        str = ui->sendMsgLineEdit->text();
        list = str.split(" ");
        for(int i = 0; i < list.count(); i++){
            if(list.at(i) == " ")
                continue;
            if(list.at(i).isEmpty())
                continue;
            data = (char)list.at(i).toInt(&ok, 16);
            if(!ok){
                QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
                if(obotimer != NULL)
                    obotimer->stop();
                ui->sendmsgBtn->setText(tr("发送"));
                ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
                return;
            }
            buf.append(data);
        }
    }else{
#if QT_VERSION < 0x050000
        buf = ui->sendMsgLineEdit->text().toAscii();
#else
        buf = ui->sendMsgLineEdit->text().toLocal8Bit();
#endif
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("发送数据成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

//发送数据按钮
void MainWindow::on_sendmsgBtn_clicked()
{
    //如果当前正在连续发送数据，暂停发送
    if(ui->sendmsgBtn->text() == tr("暂停")){
        obotimer->stop();
        ui->sendmsgBtn->setText(tr("发送"));
        ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
        return;
    }
    //如果发送数据为空，给出提示并返回
    if(ui->sendMsgLineEdit->text().isEmpty()){
        QMessageBox::information(this, tr("提示消息"), tr("没有需要发送的数据"), QMessageBox::Ok);
        return;
    }

    //如果不是连续发送
    if(!ui->obocheckBox->isChecked()){
        ui->sendMsgLineEdit->setFocus();
        //发送数据
        sendMsg();
    }else{ //连续发送
        obotimer->start(obotimerdly);
        ui->sendmsgBtn->setText(tr("暂停"));
        ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/pause.png"));
    }
}
//清空记录
void MainWindow::on_clearUpBtn_clicked()
{
    ui->textBrowser->clear();
    ui->statusBar->showMessage(tr("记录已经清空"));
}



//计数器清零
void MainWindow::on_actionClearBytes_triggered()
{
    if(ui->recvbyteslcdNumber->value() == 0){
        QMessageBox::information(this, tr("提示消息"), tr("已清零:)"), QMessageBox::Ok);
    }else{
        ui->recvbyteslcdNumber->display(0);
        ui->statusBar->showMessage(tr("计数器已经清零"));
    }
}

//单击连续发送checkBox
void MainWindow::on_obocheckBox_clicked()
{
    if(ui->obocheckBox->isChecked()){
        ui->delayspinBox->setEnabled(true);
        //检查是否有数据，如有则启动定时器
        ui->statusBar->showMessage(tr("启用连续发送"));
    }else{
        ui->delayspinBox->setEnabled(false);
        //若定时器已经启动则关闭它
        ui->statusBar->showMessage(tr("停止连续发送"));
    }
}

//保存textBrowser中的内容
void MainWindow::on_actionSave_triggered()
{

    if(ui->textBrowser->toPlainText().isEmpty()){
        QMessageBox::information(this, "提示消息", tr("貌似还没有数据! 您需要在发送编辑框中输入要发送的数据"), QMessageBox::Ok);
        return;
    }

    QString filename = QFileDialog::getSaveFileName(this, tr("保存为"), tr("未命名.txt"));
    QFile file(filename);
    //如果用户取消了保存则直接退出函数
    if(file.fileName().isEmpty()){
        return;
    }
    //如果打开失败则给出提示并退出函数
    if(!file.open(QFile::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, tr("保存文件"), tr("打开文件 %1 失败, 无法保存\n%2").arg(filename).arg(file.errorString()), QMessageBox::Ok);
        return;
    }
    //写数据到文件
    QTextStream out(&file);
    out<<ui->textBrowser->toPlainText();
    file.close();
    //修改窗口标题为保存文件路径
    setWindowTitle("saved: " + QFileInfo(filename).canonicalFilePath());

}

//退出程序
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

//添加串口
void MainWindow::on_actionAdd_triggered()
{
    bool ok = false;
    QString portname;

    portname = QInputDialog::getText(this, tr("添加串口"), tr("设备文件名"), QLineEdit::Normal, 0, &ok);
    if(ok && !portname.isEmpty()){
        ui->portNameComboBox->addItem(portname);
        ui->statusBar->showMessage(tr("添加串口成功"));
    }
}

//调整连续发送时间间隔
void MainWindow::on_delayspinBox_valueChanged(int )
{
    obotimerdly = ui->delayspinBox->value();
}

//载入外部文件
void MainWindow::on_actionLoadfile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("读取文件"), 0, tr("保存为 (*.txt *.log)"));  //添加更多的文件类型
    QFile file(filename);

    //如果取消打开则退出函数
    if(file.fileName().isEmpty()){
        return;
    }

    //如果打开失败则提示并退出函数
    if(!file.open(QFile::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, tr("打开失败"),
                             tr("抱歉! Wincom未能打开此文件, 这可能是由于没有足够的权限造成的. 您可以尝试使用chmod命令修改文件权限."),
                             QMessageBox::Ok);
        return;
    }

    //文件大小超过限制
    if(file.size() > MAX_FILE_SIZE){
        QMessageBox::critical(this, tr("载入失败"), tr("文件大小为 %1 字节, 超过限制大小 10000 字节").arg(file.size()), QMessageBox::Ok);
        return;
    }
    //文件太大时提示是否继续打开
    if(file.size() > TIP_FILE_SIZE){
        if(QMessageBox::question(this, tr("提示消息"), tr("您要打开的文件过大, 这将消耗更多一些的时间,要继续打开么?"),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No){

            return;
        }
    }

    //读取数据并加入到发送数据编辑框
    QByteArray line;
    while(!file.atEnd()){
        line = file.readLine();
        ui->sendMsgLineEdit->setText(ui->sendMsgLineEdit->text() + tr(line));

    }
    file.close();
    ui->statusBar->showMessage(tr("已经成功读取文件中的数据"));
}

//清空串口中的I/O数据
void MainWindow::on_actionCleanPort_triggered()
{
    myCom->flush();
}

//写入文件菜单
void MainWindow::on_actionWriteToFile_triggered()
{
    if(ui->actionWriteToFile->isChecked()){
        QString filename = QFileDialog::getSaveFileName(this, tr("写入文件"), 0, tr("保存为 (*.*)"));  //添加更多的文件类型
        if(filename.isEmpty()){
            ui->actionWriteToFile->setChecked(false);
        }else{
            write2fileName = filename;
            //ui->textBrowser->setEnabled(false);
            ui->actionWriteToFile->setToolTip(tr("停止写入到文件"));
        }
    }else{
        write2fileName.clear();
        //ui->textBrowser->setEnabled(true);
        ui->actionWriteToFile->setToolTip(tr("将读取数据写入到文件"));
    }

}




void MainWindow::createMenuBar()
{
    mainAction=new QAction(tr("智能实验室GUI"),this);//初始化动作
    proAction=new QAction(tr("串口调试界面"),this);
    quitAction=new QAction(tr("退出软件"),this);

    mainAction->setShortcut(tr("Ctrl+M"));//设置快捷键
    proAction->setShortcut(tr("Ctrl+P"));
    quitAction->setShortcut(tr("Ctrl+Q"));


    mainMenu=menuBar()->addMenu(tr("切换界面"));//将界面操作动作添加到mainMenu中
    mainMenu->addAction(mainAction);
    mainMenu->addAction(proAction);
    mainMenu->addSeparator();
    //mainMenu->addAction(quitAction);

    aboutMenu=menuBar()->addMenu(tr("使用说明"));//使用说明的Menu界面

    connect(mainAction,SIGNAL(triggered()),this,SLOT(on_actionMainMenu_triggered()));//链接信号与槽
    connect(proAction,SIGNAL(triggered()),this,SLOT(on_actionProMenu_triggered()));
    //connect(quitAction,SIGNAL(triggered()),this,SLOT(on_actionQuitMenu_triggered()));
}

void MainWindow::on_actionMainMenu_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);//切换页从而达到不同界面的效果
}
void MainWindow::on_actionProMenu_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_actionQuitMenu_triggered()
{
    this->close();
}
void MainWindow::sendMessege(QString buf)
{
    QByteArray sendBuf;
    QString valueBuf=buf;
    QString R;
    QString G;
    QString B;

    sendBuf=valueBuf.toLocal8Bit();
    //发送数据
    myCom->write(sendBuf);
    ui->statusBar->showMessage(tr("发送数据成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
    R[0]=buf[0];
    R[1]=buf[1];
    R[2]=buf[2];
    G[0]=buf[3];
    G[1]=buf[4];
    G[2]=buf[5];
    B[0]=buf[6];
    B[1]=buf[7];
    B[2]=buf[8];
    buf="NULL";
}




void MainWindow::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}







void MainWindow::on_pushButton_light_fire_clicked()
{
    sendMessege("!a391");
}

void MainWindow::on_pushButton_light_fire_2_clicked()
{
    sendMessege("!a390");
}

void MainWindow::on_pushButton_light_fire_3_clicked()
{
    sendMessege("!b590");
}
void MainWindow::on_pushButton_light_fire_4_clicked()
{
    sendMessege("!b591");
}

void MainWindow::on_pushButton_light_fire_5_clicked()
{
    sendMessege("!c690");
}

void MainWindow::on_pushButton_light_fire_6_clicked()
{
    sendMessege("!c691");
}

void MainWindow::on_pushButton_light_fire_7_clicked()
{
    sendMessege("!z490");
    ui->pushButton_light_fire_7->setVisible(false);
    ui->pushButton_light_fire_7->setEnabled(false);
    ui->pushButton_light_fire_8->setVisible(true);
    ui->pushButton_light_fire_8->setEnabled(true);
}

void MainWindow::on_pushButton_light_fire_8_clicked()
{
    sendMessege("!z491");
    ui->pushButton_light_fire_7->setVisible(true);
    ui->pushButton_light_fire_7->setEnabled(true);
    ui->pushButton_light_fire_8->setVisible(false);
    ui->pushButton_light_fire_8->setEnabled(false);
}
