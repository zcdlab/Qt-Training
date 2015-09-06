/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionClearBytes;
    QAction *actionLoadfile;
    QAction *actionCleanPort;
    QAction *actionWriteToFile;
    QAction *actionMainMenu;
    QAction *actionProMenu;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *ProPage;
    QWidget *widget_2;
    QGroupBox *groupBox_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *ccradioButton;
    QRadioButton *chradioButton;
    QLCDNumber *recvbyteslcdNumber;
    QPushButton *clearUpBtn;
    QTextBrowser *textBrowser;
    QWidget *widget;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *sendAsHexcheckBox;
    QLineEdit *sendMsgLineEdit;
    QPushButton *sendmsgBtn;
    QWidget *MainWidget;
    QPushButton *TurnOff_pushButton;
    QLabel *label_10;
    QPushButton *Yellow_pushButton;
    QLabel *label_11;
    QPushButton *Purple_pushButton;
    QLabel *label_12;
    QPushButton *Orange_pushButton;
    QLabel *label_13;
    QPushButton *Cyan_pushButton;
    QLabel *label_14;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Lux_Label;
    QLCDNumber *Lux_lcdNumber;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Red_Label;
    QSlider *Red_horizontalSlider;
    QSpinBox *Red_spinBox;
    QLCDNumber *Red_lcdNumber;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Green_Label;
    QSlider *Green_horizontalSlider;
    QSpinBox *Green_spinBox;
    QLCDNumber *Green_lcdNumber;
    QHBoxLayout *horizontalLayout_9;
    QLabel *Blue_Label;
    QSlider *Blue_horizontalSlider;
    QSpinBox *Blue_spinBox;
    QLCDNumber *Blue_lcdNumber;
    QPushButton *Blue_pushButton;
    QPushButton *RED_pushButton;
    QPushButton *Green_pushButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *Temp_Label;
    QLCDNumber *Temp_lcdNumber;
    QLabel *Humidity_Label;
    QLCDNumber *Humidity_lcdNumber;
    QLabel *label_16;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *pushButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *qter;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *delayspinBox;
    QCheckBox *obocheckBox;
    QLabel *label_6;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *portNameComboBox;
    QLabel *label_2;
    QComboBox *baudRateComboBox;
    QLabel *label_3;
    QComboBox *dataBitsComboBox;
    QLabel *label_4;
    QComboBox *parityComboBox;
    QLabel *label_5;
    QComboBox *stopBitsComboBox;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(879, 580);
        MainWindow->setMinimumSize(QSize(820, 580));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setStyleSheet(QLatin1String("QDialog{background:rgb(229, 255, 239)}\n"
"QStatusBar{background:url(:/images/header.bmp)}\n"
"QPushButton{background:url(:/images/header.bmp)}\n"
"QLCDNumber{background:url(:/images/lcd.bmp)}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        MainWindow->setIconSize(QSize(16, 16));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->setAnimated(true);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionAdd->setCheckable(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/mesage.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon4);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon5);
        actionClearBytes = new QAction(MainWindow);
        actionClearBytes->setObjectName(QStringLiteral("actionClearBytes"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/clearbytes.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearBytes->setIcon(icon6);
        actionLoadfile = new QAction(MainWindow);
        actionLoadfile->setObjectName(QStringLiteral("actionLoadfile"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/loadfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadfile->setIcon(icon7);
        actionCleanPort = new QAction(MainWindow);
        actionCleanPort->setObjectName(QStringLiteral("actionCleanPort"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/cleanport.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCleanPort->setIcon(icon8);
        actionWriteToFile = new QAction(MainWindow);
        actionWriteToFile->setObjectName(QStringLiteral("actionWriteToFile"));
        actionWriteToFile->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/write2file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWriteToFile->setIcon(icon9);
        actionMainMenu = new QAction(MainWindow);
        actionMainMenu->setObjectName(QStringLiteral("actionMainMenu"));
        actionProMenu = new QAction(MainWindow);
        actionProMenu->setObjectName(QStringLiteral("actionProMenu"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(140, 0, 721, 391));
        stackedWidget->setMaximumSize(QSize(16777214, 16777215));
        stackedWidget->setLayoutDirection(Qt::LeftToRight);
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        ProPage = new QWidget();
        ProPage->setObjectName(QStringLiteral("ProPage"));
        ProPage->setToolTipDuration(1);
        widget_2 = new QWidget(ProPage);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 851, 641));
        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 10, 791, 511));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        groupBox_2->setFlat(true);
        frame_3 = new QFrame(groupBox_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(11, 27, 771, 51));
        frame_3->setStyleSheet(QStringLiteral(""));
        frame_3->setFrameShape(QFrame::WinPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(1);
        frame_3->setMidLineWidth(0);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ccradioButton = new QRadioButton(frame_3);
        ccradioButton->setObjectName(QStringLiteral("ccradioButton"));
        ccradioButton->setChecked(true);

        horizontalLayout->addWidget(ccradioButton);

        chradioButton = new QRadioButton(frame_3);
        chradioButton->setObjectName(QStringLiteral("chradioButton"));

        horizontalLayout->addWidget(chradioButton);

        recvbyteslcdNumber = new QLCDNumber(frame_3);
        recvbyteslcdNumber->setObjectName(QStringLiteral("recvbyteslcdNumber"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(recvbyteslcdNumber->sizePolicy().hasHeightForWidth());
        recvbyteslcdNumber->setSizePolicy(sizePolicy);
        recvbyteslcdNumber->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(recvbyteslcdNumber);

        clearUpBtn = new QPushButton(frame_3);
        clearUpBtn->setObjectName(QStringLiteral("clearUpBtn"));
        clearUpBtn->setMinimumSize(QSize(0, 23));
        clearUpBtn->setMaximumSize(QSize(100, 23));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearUpBtn->setIcon(icon10);

        horizontalLayout->addWidget(clearUpBtn);

        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(11, 83, 771, 421));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-20, 200, 851, 631));
        groupBox_4 = new QGroupBox(widget_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 520, 771, 131));
        groupBox_4->setStyleSheet(QStringLiteral(""));
        groupBox_4->setFlat(true);
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sendAsHexcheckBox = new QCheckBox(groupBox_4);
        sendAsHexcheckBox->setObjectName(QStringLiteral("sendAsHexcheckBox"));

        horizontalLayout_2->addWidget(sendAsHexcheckBox);

        sendMsgLineEdit = new QLineEdit(groupBox_4);
        sendMsgLineEdit->setObjectName(QStringLiteral("sendMsgLineEdit"));
        sendMsgLineEdit->setMaxLength(10000);
        sendMsgLineEdit->setDragEnabled(false);

        horizontalLayout_2->addWidget(sendMsgLineEdit);

        sendmsgBtn = new QPushButton(groupBox_4);
        sendmsgBtn->setObjectName(QStringLiteral("sendmsgBtn"));
        sendmsgBtn->setMinimumSize(QSize(0, 23));
        sendmsgBtn->setMaximumSize(QSize(100, 23));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendmsgBtn->setIcon(icon11);
        sendmsgBtn->setAutoDefault(false);
        sendmsgBtn->setDefault(false);

        horizontalLayout_2->addWidget(sendmsgBtn);

        stackedWidget->addWidget(ProPage);
        MainWidget = new QWidget();
        MainWidget->setObjectName(QStringLiteral("MainWidget"));
        TurnOff_pushButton = new QPushButton(MainWidget);
        TurnOff_pushButton->setObjectName(QStringLiteral("TurnOff_pushButton"));
        TurnOff_pushButton->setEnabled(true);
        TurnOff_pushButton->setGeometry(QRect(340, 20, 101, 21));
        QPalette palette;
        TurnOff_pushButton->setPalette(palette);
        TurnOff_pushButton->setAcceptDrops(false);
        TurnOff_pushButton->setAutoFillBackground(false);
        TurnOff_pushButton->setAutoDefault(false);
        TurnOff_pushButton->setFlat(false);
        label_10 = new QLabel(MainWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(290, 10, 51, 31));
        Yellow_pushButton = new QPushButton(MainWidget);
        Yellow_pushButton->setObjectName(QStringLiteral("Yellow_pushButton"));
        Yellow_pushButton->setEnabled(true);
        Yellow_pushButton->setGeometry(QRect(340, 200, 101, 31));
        QPalette palette1;
        Yellow_pushButton->setPalette(palette1);
        Yellow_pushButton->setAcceptDrops(false);
        Yellow_pushButton->setAutoFillBackground(false);
        Yellow_pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/images/color/Yellow.png);"));
        Yellow_pushButton->setAutoDefault(false);
        Yellow_pushButton->setFlat(false);
        label_11 = new QLabel(MainWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(290, 200, 51, 31));
        Purple_pushButton = new QPushButton(MainWidget);
        Purple_pushButton->setObjectName(QStringLiteral("Purple_pushButton"));
        Purple_pushButton->setEnabled(true);
        Purple_pushButton->setGeometry(QRect(340, 250, 101, 31));
        QPalette palette2;
        Purple_pushButton->setPalette(palette2);
        Purple_pushButton->setAcceptDrops(false);
        Purple_pushButton->setAutoFillBackground(false);
        Purple_pushButton->setStyleSheet(QLatin1String("\n"
"border-image: url(:/new/prefix1/images/color/Purple.png);\n"
""));
        Purple_pushButton->setAutoDefault(false);
        Purple_pushButton->setFlat(false);
        label_12 = new QLabel(MainWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(290, 250, 51, 31));
        Orange_pushButton = new QPushButton(MainWidget);
        Orange_pushButton->setObjectName(QStringLiteral("Orange_pushButton"));
        Orange_pushButton->setEnabled(true);
        Orange_pushButton->setGeometry(QRect(340, 300, 101, 31));
        QPalette palette3;
        Orange_pushButton->setPalette(palette3);
        Orange_pushButton->setAcceptDrops(false);
        Orange_pushButton->setAutoFillBackground(false);
        Orange_pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/images/color/Orange.png);"));
        Orange_pushButton->setAutoDefault(false);
        Orange_pushButton->setFlat(false);
        label_13 = new QLabel(MainWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(290, 300, 51, 31));
        Cyan_pushButton = new QPushButton(MainWidget);
        Cyan_pushButton->setObjectName(QStringLiteral("Cyan_pushButton"));
        Cyan_pushButton->setEnabled(true);
        Cyan_pushButton->setGeometry(QRect(340, 350, 101, 31));
        QPalette palette4;
        Cyan_pushButton->setPalette(palette4);
        Cyan_pushButton->setAcceptDrops(false);
        Cyan_pushButton->setAutoFillBackground(false);
        Cyan_pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/images/color/Cyan.png);"));
        Cyan_pushButton->setAutoDefault(false);
        Cyan_pushButton->setFlat(false);
        label_14 = new QLabel(MainWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(290, 350, 51, 31));
        layoutWidget = new QWidget(MainWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 261, 171));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        Lux_Label = new QLabel(layoutWidget);
        Lux_Label->setObjectName(QStringLiteral("Lux_Label"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Lux_Label->sizePolicy().hasHeightForWidth());
        Lux_Label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("MS UI Gothic"));
        font1.setUnderline(false);
        Lux_Label->setFont(font1);

        horizontalLayout_6->addWidget(Lux_Label);

        Lux_lcdNumber = new QLCDNumber(layoutWidget);
        Lux_lcdNumber->setObjectName(QStringLiteral("Lux_lcdNumber"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Lux_lcdNumber->sizePolicy().hasHeightForWidth());
        Lux_lcdNumber->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(Lux_lcdNumber);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        Red_Label = new QLabel(layoutWidget);
        Red_Label->setObjectName(QStringLiteral("Red_Label"));
        Red_Label->setFont(font1);
        Red_Label->setLayoutDirection(Qt::LeftToRight);
        Red_Label->setAutoFillBackground(false);
        Red_Label->setMargin(0);
        Red_Label->setIndent(0);

        horizontalLayout_7->addWidget(Red_Label);

        Red_horizontalSlider = new QSlider(layoutWidget);
        Red_horizontalSlider->setObjectName(QStringLiteral("Red_horizontalSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Red_horizontalSlider->sizePolicy().hasHeightForWidth());
        Red_horizontalSlider->setSizePolicy(sizePolicy3);
        Red_horizontalSlider->setMaximum(255);
        Red_horizontalSlider->setValue(0);
        Red_horizontalSlider->setTracking(true);
        Red_horizontalSlider->setOrientation(Qt::Horizontal);
        Red_horizontalSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_7->addWidget(Red_horizontalSlider);

        Red_spinBox = new QSpinBox(layoutWidget);
        Red_spinBox->setObjectName(QStringLiteral("Red_spinBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Red_spinBox->sizePolicy().hasHeightForWidth());
        Red_spinBox->setSizePolicy(sizePolicy4);
        Red_spinBox->setMaximum(255);

        horizontalLayout_7->addWidget(Red_spinBox);

        Red_lcdNumber = new QLCDNumber(layoutWidget);
        Red_lcdNumber->setObjectName(QStringLiteral("Red_lcdNumber"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Red_lcdNumber->sizePolicy().hasHeightForWidth());
        Red_lcdNumber->setSizePolicy(sizePolicy5);

        horizontalLayout_7->addWidget(Red_lcdNumber);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        Green_Label = new QLabel(layoutWidget);
        Green_Label->setObjectName(QStringLiteral("Green_Label"));
        Green_Label->setFont(font1);
        Green_Label->setIndent(0);

        horizontalLayout_8->addWidget(Green_Label);

        Green_horizontalSlider = new QSlider(layoutWidget);
        Green_horizontalSlider->setObjectName(QStringLiteral("Green_horizontalSlider"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(Green_horizontalSlider->sizePolicy().hasHeightForWidth());
        Green_horizontalSlider->setSizePolicy(sizePolicy6);
        Green_horizontalSlider->setMaximum(255);
        Green_horizontalSlider->setOrientation(Qt::Horizontal);
        Green_horizontalSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_8->addWidget(Green_horizontalSlider);

        Green_spinBox = new QSpinBox(layoutWidget);
        Green_spinBox->setObjectName(QStringLiteral("Green_spinBox"));
        sizePolicy4.setHeightForWidth(Green_spinBox->sizePolicy().hasHeightForWidth());
        Green_spinBox->setSizePolicy(sizePolicy4);
        Green_spinBox->setMinimumSize(QSize(0, 0));
        Green_spinBox->setMaximum(255);

        horizontalLayout_8->addWidget(Green_spinBox);

        Green_lcdNumber = new QLCDNumber(layoutWidget);
        Green_lcdNumber->setObjectName(QStringLiteral("Green_lcdNumber"));
        sizePolicy2.setHeightForWidth(Green_lcdNumber->sizePolicy().hasHeightForWidth());
        Green_lcdNumber->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(Green_lcdNumber);


        gridLayout->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        Blue_Label = new QLabel(layoutWidget);
        Blue_Label->setObjectName(QStringLiteral("Blue_Label"));
        Blue_Label->setFont(font1);
        Blue_Label->setIndent(0);

        horizontalLayout_9->addWidget(Blue_Label);

        Blue_horizontalSlider = new QSlider(layoutWidget);
        Blue_horizontalSlider->setObjectName(QStringLiteral("Blue_horizontalSlider"));
        sizePolicy6.setHeightForWidth(Blue_horizontalSlider->sizePolicy().hasHeightForWidth());
        Blue_horizontalSlider->setSizePolicy(sizePolicy6);
        Blue_horizontalSlider->setMaximum(255);
        Blue_horizontalSlider->setOrientation(Qt::Horizontal);
        Blue_horizontalSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_9->addWidget(Blue_horizontalSlider);

        Blue_spinBox = new QSpinBox(layoutWidget);
        Blue_spinBox->setObjectName(QStringLiteral("Blue_spinBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(Blue_spinBox->sizePolicy().hasHeightForWidth());
        Blue_spinBox->setSizePolicy(sizePolicy7);
        Blue_spinBox->setMaximum(255);

        horizontalLayout_9->addWidget(Blue_spinBox);

        Blue_lcdNumber = new QLCDNumber(layoutWidget);
        Blue_lcdNumber->setObjectName(QStringLiteral("Blue_lcdNumber"));
        sizePolicy2.setHeightForWidth(Blue_lcdNumber->sizePolicy().hasHeightForWidth());
        Blue_lcdNumber->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(Blue_lcdNumber);


        gridLayout->addLayout(horizontalLayout_9, 3, 0, 1, 1);

        Blue_pushButton = new QPushButton(MainWidget);
        Blue_pushButton->setObjectName(QStringLiteral("Blue_pushButton"));
        Blue_pushButton->setEnabled(true);
        Blue_pushButton->setGeometry(QRect(341, 153, 101, 31));
        sizePolicy2.setHeightForWidth(Blue_pushButton->sizePolicy().hasHeightForWidth());
        Blue_pushButton->setSizePolicy(sizePolicy2);
        QPalette palette5;
        Blue_pushButton->setPalette(palette5);
        Blue_pushButton->setAcceptDrops(false);
        Blue_pushButton->setAutoFillBackground(false);
        Blue_pushButton->setStyleSheet(QLatin1String("\n"
"border-image: url(:/new/prefix1/images/color/Blue.png);\n"
""));
        Blue_pushButton->setAutoDefault(false);
        Blue_pushButton->setFlat(false);
        RED_pushButton = new QPushButton(MainWidget);
        RED_pushButton->setObjectName(QStringLiteral("RED_pushButton"));
        RED_pushButton->setEnabled(true);
        RED_pushButton->setGeometry(QRect(341, 62, 101, 31));
        sizePolicy2.setHeightForWidth(RED_pushButton->sizePolicy().hasHeightForWidth());
        RED_pushButton->setSizePolicy(sizePolicy2);
        QPalette palette6;
        RED_pushButton->setPalette(palette6);
        RED_pushButton->setAcceptDrops(false);
        RED_pushButton->setAutoFillBackground(false);
        RED_pushButton->setStyleSheet(QLatin1String("\n"
"border-image: url(:/new/prefix1/images/color/RED.png);\n"
""));
        RED_pushButton->setAutoDefault(false);
        RED_pushButton->setFlat(false);
        Green_pushButton = new QPushButton(MainWidget);
        Green_pushButton->setObjectName(QStringLiteral("Green_pushButton"));
        Green_pushButton->setEnabled(true);
        Green_pushButton->setGeometry(QRect(341, 107, 101, 31));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(Green_pushButton->sizePolicy().hasHeightForWidth());
        Green_pushButton->setSizePolicy(sizePolicy8);
        QPalette palette7;
        Green_pushButton->setPalette(palette7);
        Green_pushButton->setAcceptDrops(false);
        Green_pushButton->setAutoFillBackground(false);
        Green_pushButton->setStyleSheet(QLatin1String("\n"
"border-image: url(:/new/prefix1/images/color/Green.png);\n"
""));
        Green_pushButton->setAutoDefault(false);
        Green_pushButton->setFlat(false);
        layoutWidget1 = new QWidget(MainWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(490, 10, 201, 101));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Temp_Label = new QLabel(layoutWidget1);
        Temp_Label->setObjectName(QStringLiteral("Temp_Label"));
        sizePolicy1.setHeightForWidth(Temp_Label->sizePolicy().hasHeightForWidth());
        Temp_Label->setSizePolicy(sizePolicy1);
        Temp_Label->setFont(font1);

        gridLayout_2->addWidget(Temp_Label, 0, 0, 1, 1);

        Temp_lcdNumber = new QLCDNumber(layoutWidget1);
        Temp_lcdNumber->setObjectName(QStringLiteral("Temp_lcdNumber"));
        sizePolicy2.setHeightForWidth(Temp_lcdNumber->sizePolicy().hasHeightForWidth());
        Temp_lcdNumber->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Temp_lcdNumber, 0, 1, 1, 1);

        Humidity_Label = new QLabel(layoutWidget1);
        Humidity_Label->setObjectName(QStringLiteral("Humidity_Label"));
        sizePolicy1.setHeightForWidth(Humidity_Label->sizePolicy().hasHeightForWidth());
        Humidity_Label->setSizePolicy(sizePolicy1);
        Humidity_Label->setFont(font1);

        gridLayout_2->addWidget(Humidity_Label, 1, 0, 1, 1);

        Humidity_lcdNumber = new QLCDNumber(layoutWidget1);
        Humidity_lcdNumber->setObjectName(QStringLiteral("Humidity_lcdNumber"));
        sizePolicy2.setHeightForWidth(Humidity_lcdNumber->sizePolicy().hasHeightForWidth());
        Humidity_lcdNumber->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(Humidity_lcdNumber, 1, 1, 1, 1);

        label_16 = new QLabel(MainWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(290, 150, 51, 31));
        label_18 = new QLabel(MainWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(290, 110, 51, 31));
        label_19 = new QLabel(MainWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(290, 60, 51, 31));
        pushButton = new QPushButton(MainWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 190, 141, 20));
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy9);
        QFont font2;
        font2.setKerning(true);
        pushButton->setFont(font2);
        pushButton->setContextMenuPolicy(Qt::PreventContextMenu);
        pushButton->setIconSize(QSize(32, 30));
        pushButton->setAutoDefault(false);
        pushButton->setDefault(false);
        pushButton->setFlat(false);
        stackedWidget->addWidget(MainWidget);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(-120, 470, 1161, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(255, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        qter = new QLabel(layoutWidget4);
        qter->setObjectName(QStringLiteral("qter"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(qter->sizePolicy().hasHeightForWidth());
        qter->setSizePolicy(sizePolicy10);
        qter->setOpenExternalLinks(true);

        horizontalLayout_3->addWidget(qter);

        horizontalSpacer_2 = new QSpacerItem(255, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        delayspinBox = new QSpinBox(centralWidget);
        delayspinBox->setObjectName(QStringLiteral("delayspinBox"));
        delayspinBox->setGeometry(QRect(10, 420, 79, 20));
        delayspinBox->setMinimum(10);
        delayspinBox->setMaximum(5000);
        delayspinBox->setValue(200);
        obocheckBox = new QCheckBox(centralWidget);
        obocheckBox->setObjectName(QStringLiteral("obocheckBox"));
        obocheckBox->setGeometry(QRect(10, 370, 79, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 397, 79, 16));
        sizePolicy10.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy10);
        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 10, 122, 350));
        verticalLayout_2 = new QVBoxLayout(layoutWidget5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setFlat(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy10.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy10);

        verticalLayout->addWidget(label);

        portNameComboBox = new QComboBox(groupBox);
        portNameComboBox->setObjectName(QStringLiteral("portNameComboBox"));

        verticalLayout->addWidget(portNameComboBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy10.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy10);

        verticalLayout->addWidget(label_2);

        baudRateComboBox = new QComboBox(groupBox);
        baudRateComboBox->setObjectName(QStringLiteral("baudRateComboBox"));

        verticalLayout->addWidget(baudRateComboBox);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy10.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy10);

        verticalLayout->addWidget(label_3);

        dataBitsComboBox = new QComboBox(groupBox);
        dataBitsComboBox->setObjectName(QStringLiteral("dataBitsComboBox"));

        verticalLayout->addWidget(dataBitsComboBox);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy10.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy10);

        verticalLayout->addWidget(label_4);

        parityComboBox = new QComboBox(groupBox);
        parityComboBox->setObjectName(QStringLiteral("parityComboBox"));

        verticalLayout->addWidget(parityComboBox);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy10.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy10);

        verticalLayout->addWidget(label_5);

        stopBitsComboBox = new QComboBox(groupBox);
        stopBitsComboBox->setObjectName(QStringLiteral("stopBitsComboBox"));

        verticalLayout->addWidget(stopBitsComboBox);


        verticalLayout_2->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        stackedWidget->raise();
        delayspinBox->raise();
        obocheckBox->raise();
        label_6->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        sizePolicy10.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy10);
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setMaximumSize(QSize(16777215, 55));
        QFont font3;
        font3.setPointSize(9);
        mainToolBar->setFont(font3);
        mainToolBar->setCursor(QCursor(Qt::PointingHandCursor));
        mainToolBar->setFocusPolicy(Qt::StrongFocus);
        mainToolBar->setContextMenuPolicy(Qt::NoContextMenu);
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::NoToolBarArea);
        mainToolBar->setIconSize(QSize(20, 20));
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionClose);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionLoadfile);
        mainToolBar->addAction(actionWriteToFile);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionClearBytes);
        mainToolBar->addAction(actionCleanPort);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        baudRateComboBox->setCurrentIndex(12);
        dataBitsComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QCom\344\270\262\345\217\243\350\260\203\350\257\225\345\212\251\346\211\213 1.0", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243\350\256\276\345\244\207\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionAdd->setStatusTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243\350\256\276\345\244\207\346\226\207\344\273\266", 0));
#endif // QT_NO_STATUSTIP
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
#endif // QT_NO_STATUSTIP
        actionClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
#ifndef QT_NO_STATUSTIP
        actionClose->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
#endif // QT_NO_STATUSTIP
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#ifndef QT_NO_STATUSTIP
        actionExit->setStatusTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#endif // QT_NO_STATUSTIP
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Wincom", 0));
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216Wincom", 0));
#endif // QT_NO_STATUSTIP
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\224\266\345\217\221\346\241\206\345\206\205\347\232\204\346\225\260\346\215\256", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\224\266\345\217\221\346\241\206\345\206\205\347\232\204\346\225\260\346\215\256", 0));
#endif // QT_NO_STATUSTIP
        actionClearBytes->setText(QApplication::translate("MainWindow", "\350\256\241\346\225\260\346\270\205\351\233\266", 0));
#ifndef QT_NO_TOOLTIP
        actionClearBytes->setToolTip(QApplication::translate("MainWindow", "\346\270\205\351\233\266\345\267\262\346\224\266\345\210\260\347\232\204\345\255\227\350\212\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionClearBytes->setStatusTip(QApplication::translate("MainWindow", "\346\270\205\351\233\266\345\267\262\346\224\266\345\210\260\347\232\204\345\255\227\350\212\202\346\225\260", 0));
#endif // QT_NO_STATUSTIP
        actionLoadfile->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        actionLoadfile->setToolTip(QApplication::translate("MainWindow", "\350\275\275\345\205\245\345\244\226\351\203\250\346\226\207\344\273\266\344\275\234\344\270\272\345\217\221\351\200\201\345\206\205\345\256\271", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionLoadfile->setStatusTip(QApplication::translate("MainWindow", "\350\275\275\345\205\245\345\244\226\351\203\250\346\226\207\344\273\266\344\275\234\344\270\272\345\217\221\351\200\201\345\206\205\345\256\271", 0));
#endif // QT_NO_STATUSTIP
        actionCleanPort->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        actionCleanPort->setToolTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243\344\270\255I/O\346\225\260\346\215\256", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCleanPort->setStatusTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243\344\270\255I/O\346\225\260\346\215\256", 0));
#endif // QT_NO_STATUSTIP
        actionWriteToFile->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        actionWriteToFile->setToolTip(QApplication::translate("MainWindow", "\345\260\206\350\257\273\345\217\226\346\225\260\346\215\256\345\206\231\345\205\245\345\210\260\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionWriteToFile->setStatusTip(QApplication::translate("MainWindow", "\345\260\206\350\257\273\345\217\226\346\225\260\346\215\256\345\206\231\345\205\245\345\210\260\346\226\207\344\273\266", 0));
#endif // QT_NO_STATUSTIP
        actionMainMenu->setText(QApplication::translate("MainWindow", "GUI\346\216\247\345\210\266\347\225\214\351\235\242", 0));
        actionProMenu->setText(QApplication::translate("MainWindow", "\350\260\203\350\257\225\347\225\214\351\235\242", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256", 0));
#ifndef QT_NO_TOOLTIP
        ccradioButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\273\245\345\255\227\347\254\246\346\226\271\345\274\217\346\230\276\347\244\272\346\225\260\346\215\256</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        ccradioButton->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\345\275\242\345\274\217\346\230\276\347\244\272", 0));
#ifndef QT_NO_TOOLTIP
        chradioButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\273\245\345\215\201\345\205\255\350\277\233\345\210\266\346\226\271\345\274\217\346\230\276\347\244\272\346\225\260\346\215\256</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        chradioButton->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\275\242\345\274\217\346\230\276\347\244\272", 0));
#ifndef QT_NO_TOOLTIP
        recvbyteslcdNumber->setToolTip(QApplication::translate("MainWindow", "\345\267\262\346\216\245\346\224\266\345\255\227\350\212\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        clearUpBtn->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\230\276\347\244\272", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
#ifndef QT_NO_TOOLTIP
        sendAsHexcheckBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\273\245\345\215\201\345\205\255\350\277\233\345\210\266\346\226\271\345\274\217\345\217\221\351\200\201\346\225\260\346\215\256\357\274\210\351\273\230\350\256\244\344\270\272\345\255\227\347\254\246\346\226\271\345\274\217\357\274\211</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sendAsHexcheckBox->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", 0));
        sendmsgBtn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        TurnOff_pushButton->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\201\255\347\201\257</span></p></body></html>", 0));
        Yellow_pushButton->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\351\273\204\350\211\262</span></p></body></html>", 0));
        Purple_pushButton->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\264\253\350\211\262</span></p></body></html>", 0));
        Orange_pushButton->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\251\231\350\211\262</span></p></body></html>", 0));
        Cyan_pushButton->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\351\235\233\350\211\262</span></p></body></html>", 0));
        Lux_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\345\205\211\345\274\272</span><span style=\" font-size:12pt; font-weight:600; vertical-align:super;\">Lux:</span></p></body></html>", 0));
        Red_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">R\357\274\232</span></p></body></html>", 0));
        Green_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">G\357\274\232</span></p></body></html>", 0));
        Blue_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">B\357\274\232</span></p></body></html>", 0));
        Blue_pushButton->setText(QString());
        RED_pushButton->setText(QString());
        Green_pushButton->setText(QString());
        Temp_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\270\251\345\272\246\342\204\203:</span></p></body></html>", 0));
        Humidity_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\346\271\277\345\272\246</span><span style=\" font-size:12pt; font-weight:600; vertical-align:super;\">\357\274\205</span><span style=\" font-size:12pt; font-weight:600;\">:</span></p></body></html>", 0));
        label_16->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\350\223\235\350\211\262</span></p></body></html>", 0));
        label_18->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\273\277\350\211\262</span></p></body></html>", 0));
        label_19->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\347\272\242\350\211\262</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", 0));
#ifndef QT_NO_TOOLTIP
        qter->setToolTip(QApplication::translate("MainWindow", "\346\254\242\350\277\216\350\256\277\351\227\256\346\210\221\344\273\254\347\232\204\347\275\221\347\253\231", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        qter->setStatusTip(QApplication::translate("MainWindow", "\346\254\242\350\277\216\350\256\277\351\227\256\346\210\221\344\273\254\347\232\204\347\275\221\347\253\231", 0));
#endif // QT_NO_STATUSTIP
        qter->setText(QApplication::translate("MainWindow", "TCM", 0));
        obocheckBox->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\345\217\221\351\200\201", 0));
        label_6->setText(QApplication::translate("MainWindow", "\351\227\264\351\232\224(\346\257\253\347\247\222)", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", 0));
        baudRateComboBox->clear();
        baudRateComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "50", 0)
         << QApplication::translate("MainWindow", "75", 0)
         << QApplication::translate("MainWindow", "110", 0)
         << QApplication::translate("MainWindow", "134", 0)
         << QApplication::translate("MainWindow", "150", 0)
         << QApplication::translate("MainWindow", "200", 0)
         << QApplication::translate("MainWindow", "300", 0)
         << QApplication::translate("MainWindow", "600", 0)
         << QApplication::translate("MainWindow", "1200", 0)
         << QApplication::translate("MainWindow", "1800", 0)
         << QApplication::translate("MainWindow", "2400", 0)
         << QApplication::translate("MainWindow", "4800", 0)
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "14400", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
         << QApplication::translate("MainWindow", "56000", 0)
         << QApplication::translate("MainWindow", "57600", 0)
         << QApplication::translate("MainWindow", "76800", 0)
         << QApplication::translate("MainWindow", "115200", 0)
         << QApplication::translate("MainWindow", "128000", 0)
         << QApplication::translate("MainWindow", "256000", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", 0));
        dataBitsComboBox->clear();
        dataBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", 0));
        parityComboBox->clear();
        parityComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\227\240", 0)
         << QApplication::translate("MainWindow", "\345\245\207", 0)
         << QApplication::translate("MainWindow", "\345\201\266", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", 0));
        stopBitsComboBox->clear();
        stopBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "1.5", 0)
         << QApplication::translate("MainWindow", "2", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
