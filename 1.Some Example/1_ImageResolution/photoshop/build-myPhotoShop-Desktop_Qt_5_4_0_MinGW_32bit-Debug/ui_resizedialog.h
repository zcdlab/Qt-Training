/********************************************************************************
** Form generated from reading UI file 'resizedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEDIALOG_H
#define UI_RESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reSizeDialog
{
public:
    QLabel *label;
    QWidget *widget;
    QFormLayout *formLayout;
    QSpinBox *xSpinBox;
    QLabel *label_3;
    QSpinBox *ySpinBox;
    QLabel *label_2;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QWidget *widget2;
    QGridLayout *gridLayout_2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *reSizeDialog)
    {
        if (reSizeDialog->objectName().isEmpty())
            reSizeDialog->setObjectName(QStringLiteral("reSizeDialog"));
        reSizeDialog->resize(284, 151);
        label = new QLabel(reSizeDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 48, 16));
        widget = new QWidget(reSizeDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 40, 131, 48));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        xSpinBox = new QSpinBox(widget);
        xSpinBox->setObjectName(QStringLiteral("xSpinBox"));
        xSpinBox->setMinimum(1);
        xSpinBox->setMaximum(1000);

        formLayout->setWidget(0, QFormLayout::FieldRole, xSpinBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        ySpinBox = new QSpinBox(widget);
        ySpinBox->setObjectName(QStringLiteral("ySpinBox"));
        ySpinBox->setMinimum(1);
        ySpinBox->setMaximum(1000);

        formLayout->setWidget(1, QFormLayout::FieldRole, ySpinBox);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        widget1 = new QWidget(reSizeDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(150, 30, 121, 62));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget1);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(widget1);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 1);

        radioButton_3 = new QRadioButton(widget1);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 2, 0, 1, 1);

        widget2 = new QWidget(reSizeDialog);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 110, 158, 25));
        gridLayout_2 = new QGridLayout(widget2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(widget2);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_2->addWidget(okButton, 0, 0, 1, 1);

        cancelButton = new QPushButton(widget2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 0, 1, 1, 1);

        label->raise();
        radioButton->raise();
        radioButton_2->raise();
        radioButton_3->raise();
        label_2->raise();
        label_2->raise();

        retranslateUi(reSizeDialog);

        QMetaObject::connectSlotsByName(reSizeDialog);
    } // setupUi

    void retranslateUi(QDialog *reSizeDialog)
    {
        reSizeDialog->setWindowTitle(QApplication::translate("reSizeDialog", "Dialog", 0));
        label->setText(QApplication::translate("reSizeDialog", "\347\233\256\346\240\207\345\244\247\345\260\217", 0));
        xSpinBox->setSuffix(QApplication::translate("reSizeDialog", " \345\203\217\347\264\240", 0));
        label_3->setText(QApplication::translate("reSizeDialog", "\347\272\265\345\220\221\345\203\217\347\264\240", 0));
        ySpinBox->setSuffix(QApplication::translate("reSizeDialog", " \345\203\217\347\264\240", 0));
        label_2->setText(QApplication::translate("reSizeDialog", "\346\250\252\345\220\221\345\203\217\347\264\240", 0));
        radioButton->setText(QApplication::translate("reSizeDialog", "Nearest Neighbor", 0));
        radioButton_2->setText(QApplication::translate("reSizeDialog", "Bilinear", 0));
        radioButton_3->setText(QApplication::translate("reSizeDialog", "Bicubic ", 0));
        okButton->setText(QApplication::translate("reSizeDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("reSizeDialog", "CANCEL", 0));
    } // retranslateUi

};

namespace Ui {
    class reSizeDialog: public Ui_reSizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEDIALOG_H
