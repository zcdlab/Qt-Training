#include <QtWidgets>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    ui->horizontalSlider->setRange(0, 0);
    ui->tableWidget->hide();
    ui->tableWidget->hideColumn(2);
    volume=80;

    createContextMenu();
    createSystemTrayIcon();

    playList=new QMediaPlaylist;
    playList->setPlaybackMode(QMediaPlaylist::Loop);
    player=new QMediaPlayer;
    player->setPlaylist(playList);
    player->setVolume(volume);

    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(setPosition(int)));
    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(playTo(int, int)));

    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
    connect(playList, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSongList(int)));

    connect(ui->action_SongList, SIGNAL(triggered()), this, SLOT(showOrHideSongList()));
    connect(ui->action_Import, SIGNAL(triggered()), this, SLOT(importSongs()));
    connect(ui->action_Last, SIGNAL(triggered()), this, SLOT(playLast()));
    connect(ui->action_Play, SIGNAL(triggered()), this, SLOT(playOrPause()));
    connect(ui->action_Stop, SIGNAL(triggered()), player, SLOT(stop()));
    connect(ui->action_Next, SIGNAL(triggered()), this, SLOT(playNext()));
    connect(ui->action_SoundPlus, SIGNAL(triggered()), this, SLOT(plusSound()));
    connect(ui->action_SoundReduce, SIGNAL(triggered()), this, SLOT(reduceSound()));
    connect(ui->action_Mode1, SIGNAL(triggered()), this, SLOT(setPlaybackMode1()));
    connect(ui->action_Mode2, SIGNAL(triggered()), this, SLOT(setPlaybackMode2()));
    connect(ui->action_Mode3, SIGNAL(triggered()), this, SLOT(setPlaybackMode3()));
    connect(ui->action_Mode4, SIGNAL(triggered()), this, SLOT(setPlaybackMode4()));
    connect(ui->action_Support, SIGNAL(triggered()), this, SLOT(support()));
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(aboutUs()));
    connect(ui->action_Quit, SIGNAL(triggered()), this, SLOT(close()));

    connect(ui->toolButton_Last, SIGNAL(clicked()), this, SLOT(playLast()));
    connect(ui->toolButton_Play, SIGNAL(clicked()), this, SLOT(playOrPause()));
    connect(ui->toolButton_Stop, SIGNAL(clicked()), player, SLOT(stop()));
    connect(ui->toolButton_Next, SIGNAL(clicked()), this, SLOT(playNext()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createContextMenu()
{
    seperatorAction1=new QAction(this);
    seperatorAction1->setSeparator(true);
    seperatorAction2=new QAction(this);
    seperatorAction2->setSeparator(true);
    seperatorAction3=new QAction(this);
    seperatorAction3->setSeparator(true);
    seperatorAction4=new QAction(this);
    seperatorAction4->setSeparator(true);
    seperatorAction5=new QAction(this);
    seperatorAction5->setSeparator(true);

    addAction(ui->action_SongList);
    addAction(ui->action_Import);
    addAction(seperatorAction1);
    addAction(ui->action_Last);
    addAction(ui->action_Play);
    addAction(ui->action_Stop);
    addAction(ui->action_Next);
    addAction(seperatorAction2);
    addAction(ui->action_Mode1);
    addAction(ui->action_Mode2);
    addAction(ui->action_Mode3);
    addAction(ui->action_Mode4);
    addAction(seperatorAction3);
    addAction(ui->action_SoundPlus);
    addAction(ui->action_SoundReduce);
    addAction(seperatorAction4);
    addAction(ui->action_Support);
    addAction(ui->action_About);
    addAction(seperatorAction5);
    addAction(ui->action_Quit);
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createSystemTrayIcon()
{
    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(tr(":/new/background/images/icon.ico")));
    trayIcon->setToolTip(tr("酷音听听 - 音乐播放器"));

    restoreAction=new QAction(tr("打开主面板"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(show()));

    quitAction=new QAction(tr("退出"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    trayContextMenu=new QMenu(this);
    trayContextMenu->addAction(ui->action_SongList);
    trayContextMenu->addAction(ui->action_Import);
    trayContextMenu->addSeparator();
    trayContextMenu->addAction(ui->action_Last);
    trayContextMenu->addAction(ui->action_Play);
    trayContextMenu->addAction(ui->action_Stop);
    trayContextMenu->addAction(ui->action_Next);
    trayContextMenu->addSeparator();
    trayContextMenu->addAction(ui->action_Mode1);
    trayContextMenu->addAction(ui->action_Mode2);
    trayContextMenu->addAction(ui->action_Mode3);
    trayContextMenu->addAction(ui->action_Mode4);
    trayContextMenu->addSeparator();
    trayContextMenu->addAction(ui->action_SoundPlus);
    trayContextMenu->addAction(ui->action_SoundReduce);
    trayContextMenu->addSeparator();
    trayContextMenu->addAction(ui->action_Support);
    trayContextMenu->addAction(ui->action_About);
    trayContextMenu->addSeparator();
    trayContextMenu->addAction(restoreAction);
    trayContextMenu->addAction(quitAction);
    trayIcon->setContextMenu(trayContextMenu);

    trayIcon->show();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), \
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason) {
    case QSystemTrayIcon::DoubleClick:
    case QSystemTrayIcon::Trigger:
        if(this->isVisible()==true) {
            ;
        } else {
            this->show();
            this->activateWindow();
        }
        break;
    default:
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(trayIcon->isVisible()) {
        hide();
        trayIcon->showMessage(tr("提示"), tr("酷音听听将在后台运行"));
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton) {
        dragPos=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton) {
        move(event->globalPos()-dragPos);
        event->accept();
    }
}

void MainWindow::positionChanged(qint64 position)
{
    ui->horizontalSlider->setValue(position);
}

void MainWindow::durationChanged(qint64 duration)
{
    ui->horizontalSlider->setRange(0, duration);
}

void MainWindow::updateSongList(int i)
{
    ui->tableWidget->selectRow(i);
    ui->label->setText(tr("正在播放: %1").arg(ui->tableWidget->item(i, 0)->text()));
}

void MainWindow::showOrHideSongList()
{
    if(ui->tableWidget->isHidden()) {
        ui->tableWidget->show();
    } else {
        ui->tableWidget->hide();
    }
}

void MainWindow::playTo(int i, int /* j */)
{
    playList->setCurrentIndex(i);
    player->play();
}

void MainWindow::importSongs()
{
    QString initialName=QDir::homePath();
    QStringList pathList=QFileDialog::getOpenFileNames(this, tr("选择文件"), initialName, tr(".mp3"));
    for(int i=0; i<pathList.size(); ++i) {
        QString path=QDir::toNativeSeparators(pathList.at(i));
        if(!path.isEmpty()) {
            playList->addMedia(QUrl::fromLocalFile(path));
            QString fileName=path.split("\\").last();
            int rownum=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rownum);
            ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName.split(".").front()));
            ui->tableWidget->setItem(rownum, 1, new QTableWidgetItem(fileName.split(".").last()));
            ui->tableWidget->setItem(rownum, 2, new QTableWidgetItem(path));
        }
    }
}

void MainWindow::playLast()
{
    int currentIndex=playList->currentIndex();
    if(--currentIndex<0) currentIndex=0;
    playList->setCurrentIndex(currentIndex);
    player->play();
}

void MainWindow::playOrPause()
{
    if(ui->toolButton_Play->text()==tr("播放")) {
        player->play();
        ui->toolButton_Play->setText(tr("暂停"));
    } else {
        player->pause();
        ui->toolButton_Play->setText(tr("播放"));
    }
}

void MainWindow::playNext()
{
    int currentIndex=playList->currentIndex();
    if(++currentIndex==playList->mediaCount()) currentIndex=0;
    playList->setCurrentIndex(currentIndex);
    player->play();
}

void MainWindow::plusSound()
{
    volume+=20;
    if(volume>=100) {
        volume=100;
        ui->action_SoundPlus->setEnabled(false);
    }
    player->setVolume(volume);

    if(!ui->action_SoundReduce->isEnabled())
        ui->action_SoundReduce->setEnabled(true);
}

void MainWindow::reduceSound()
{
    volume-=20;
    if(volume<=0) {
        volume=0;
        ui->action_SoundReduce->setEnabled(false);
    }
    player->setVolume(volume);

    if(!ui->action_SoundPlus->isEnabled())
        ui->action_SoundPlus->setEnabled(true);
}

void MainWindow::setPosition(int position)
{
    player->setPosition(position);
}

void MainWindow::setPlaybackMode1()
{
    playList->setPlaybackMode(QMediaPlaylist::Loop);
}

void MainWindow::setPlaybackMode2()
{
    playList->setPlaybackMode(QMediaPlaylist::Random);
}

void MainWindow::setPlaybackMode3()
{
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}

void MainWindow::setPlaybackMode4()
{
    playList->setPlaybackMode(QMediaPlaylist::Sequential);
}

void MainWindow::support()
{
    QMessageBox::about(this, tr("关于酷音听听"), \
                       tr("酷音听听，感谢您的使用！"));
}

void MainWindow::aboutUs()
{
    const QUrl url("http://blog.sina.com.cn/terrynotes");
    QDesktopServices::openUrl(url);
}
