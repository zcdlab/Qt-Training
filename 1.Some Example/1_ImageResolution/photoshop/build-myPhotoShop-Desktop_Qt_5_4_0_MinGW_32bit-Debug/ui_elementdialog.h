/********************************************************************************
** Form generated from reading UI file 'elementdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELEMENTDIALOG_H
#define UI_ELEMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_elementDialog
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_0;
    QSpinBox *spinBox_1;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_9;
    QSpinBox *spinBox_10;
    QSpinBox *spinBox_11;
    QSpinBox *spinBox_12;
    QSpinBox *spinBox_13;
    QSpinBox *spinBox_14;
    QSpinBox *spinBox_15;
    QSpinBox *spinBox_16;
    QSpinBox *spinBox_17;
    QSpinBox *spinBox_18;
    QSpinBox *spinBox_19;
    QSpinBox *spinBox_20;
    QSpinBox *spinBox_21;
    QSpinBox *spinBox_22;
    QSpinBox *spinBox_23;
    QSpinBox *spinBox_24;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *elementDialog)
    {
        if (elementDialog->objectName().isEmpty())
            elementDialog->setObjectName(QStringLiteral("elementDialog"));
        elementDialog->resize(276, 235);
        label = new QLabel(elementDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 54, 12));
        layoutWidget = new QWidget(elementDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 236, 126));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_0 = new QSpinBox(layoutWidget);
        spinBox_0->setObjectName(QStringLiteral("spinBox_0"));
        spinBox_0->setMaximum(1);

        gridLayout->addWidget(spinBox_0, 0, 0, 1, 1);

        spinBox_1 = new QSpinBox(layoutWidget);
        spinBox_1->setObjectName(QStringLiteral("spinBox_1"));
        spinBox_1->setMaximum(1);

        gridLayout->addWidget(spinBox_1, 0, 1, 1, 1);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(1);

        gridLayout->addWidget(spinBox_2, 0, 2, 1, 1);

        spinBox_3 = new QSpinBox(layoutWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(1);

        gridLayout->addWidget(spinBox_3, 0, 3, 1, 1);

        spinBox_4 = new QSpinBox(layoutWidget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMaximum(1);

        gridLayout->addWidget(spinBox_4, 0, 4, 1, 1);

        spinBox_5 = new QSpinBox(layoutWidget);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setMaximum(1);

        gridLayout->addWidget(spinBox_5, 1, 0, 1, 1);

        spinBox_6 = new QSpinBox(layoutWidget);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setMaximum(1);

        gridLayout->addWidget(spinBox_6, 1, 1, 1, 1);

        spinBox_7 = new QSpinBox(layoutWidget);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setMaximum(1);

        gridLayout->addWidget(spinBox_7, 1, 2, 1, 1);

        spinBox_8 = new QSpinBox(layoutWidget);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setMaximum(1);

        gridLayout->addWidget(spinBox_8, 1, 3, 1, 1);

        spinBox_9 = new QSpinBox(layoutWidget);
        spinBox_9->setObjectName(QStringLiteral("spinBox_9"));
        spinBox_9->setMaximum(1);

        gridLayout->addWidget(spinBox_9, 1, 4, 1, 1);

        spinBox_10 = new QSpinBox(layoutWidget);
        spinBox_10->setObjectName(QStringLiteral("spinBox_10"));
        spinBox_10->setMaximum(1);

        gridLayout->addWidget(spinBox_10, 2, 0, 1, 1);

        spinBox_11 = new QSpinBox(layoutWidget);
        spinBox_11->setObjectName(QStringLiteral("spinBox_11"));
        spinBox_11->setMaximum(1);

        gridLayout->addWidget(spinBox_11, 2, 1, 1, 1);

        spinBox_12 = new QSpinBox(layoutWidget);
        spinBox_12->setObjectName(QStringLiteral("spinBox_12"));
        spinBox_12->setMaximum(1);

        gridLayout->addWidget(spinBox_12, 2, 2, 1, 1);

        spinBox_13 = new QSpinBox(layoutWidget);
        spinBox_13->setObjectName(QStringLiteral("spinBox_13"));
        spinBox_13->setMaximum(1);

        gridLayout->addWidget(spinBox_13, 2, 3, 1, 1);

        spinBox_14 = new QSpinBox(layoutWidget);
        spinBox_14->setObjectName(QStringLiteral("spinBox_14"));
        spinBox_14->setMaximum(1);

        gridLayout->addWidget(spinBox_14, 2, 4, 1, 1);

        spinBox_15 = new QSpinBox(layoutWidget);
        spinBox_15->setObjectName(QStringLiteral("spinBox_15"));
        spinBox_15->setMaximum(1);

        gridLayout->addWidget(spinBox_15, 3, 0, 1, 1);

        spinBox_16 = new QSpinBox(layoutWidget);
        spinBox_16->setObjectName(QStringLiteral("spinBox_16"));
        spinBox_16->setMaximum(1);

        gridLayout->addWidget(spinBox_16, 3, 1, 1, 1);

        spinBox_17 = new QSpinBox(layoutWidget);
        spinBox_17->setObjectName(QStringLiteral("spinBox_17"));
        spinBox_17->setMaximum(1);

        gridLayout->addWidget(spinBox_17, 3, 2, 1, 1);

        spinBox_18 = new QSpinBox(layoutWidget);
        spinBox_18->setObjectName(QStringLiteral("spinBox_18"));
        spinBox_18->setMaximum(1);

        gridLayout->addWidget(spinBox_18, 3, 3, 1, 1);

        spinBox_19 = new QSpinBox(layoutWidget);
        spinBox_19->setObjectName(QStringLiteral("spinBox_19"));
        spinBox_19->setMaximum(1);

        gridLayout->addWidget(spinBox_19, 3, 4, 1, 1);

        spinBox_20 = new QSpinBox(layoutWidget);
        spinBox_20->setObjectName(QStringLiteral("spinBox_20"));
        spinBox_20->setMaximum(1);

        gridLayout->addWidget(spinBox_20, 4, 0, 1, 1);

        spinBox_21 = new QSpinBox(layoutWidget);
        spinBox_21->setObjectName(QStringLiteral("spinBox_21"));
        spinBox_21->setMaximum(1);

        gridLayout->addWidget(spinBox_21, 4, 1, 1, 1);

        spinBox_22 = new QSpinBox(layoutWidget);
        spinBox_22->setObjectName(QStringLiteral("spinBox_22"));
        spinBox_22->setMaximum(1);

        gridLayout->addWidget(spinBox_22, 4, 2, 1, 1);

        spinBox_23 = new QSpinBox(layoutWidget);
        spinBox_23->setObjectName(QStringLiteral("spinBox_23"));
        spinBox_23->setMaximum(1);

        gridLayout->addWidget(spinBox_23, 4, 3, 1, 1);

        spinBox_24 = new QSpinBox(layoutWidget);
        spinBox_24->setObjectName(QStringLiteral("spinBox_24"));
        spinBox_24->setMaximum(1);

        gridLayout->addWidget(spinBox_24, 4, 4, 1, 1);

        widget = new QWidget(elementDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 190, 158, 25));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(widget);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_2->addWidget(okButton, 0, 0, 1, 1);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 0, 1, 1, 1);


        retranslateUi(elementDialog);

        QMetaObject::connectSlotsByName(elementDialog);
    } // setupUi

    void retranslateUi(QDialog *elementDialog)
    {
        elementDialog->setWindowTitle(QApplication::translate("elementDialog", "Dialog", 0));
        label->setText(QApplication::translate("elementDialog", "\345\205\203\347\264\240\350\256\276\345\256\232", 0));
        okButton->setText(QApplication::translate("elementDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("elementDialog", "CANCEL", 0));
    } // retranslateUi

};

namespace Ui {
    class elementDialog: public Ui_elementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELEMENTDIALOG_H
