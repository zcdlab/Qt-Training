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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newPicture;
    QAction *openPicture;
    QAction *drawHistogram;
    QAction *reSize;
    QAction *actionGaussian_filter;
    QAction *actionMean_filter;
    QAction *actionMedian_filter;
    QAction *actionManual;
    QAction *actionOtsu;
    QAction *actionEntropy;
    QAction *matrixBySelf;
    QAction *action_vertex;
    QAction *action_add;
    QAction *action_minus;
    QAction *action_multiply;
    QAction *action_openPicture2;
    QAction *Roberts_x;
    QAction *Roberts_y;
    QAction *prewitt_x;
    QAction *prewitt_y;
    QAction *sobel_x;
    QAction *sobel_y;
    QAction *Roberts_RGB_x;
    QAction *Roberts_RGB_y;
    QAction *prewitt_RGB_x;
    QAction *prewitt_RGB_y;
    QAction *sobel_RGB_x;
    QAction *sobel_RGB_y;
    QAction *actionTest;
    QAction *clockwise;
    QAction *anticlockwise;
    QAction *grayDilation;
    QAction *binaryDilation;
    QAction *grayErosion;
    QAction *binaryErosion;
    QAction *grayOpen;
    QAction *binaryOpen;
    QAction *grayClose;
    QAction *binaryClose;
    QWidget *centralWidget;
    QScrollArea *oldScrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *picture1;
    QScrollArea *newScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *picture2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *makeDone;
    QLabel *label_4;
    QLabel *theThreshold;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menuAutomatic;
    QMenu *menu_3;
    QMenu *menuRoberts_operator;
    QMenu *menuPrewitt_operator;
    QMenu *menuSobel_operator;
    QMenu *menu_5;
    QMenu *menu_6;
    QMenu *menu_7;
    QMenu *menu_8;
    QMenu *menu_9;
    QMenu *menu_10;
    QMenu *menu_12;
    QMenu *menu_11;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1080, 720);
        newPicture = new QAction(MainWindow);
        newPicture->setObjectName(QStringLiteral("newPicture"));
        openPicture = new QAction(MainWindow);
        openPicture->setObjectName(QStringLiteral("openPicture"));
        drawHistogram = new QAction(MainWindow);
        drawHistogram->setObjectName(QStringLiteral("drawHistogram"));
        reSize = new QAction(MainWindow);
        reSize->setObjectName(QStringLiteral("reSize"));
        actionGaussian_filter = new QAction(MainWindow);
        actionGaussian_filter->setObjectName(QStringLiteral("actionGaussian_filter"));
        actionMean_filter = new QAction(MainWindow);
        actionMean_filter->setObjectName(QStringLiteral("actionMean_filter"));
        actionMedian_filter = new QAction(MainWindow);
        actionMedian_filter->setObjectName(QStringLiteral("actionMedian_filter"));
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        actionOtsu = new QAction(MainWindow);
        actionOtsu->setObjectName(QStringLiteral("actionOtsu"));
        actionEntropy = new QAction(MainWindow);
        actionEntropy->setObjectName(QStringLiteral("actionEntropy"));
        matrixBySelf = new QAction(MainWindow);
        matrixBySelf->setObjectName(QStringLiteral("matrixBySelf"));
        action_vertex = new QAction(MainWindow);
        action_vertex->setObjectName(QStringLiteral("action_vertex"));
        action_add = new QAction(MainWindow);
        action_add->setObjectName(QStringLiteral("action_add"));
        action_minus = new QAction(MainWindow);
        action_minus->setObjectName(QStringLiteral("action_minus"));
        action_multiply = new QAction(MainWindow);
        action_multiply->setObjectName(QStringLiteral("action_multiply"));
        action_openPicture2 = new QAction(MainWindow);
        action_openPicture2->setObjectName(QStringLiteral("action_openPicture2"));
        Roberts_x = new QAction(MainWindow);
        Roberts_x->setObjectName(QStringLiteral("Roberts_x"));
        Roberts_y = new QAction(MainWindow);
        Roberts_y->setObjectName(QStringLiteral("Roberts_y"));
        prewitt_x = new QAction(MainWindow);
        prewitt_x->setObjectName(QStringLiteral("prewitt_x"));
        prewitt_y = new QAction(MainWindow);
        prewitt_y->setObjectName(QStringLiteral("prewitt_y"));
        sobel_x = new QAction(MainWindow);
        sobel_x->setObjectName(QStringLiteral("sobel_x"));
        sobel_y = new QAction(MainWindow);
        sobel_y->setObjectName(QStringLiteral("sobel_y"));
        Roberts_RGB_x = new QAction(MainWindow);
        Roberts_RGB_x->setObjectName(QStringLiteral("Roberts_RGB_x"));
        Roberts_RGB_y = new QAction(MainWindow);
        Roberts_RGB_y->setObjectName(QStringLiteral("Roberts_RGB_y"));
        prewitt_RGB_x = new QAction(MainWindow);
        prewitt_RGB_x->setObjectName(QStringLiteral("prewitt_RGB_x"));
        prewitt_RGB_y = new QAction(MainWindow);
        prewitt_RGB_y->setObjectName(QStringLiteral("prewitt_RGB_y"));
        sobel_RGB_x = new QAction(MainWindow);
        sobel_RGB_x->setObjectName(QStringLiteral("sobel_RGB_x"));
        sobel_RGB_y = new QAction(MainWindow);
        sobel_RGB_y->setObjectName(QStringLiteral("sobel_RGB_y"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        clockwise = new QAction(MainWindow);
        clockwise->setObjectName(QStringLiteral("clockwise"));
        anticlockwise = new QAction(MainWindow);
        anticlockwise->setObjectName(QStringLiteral("anticlockwise"));
        grayDilation = new QAction(MainWindow);
        grayDilation->setObjectName(QStringLiteral("grayDilation"));
        binaryDilation = new QAction(MainWindow);
        binaryDilation->setObjectName(QStringLiteral("binaryDilation"));
        grayErosion = new QAction(MainWindow);
        grayErosion->setObjectName(QStringLiteral("grayErosion"));
        binaryErosion = new QAction(MainWindow);
        binaryErosion->setObjectName(QStringLiteral("binaryErosion"));
        grayOpen = new QAction(MainWindow);
        grayOpen->setObjectName(QStringLiteral("grayOpen"));
        binaryOpen = new QAction(MainWindow);
        binaryOpen->setObjectName(QStringLiteral("binaryOpen"));
        grayClose = new QAction(MainWindow);
        grayClose->setObjectName(QStringLiteral("grayClose"));
        binaryClose = new QAction(MainWindow);
        binaryClose->setObjectName(QStringLiteral("binaryClose"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        oldScrollArea = new QScrollArea(centralWidget);
        oldScrollArea->setObjectName(QStringLiteral("oldScrollArea"));
        oldScrollArea->setGeometry(QRect(20, 40, 500, 500));
        oldScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 498, 498));
        picture1 = new QLabel(scrollAreaWidgetContents);
        picture1->setObjectName(QStringLiteral("picture1"));
        picture1->setGeometry(QRect(250, 250, 1, 1));
        oldScrollArea->setWidget(scrollAreaWidgetContents);
        newScrollArea = new QScrollArea(centralWidget);
        newScrollArea->setObjectName(QStringLiteral("newScrollArea"));
        newScrollArea->setGeometry(QRect(560, 40, 500, 500));
        newScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 498, 498));
        picture2 = new QLabel(scrollAreaWidgetContents_2);
        picture2->setObjectName(QStringLiteral("picture2"));
        picture2->setGeometry(QRect(250, 250, 1, 1));
        newScrollArea->setWidget(scrollAreaWidgetContents_2);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 550, 40, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 54, 12));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(560, 10, 61, 16));
        makeDone = new QPushButton(centralWidget);
        makeDone->setObjectName(QStringLiteral("makeDone"));
        makeDone->setGeometry(QRect(930, 10, 101, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(560, 550, 31, 16));
        theThreshold = new QLabel(centralWidget);
        theThreshold->setObjectName(QStringLiteral("theThreshold"));
        theThreshold->setGeometry(QRect(600, 550, 54, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1080, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_4 = new QMenu(menu_2);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menuAutomatic = new QMenu(menu_4);
        menuAutomatic->setObjectName(QStringLiteral("menuAutomatic"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menuRoberts_operator = new QMenu(menu_3);
        menuRoberts_operator->setObjectName(QStringLiteral("menuRoberts_operator"));
        menuPrewitt_operator = new QMenu(menu_3);
        menuPrewitt_operator->setObjectName(QStringLiteral("menuPrewitt_operator"));
        menuSobel_operator = new QMenu(menu_3);
        menuSobel_operator->setObjectName(QStringLiteral("menuSobel_operator"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_6 = new QMenu(menu_5);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        menu_7 = new QMenu(menu_5);
        menu_7->setObjectName(QStringLiteral("menu_7"));
        menu_8 = new QMenu(menuBar);
        menu_8->setObjectName(QStringLiteral("menu_8"));
        menu_9 = new QMenu(menu_8);
        menu_9->setObjectName(QStringLiteral("menu_9"));
        menu_10 = new QMenu(menu_8);
        menu_10->setObjectName(QStringLiteral("menu_10"));
        menu_12 = new QMenu(menu_8);
        menu_12->setObjectName(QStringLiteral("menu_12"));
        menu_11 = new QMenu(menu_8);
        menu_11->setObjectName(QStringLiteral("menu_11"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menuBar->addAction(menu_8->menuAction());
        menu->addAction(newPicture);
        menu->addAction(openPicture);
        menu->addAction(action_openPicture2);
        menu->addAction(actionTest);
        menu_2->addAction(drawHistogram);
        menu_2->addAction(menu_4->menuAction());
        menu_2->addAction(reSize);
        menu_4->addAction(actionManual);
        menu_4->addAction(menuAutomatic->menuAction());
        menuAutomatic->addAction(actionOtsu);
        menuAutomatic->addAction(actionEntropy);
        menu_3->addAction(menuRoberts_operator->menuAction());
        menu_3->addAction(menuPrewitt_operator->menuAction());
        menu_3->addAction(menuSobel_operator->menuAction());
        menu_3->addAction(actionGaussian_filter);
        menu_3->addAction(actionMean_filter);
        menu_3->addAction(actionMedian_filter);
        menu_3->addAction(matrixBySelf);
        menuRoberts_operator->addAction(Roberts_x);
        menuRoberts_operator->addAction(Roberts_y);
        menuRoberts_operator->addAction(Roberts_RGB_x);
        menuRoberts_operator->addAction(Roberts_RGB_y);
        menuPrewitt_operator->addAction(prewitt_x);
        menuPrewitt_operator->addAction(prewitt_y);
        menuPrewitt_operator->addAction(prewitt_RGB_x);
        menuPrewitt_operator->addAction(prewitt_RGB_y);
        menuSobel_operator->addAction(sobel_x);
        menuSobel_operator->addAction(sobel_y);
        menuSobel_operator->addAction(sobel_RGB_x);
        menuSobel_operator->addAction(sobel_RGB_y);
        menu_5->addAction(action_vertex);
        menu_5->addAction(menu_6->menuAction());
        menu_5->addAction(menu_7->menuAction());
        menu_6->addAction(action_add);
        menu_6->addAction(action_minus);
        menu_6->addAction(action_multiply);
        menu_7->addAction(clockwise);
        menu_7->addAction(anticlockwise);
        menu_8->addAction(menu_9->menuAction());
        menu_8->addAction(menu_10->menuAction());
        menu_8->addAction(menu_11->menuAction());
        menu_8->addAction(menu_12->menuAction());
        menu_9->addAction(grayDilation);
        menu_9->addAction(binaryDilation);
        menu_10->addAction(grayErosion);
        menu_10->addAction(binaryErosion);
        menu_12->addAction(grayClose);
        menu_12->addAction(binaryClose);
        menu_11->addAction(grayOpen);
        menu_11->addAction(binaryOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        newPicture->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\233\276\347\211\207", 0));
        openPicture->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", 0));
        drawHistogram->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\347\201\260\345\272\246\347\233\264\346\226\271\345\233\276", 0));
        reSize->setText(QApplication::translate("MainWindow", "\346\224\271\345\217\230\345\233\276\347\211\207\345\244\247\345\260\217", 0));
        actionGaussian_filter->setText(QApplication::translate("MainWindow", "Gaussian filter", 0));
        actionMean_filter->setText(QApplication::translate("MainWindow", "mean filter", 0));
        actionMedian_filter->setText(QApplication::translate("MainWindow", "Median filter", 0));
        actionManual->setText(QApplication::translate("MainWindow", "manual", 0));
        actionOtsu->setText(QApplication::translate("MainWindow", "Otsu", 0));
        actionEntropy->setText(QApplication::translate("MainWindow", "Entropy", 0));
        matrixBySelf->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\350\276\223\345\205\245\345\215\267\347\247\257\347\237\251\351\230\265", 0));
        action_vertex->setText(QApplication::translate("MainWindow", "\347\202\271\346\223\215\344\275\234", 0));
        action_add->setText(QApplication::translate("MainWindow", "\344\273\243\346\225\260\345\212\240", 0));
        action_minus->setText(QApplication::translate("MainWindow", "\344\273\243\346\225\260\345\207\217", 0));
        action_multiply->setText(QApplication::translate("MainWindow", "\344\273\243\346\225\260\344\271\230", 0));
        action_openPicture2->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\273\243\346\225\260\346\223\215\344\275\234\345\233\276\347\211\207", 0));
        Roberts_x->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\346\250\252\345\220\221", 0));
        Roberts_y->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\347\272\265\345\220\221", 0));
        prewitt_x->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\346\250\252\345\220\221", 0));
        prewitt_y->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\347\272\265\345\220\221", 0));
        sobel_x->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\346\250\252\345\220\221", 0));
        sobel_y->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\347\272\265\345\220\221", 0));
        Roberts_RGB_x->setText(QApplication::translate("MainWindow", "RGB\346\250\252\345\220\221", 0));
        Roberts_RGB_y->setText(QApplication::translate("MainWindow", "RGB\347\272\265\345\220\221", 0));
        prewitt_RGB_x->setText(QApplication::translate("MainWindow", "RGB\346\250\252\345\220\221", 0));
        prewitt_RGB_y->setText(QApplication::translate("MainWindow", "RGB\347\272\265\345\220\221", 0));
        sobel_RGB_x->setText(QApplication::translate("MainWindow", "RGB\346\250\252\345\220\221", 0));
        sobel_RGB_y->setText(QApplication::translate("MainWindow", "RGB\347\272\265\345\220\221", 0));
        actionTest->setText(QApplication::translate("MainWindow", "test", 0));
        clockwise->setText(QApplication::translate("MainWindow", "\351\241\272\345\212\277\351\222\21090\345\272\246", 0));
        anticlockwise->setText(QApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\21090\345\272\246", 0));
        grayDilation->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246", 0));
        binaryDilation->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274", 0));
        grayErosion->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246", 0));
        binaryErosion->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274", 0));
        grayOpen->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246", 0));
        binaryOpen->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274", 0));
        grayClose->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246", 0));
        binaryClose->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274", 0));
        picture1->setText(QString());
        picture2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\244\204\347\220\206\345\233\276\345\203\217", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\244\204\347\220\206\345\220\216\345\233\276\345\203\217", 0));
        makeDone->setText(QApplication::translate("MainWindow", "\350\275\254\344\270\272\345\244\204\347\220\206\345\233\276\345\203\217", 0));
        label_4->setText(QApplication::translate("MainWindow", "\351\230\210\345\200\274", 0));
        theThreshold->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", 0));
        menu_4->setTitle(QApplication::translate("MainWindow", "\350\277\233\350\241\214\344\272\214\345\200\274\345\214\226", 0));
        menuAutomatic->setTitle(QApplication::translate("MainWindow", "automatic", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\273\244\351\225\234", 0));
        menuRoberts_operator->setTitle(QApplication::translate("MainWindow", "Roberts operator", 0));
        menuPrewitt_operator->setTitle(QApplication::translate("MainWindow", "Prewitt operator", 0));
        menuSobel_operator->setTitle(QApplication::translate("MainWindow", "Sobel operator", 0));
        menu_5->setTitle(QApplication::translate("MainWindow", "\345\203\217\347\264\240\346\223\215\344\275\234", 0));
        menu_6->setTitle(QApplication::translate("MainWindow", "\344\273\243\346\225\260\346\223\215\344\275\234", 0));
        menu_7->setTitle(QApplication::translate("MainWindow", "\346\227\213\350\275\254", 0));
        menu_8->setTitle(QApplication::translate("MainWindow", "\345\275\242\346\200\201\346\223\215\344\275\234", 0));
        menu_9->setTitle(QApplication::translate("MainWindow", "\350\206\250\350\203\200", 0));
        menu_10->setTitle(QApplication::translate("MainWindow", "\350\205\220\350\232\200", 0));
        menu_12->setTitle(QApplication::translate("MainWindow", "\351\227\255\346\223\215\344\275\234", 0));
        menu_11->setTitle(QApplication::translate("MainWindow", "\345\274\200\346\223\215\344\275\234", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
