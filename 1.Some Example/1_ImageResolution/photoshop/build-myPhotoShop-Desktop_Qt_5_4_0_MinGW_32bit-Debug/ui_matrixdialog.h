/********************************************************************************
** Form generated from reading UI file 'matrixdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIXDIALOG_H
#define UI_MATRIXDIALOG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_matrixDialog
{
public:
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *cancelButton;
    QPushButton *okButton;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QDoubleSpinBox *a1;
    QDoubleSpinBox *a3;
    QDoubleSpinBox *b1;
    QDoubleSpinBox *b2;
    QDoubleSpinBox *b3;
    QDoubleSpinBox *c1;
    QDoubleSpinBox *c2;
    QDoubleSpinBox *c3;
    QDoubleSpinBox *a2;

    void setupUi(QDialog *matrixDialog)
    {
        if (matrixDialog->objectName().isEmpty())
            matrixDialog->setObjectName(QStringLiteral("matrixDialog"));
        matrixDialog->resize(257, 153);
        label = new QLabel(matrixDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 54, 12));
        widget = new QWidget(matrixDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 110, 158, 25));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 0, 1, 1, 1);

        okButton = new QPushButton(widget);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_2->addWidget(okButton, 0, 0, 1, 1);

        widget1 = new QWidget(matrixDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 30, 211, 74));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        a1 = new QDoubleSpinBox(widget1);
        a1->setObjectName(QStringLiteral("a1"));
        a1->setDecimals(1);
        a1->setMinimum(-10);
        a1->setMaximum(10);
        a1->setSingleStep(0.1);

        gridLayout->addWidget(a1, 0, 0, 1, 1);

        a3 = new QDoubleSpinBox(widget1);
        a3->setObjectName(QStringLiteral("a3"));
        a3->setDecimals(1);
        a3->setMinimum(-10);
        a3->setMaximum(10);
        a3->setSingleStep(0.1);
        a3->setValue(0);

        gridLayout->addWidget(a3, 0, 2, 1, 1);

        b1 = new QDoubleSpinBox(widget1);
        b1->setObjectName(QStringLiteral("b1"));
        b1->setDecimals(1);
        b1->setMinimum(-10);
        b1->setMaximum(10);
        b1->setSingleStep(0.1);
        b1->setValue(0);

        gridLayout->addWidget(b1, 1, 0, 1, 1);

        b2 = new QDoubleSpinBox(widget1);
        b2->setObjectName(QStringLiteral("b2"));
        b2->setDecimals(1);
        b2->setMinimum(-10);
        b2->setMaximum(10);
        b2->setSingleStep(0.1);
        b2->setValue(0);

        gridLayout->addWidget(b2, 1, 1, 1, 1);

        b3 = new QDoubleSpinBox(widget1);
        b3->setObjectName(QStringLiteral("b3"));
        b3->setDecimals(1);
        b3->setMinimum(-10);
        b3->setMaximum(10);
        b3->setSingleStep(0.1);
        b3->setValue(0);

        gridLayout->addWidget(b3, 1, 2, 1, 1);

        c1 = new QDoubleSpinBox(widget1);
        c1->setObjectName(QStringLiteral("c1"));
        c1->setDecimals(1);
        c1->setMinimum(-10);
        c1->setMaximum(10);
        c1->setSingleStep(0.1);
        c1->setValue(0);

        gridLayout->addWidget(c1, 2, 0, 1, 1);

        c2 = new QDoubleSpinBox(widget1);
        c2->setObjectName(QStringLiteral("c2"));
        c2->setDecimals(1);
        c2->setMinimum(-10);
        c2->setMaximum(10);
        c2->setSingleStep(0.1);
        c2->setValue(0);

        gridLayout->addWidget(c2, 2, 1, 1, 1);

        c3 = new QDoubleSpinBox(widget1);
        c3->setObjectName(QStringLiteral("c3"));
        c3->setDecimals(1);
        c3->setMinimum(-10);
        c3->setMaximum(10);
        c3->setSingleStep(0.1);
        c3->setValue(0);

        gridLayout->addWidget(c3, 2, 2, 1, 1);

        a2 = new QDoubleSpinBox(widget1);
        a2->setObjectName(QStringLiteral("a2"));
        a2->setDecimals(1);
        a2->setMinimum(-10);
        a2->setMaximum(10);
        a2->setSingleStep(0.1);

        gridLayout->addWidget(a2, 0, 1, 1, 1);

        a1->raise();
        a2->raise();
        a3->raise();
        b1->raise();
        b2->raise();
        b3->raise();
        c1->raise();
        c2->raise();
        c3->raise();
        label->raise();
        okButton->raise();
        cancelButton->raise();
        a1->raise();
        a2->raise();
        a3->raise();
        b1->raise();
        b2->raise();
        b3->raise();
        c1->raise();
        c2->raise();
        c3->raise();
        okButton->raise();

        retranslateUi(matrixDialog);

        QMetaObject::connectSlotsByName(matrixDialog);
    } // setupUi

    void retranslateUi(QDialog *matrixDialog)
    {
        matrixDialog->setWindowTitle(QApplication::translate("matrixDialog", "Dialog", 0));
        label->setText(QApplication::translate("matrixDialog", "\350\276\223\345\205\245\347\237\251\351\230\265", 0));
        cancelButton->setText(QApplication::translate("matrixDialog", "CANCEL", 0));
        okButton->setText(QApplication::translate("matrixDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class matrixDialog: public Ui_matrixDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIXDIALOG_H
