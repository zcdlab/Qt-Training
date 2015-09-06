/********************************************************************************
** Form generated from reading UI file 'manualdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUALDIALOG_H
#define UI_MANUALDIALOG_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manualDialog
{
public:
    QLabel *label_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox;
    QFormLayout *formLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label;

    void setupUi(QDialog *manualDialog)
    {
        if (manualDialog->objectName().isEmpty())
            manualDialog->setObjectName(QStringLiteral("manualDialog"));
        manualDialog->resize(199, 96);
        label_2 = new QLabel(manualDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 54, 12));
        widget = new QWidget(manualDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 160, 53));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(255);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        okButton = new QPushButton(widget);
        okButton->setObjectName(QStringLiteral("okButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, okButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cancelButton);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label->raise();
        spinBox->raise();
        okButton->raise();
        cancelButton->raise();
        label_2->raise();
        label->raise();

        retranslateUi(manualDialog);

        QMetaObject::connectSlotsByName(manualDialog);
    } // setupUi

    void retranslateUi(QDialog *manualDialog)
    {
        manualDialog->setWindowTitle(QApplication::translate("manualDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("manualDialog", "\351\230\210\345\200\274\350\256\276\345\256\232", 0));
        spinBox->setSuffix(QApplication::translate("manualDialog", " \347\201\260\345\272\246\345\200\274", 0));
        spinBox->setPrefix(QString());
        okButton->setText(QApplication::translate("manualDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("manualDialog", "CANCEL", 0));
        label->setText(QApplication::translate("manualDialog", "\351\230\210\345\200\274", 0));
    } // retranslateUi

};

namespace Ui {
    class manualDialog: public Ui_manualDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALDIALOG_H
