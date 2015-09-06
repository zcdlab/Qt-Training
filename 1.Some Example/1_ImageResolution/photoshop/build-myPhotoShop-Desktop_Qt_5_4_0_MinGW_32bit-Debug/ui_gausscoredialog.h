/********************************************************************************
** Form generated from reading UI file 'gausscoredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSSCOREDIALOG_H
#define UI_GAUSSCOREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gaussCoreDialog
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QDoubleSpinBox *a;
    QLabel *label_3;
    QSpinBox *N;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *gaussCoreDialog)
    {
        if (gaussCoreDialog->objectName().isEmpty())
            gaussCoreDialog->setObjectName(QStringLiteral("gaussCoreDialog"));
        gaussCoreDialog->resize(206, 154);
        label = new QLabel(gaussCoreDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 61, 16));
        layoutWidget = new QWidget(gaussCoreDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 151, 48));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        a = new QDoubleSpinBox(layoutWidget);
        a->setObjectName(QStringLiteral("a"));
        a->setMinimum(0.1);
        a->setMaximum(10);
        a->setSingleStep(0.1);
        a->setValue(0.1);

        gridLayout->addWidget(a, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        N = new QSpinBox(layoutWidget);
        N->setObjectName(QStringLiteral("N"));
        N->setMinimum(1);
        N->setMaximum(5);

        gridLayout->addWidget(N, 1, 1, 1, 1);

        layoutWidget1 = new QWidget(gaussCoreDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 100, 158, 31));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 0, 1, 1, 1);

        okButton = new QPushButton(layoutWidget1);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_2->addWidget(okButton, 0, 0, 1, 1);


        retranslateUi(gaussCoreDialog);

        QMetaObject::connectSlotsByName(gaussCoreDialog);
    } // setupUi

    void retranslateUi(QDialog *gaussCoreDialog)
    {
        gaussCoreDialog->setWindowTitle(QApplication::translate("gaussCoreDialog", "Dialog", 0));
        label->setText(QApplication::translate("gaussCoreDialog", "gaussCore", 0));
        label_2->setText(QApplication::translate("gaussCoreDialog", "\345\271\263\346\273\221\345\260\272\345\272\246", 0));
        label_3->setText(QApplication::translate("gaussCoreDialog", "\346\250\241\345\235\227\345\260\272\345\257\270", 0));
        cancelButton->setText(QApplication::translate("gaussCoreDialog", "CANCEL", 0));
        okButton->setText(QApplication::translate("gaussCoreDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class gaussCoreDialog: public Ui_gaussCoreDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSSCOREDIALOG_H
