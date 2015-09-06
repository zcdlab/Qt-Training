#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMenuBar"
#include "QTimer"

QString Lux;
QString Red;
QString Green;
QString Blue;
QString Red_SpinBox="000";
QString Green_SpinBox="000";
QString Blue_SpinBox="000";
QString ALL_SpinBox;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startInit();
    myCom = NULL;
    ui->qter->setText("T C M");
    createMenuBar();
//自动加入串口 本软件自动查询注册表来自动添加串口
    init_com();
    ui->statusBar->showMessage(tr("Edit By TCM&Enjoy it!"));


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

    ui->Red_horizontalSlider->setMinimum(0);//Slider的最小值
    ui->Green_horizontalSlider->setMinimum(0);
    ui->Blue_horizontalSlider->setMinimum(0);
    ui->Red_horizontalSlider->setMaximum(255);//Slider的最大值
    ui->Green_horizontalSlider->setMaximum(255);
    ui->Blue_horizontalSlider->setMaximum(255);
    ui->Red_horizontalSlider->setValue(Red.toInt());//Slider的初始化值
    ui->Green_horizontalSlider->setValue(Green.toInt());
    ui->Blue_horizontalSlider->setValue(Blue.toInt());
    ui->Red_horizontalSlider->setPageStep(1);//Slider的每次变化为1
    ui->Green_horizontalSlider->setPageStep(1);
    ui->Blue_horizontalSlider->setPageStep(1);
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
        QMessageBox::information(this, tr("打开成功"), tr("已成功打开串口") + portName, QMessageBox::Ok);
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

    ui->statusBar->showMessage(tr("打开串口成功"));
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
    ui->statusBar->showMessage(tr("关于Wincom"));
}

//读取数据
void MainWindow::readMyCom()
{
    QByteArray temp ;
    QByteArray shiftElement ;
    QByteArray shiftResult ;
    QString buf;

    //if(!temp.isEmpty()){
    if(myCom->bytesAvailable() >=19 )
      {
            shiftElement=myCom->readAll();
            temp=shiftElement;
            for (int i = 0; i != shiftElement.length (); i++)//读取的19位数据循环移位，再相应输出到LCDNumberWidget显示
            {
                if(shiftElement[i]=='<')

                {
                    for(int j=0;j<19;j++)
                    {
                        if(i+j>=19)
                        shiftResult[j]=shiftElement[i+j-19];

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
        Red=buf.mid(7,3);
        ui->Red_lcdNumber->display(Red);
        Green=buf.mid(11,3);
        ui->Green_lcdNumber->display(Green);
        Blue=buf.mid(15,3);
        ui->Blue_lcdNumber->display(Blue);


        Red_SpinBox=Red;
        Green_SpinBox=Green;
        Blue_SpinBox=Blue;
        ALL_SpinBox=Red.append(Green).append(Blue);



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
        QMessageBox::information(this, tr("提示消息"), tr("貌似已经清零了呀:)"), QMessageBox::Ok);
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
    mainAction=new QAction(tr("变色灯GUI主界面"),this);//初始化动作
    proAction=new QAction(tr("串口调试界面"),this);
    quitAction=new QAction(tr("退出软件"),this);

    mainAction->setShortcut(tr("Ctrl+M"));//设置快捷键
    proAction->setShortcut(tr("Ctrl+P"));
    quitAction->setShortcut(tr("Ctrl+Q"));


    mainMenu=menuBar()->addMenu(tr("切换界面"));//将界面操作动作添加到mainMenu中
    mainMenu->addAction(mainAction);
    mainMenu->addAction(proAction);
    mainMenu->addSeparator();
    mainMenu->addAction(quitAction);

    aboutMenu=menuBar()->addMenu(tr("使用说明"));//使用说明的Menu界面

    connect(mainAction,SIGNAL(triggered()),this,SLOT(on_actionMainMenu_triggered()));//链接信号与槽
    connect(proAction,SIGNAL(triggered()),this,SLOT(on_actionProMenu_triggered()));
    connect(quitAction,SIGNAL(triggered()),this,SLOT(on_actionQuitMenu_triggered()));

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
    qDebug()<<R;
    qDebug()<<G;
    qDebug()<<B;
    ui->Red_horizontalSlider->setValue(R.toInt());
    ui->Green_horizontalSlider->setValue(G.toInt());
    ui->Blue_horizontalSlider->setValue(B.toInt());
    //ui->Red_spinBox->setValue(R.toInt());
    //ui->Green_spinBox->setValue(G.toInt());
    //ui->Blue_spinBox->setValue(B.toInt());
    buf="NULL";
}


void MainWindow::on_RED_pushButton_clicked()
{
    sendMessege("255000000");
}

void MainWindow::on_Green_pushButton_clicked()
{
    sendMessege("000255000");
}

void MainWindow::on_Blue_pushButton_clicked()
{
    sendMessege("000000255");
}

void MainWindow::on_TurnOff_pushButton_clicked()
{
    sendMessege("000000000");
}


void MainWindow::on_Yellow_pushButton_clicked()
{
    sendMessege("255255000");
}

void MainWindow::on_Purple_pushButton_clicked()
{
    sendMessege("160032240");
}

void MainWindow::on_Orange_pushButton_clicked()
{
    sendMessege("255165000");
}

void MainWindow::on_Cyan_pushButton_clicked()
{
    sendMessege("000255255");
}


void MainWindow::on_Red_horizontalSlider_valueChanged(int value)
{
    /*int temp;
    QString send;
    QString RedTemp;
    QString sendTemp;
    temp=value;
    RedTemp=QString::number(temp,10);
    if(temp<100&&temp>=10)
    {
        sendTemp[0]='0';
        sendTemp[1]=RedTemp[0];
        sendTemp[2]=RedTemp[1];
    }
    else if(temp<10)
    {
        sendTemp[0]='0';
        sendTemp[1]='0';
        sendTemp[2]=RedTemp[0];
    }
    else
    {
        sendTemp[0]=RedTemp[0];
        sendTemp[1]=RedTemp[1];
        sendTemp[2]=RedTemp[2];
    }

    //send=sendTemp.append("000000").mid(0,9);
    //Red=sendTemp.append("000000").mid(0,3);
    //sendMessege(send);*/
}



void MainWindow::on_Red_spinBox_valueChanged(const QString &arg1)
{
    int argInt=arg1.toInt();
    sleep(100);
    QString argBuf=arg1;
    if(argInt<10)
    {
        argBuf[0]='0';
        argBuf[1]='0';
        argBuf[2]=arg1[0];
    }
    else if(10<=argInt&&argInt<100)
    {
        argBuf[0]='0';
        argBuf[1]=arg1[0];
        argBuf[2]=arg1[1];
    }
    else if(255<argInt||argInt<0)
    {
       QMessageBox *messageBox=new QMessageBox(QMessageBox::Information,"错误","请输入0~255的整数",QMessageBox::Close,this);
       messageBox->show();
       timer=new QTimer(this);
       connect(timer,SIGNAL(timeout()),messageBox,SLOT(close()));
       timer->start(5000);
       return;
    }
    else
    {
        argBuf[0]=arg1[0];
        argBuf[1]=arg1[1];
        argBuf[2]=arg1[2];
    }
   Red_SpinBox=argBuf;
   ALL_SpinBox=Red_SpinBox.append(Green_SpinBox).append(Blue_SpinBox);
   sendMessege(ALL_SpinBox);
}

void MainWindow::on_Green_spinBox_valueChanged(const QString &arg1)
{
    int argInt=arg1.toInt();
    sleep(100);
    QString argBuf=arg1;
    if(argInt<10)
    {
        argBuf[0]='0';
        argBuf[1]='0';
        argBuf[2]=arg1[0];
    }
    else if(10<=argInt&&argInt<100)
    {
        argBuf[0]='0';
        argBuf[1]=arg1[0];
        argBuf[2]=arg1[1];
    }
    else if(255<argInt||argInt<0)
    {
       QMessageBox *messageBox=new QMessageBox(QMessageBox::Information,"错误","请输入0~255的整数",QMessageBox::Close,this);
       messageBox->show();
       timer=new QTimer(this);
       connect(timer,SIGNAL(timeout()),messageBox,SLOT(close()));
       timer->start(5000);
       return;
    }
    else
    {
        argBuf[0]=arg1[0];
        argBuf[1]=arg1[1];
        argBuf[2]=arg1[2];
    }

   Green_SpinBox=argBuf;
   ALL_SpinBox=Red_SpinBox.append(Green_SpinBox).append(Blue_SpinBox);
   sendMessege(ALL_SpinBox);
}

void MainWindow::on_Blue_spinBox_valueChanged(const QString &arg1)
{
    int argInt=arg1.toInt();
    QString argBuf=arg1;
    if(argInt<10)
    {
        argBuf[0]='0';
        argBuf[1]='0';
        argBuf[2]=arg1[0];
    }
    else if(10<=argInt&&argInt<100)
    {
        argBuf[0]='0';
        argBuf[1]=arg1[0];
        argBuf[2]=arg1[1];
    }
    else if(255<argInt||argInt<0)
    {
       QMessageBox *messageBox=new QMessageBox(QMessageBox::Information,"错误","请输入0~255的整数",QMessageBox::Close,this);
       messageBox->show();
       timer=new QTimer(this);
       connect(timer,SIGNAL(timeout()),messageBox,SLOT(close()));
       timer->start(5000);
       return;
    }
    else
    {
        argBuf[0]=arg1[0];
        argBuf[1]=arg1[1];
        argBuf[2]=arg1[2];
    }

   Blue_SpinBox=argBuf;
   ALL_SpinBox=Red_SpinBox.append(Green_SpinBox).append(Blue_SpinBox);
   sendMessege(ALL_SpinBox);
}
void MainWindow::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_Red_lineEdit_textEdited(const QString &arg1)
{
    int argInt=arg1.toInt();
    QString argBuf=arg1;
    if(argInt<10)
    {
        argBuf[0]='0';
        argBuf[1]='0';
        argBuf[2]=arg1[0];
    }
    else if(10<=argInt&&argInt<100)
    {
        argBuf[0]='0';
        argBuf[1]=arg1[0];
        argBuf[2]=arg1[1];
    }
    else if(255<argInt||argInt<0)
    {
       QMessageBox *messageBox=new QMessageBox(QMessageBox::Information,"错误","请输入0~255的整数",QMessageBox::Close,this);
       messageBox->show();
       timer=new QTimer(this);
       connect(timer,SIGNAL(timeout()),messageBox,SLOT(close()));
       timer->start(5000);
       return;
    }
    else
    {
        argBuf[0]=arg1[0];
        argBuf[1]=arg1[1];
        argBuf[2]=arg1[2];
    }

   Red_SpinBox=argBuf;
   ALL_SpinBox=Red_SpinBox.append(Green_SpinBox).append(Blue_SpinBox);
   sendMessege(ALL_SpinBox);
}
void MainWindow::timeout()
{

}

void MainWindow::on_Green_lineEdit_textEdited(const QString &arg1)
{
    int argInt=arg1.toInt();
    QString argBuf=arg1;
    if(argInt<10)
    {
        argBuf[0]='0';
        argBuf[1]='0';
        argBuf[2]=arg1[0];
    }
    else if(10<=argInt&&argInt<100)
    {
        argBuf[0]='0';
        argBuf[1]=arg1[0];
        argBuf[2]=arg1[1];
    }
    else if(255<argInt||argInt<0)
    {
       QMessageBox *messageBox=new QMessageBox(QMessageBox::Information,"错误","请输入0~255的整数",QMessageBox::Close,this);
       messageBox->show();
       timer=new QTimer(this);
       connect(timer,SIGNAL(timeout()),messageBox,SLOT(close()));
       timer->start(5000);
       return;
    }
    else
    {
        argBuf[0]=arg1[0];
        argBuf[1]=arg1[1];
        argBuf[2]=arg1[2];
    }

   Green_SpinBox=argBuf;
   ALL_SpinBox=Red_SpinBox.append(Green_SpinBox).append(Blue_SpinBox);
   sendMessege(ALL_SpinBox);
}

void MainWindow::on_Blue_lineEdit_textEdited(const QString &arg1)
{
    int argInt=arg1.toInt();
    sleep(100);
    QString argBuf=arg1;
    if(argInt<10)
    {
        argBuf[0]='0';
        argBuf[1]='0';
        argBuf[2]=arg1[0];
    }
    else if(10<=argInt&&argInt<100)
    {
        argBuf[0]='0';
        argBuf[1]=arg1[0];
        argBuf[2]=arg1[1];
    }
    else if(255<argInt||argInt<0)
    {
       QMessageBox *messageBox=new QMessageBox(QMessageBox::Information,"错误","请输入0~255的整数",QMessageBox::Close,this);
       messageBox->show();
       timer=new QTimer(this);
       connect(timer,SIGNAL(timeout()),messageBox,SLOT(close()));
       timer->start(5000);
       return;
    }
    else
    {
        argBuf[0]=arg1[0];
        argBuf[1]=arg1[1];
        argBuf[2]=arg1[2];
    }

   Blue_SpinBox=argBuf;
   ALL_SpinBox=Red_SpinBox.append(Green_SpinBox).append(Blue_SpinBox);
   sendMessege(ALL_SpinBox);
}
