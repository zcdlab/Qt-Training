/********************************************************************************
** Form generated from reading UI file 'newpicdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPICDIALOG_H
#define UI_NEWPICDIALOG_H

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

class Ui_newPicDialog
{
public:
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *height;
    QLabel *label_3;
    QSpinBox *width;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *newPicDialog)
    {
        if (newPicDialog->objectName().isEmpty())
            newPicDialog->setObjectName(QStringLiteral("newPicDialog"));
        newPicDialog->resize(192, 162);
        label = new QLabel(newPicDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 51, 16));
        widget = new QWidget(newPicDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 50, 121, 48));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        height = new QSpinBox(widget);
        height->setObjectName(QStringLiteral("height"));
        height->setMinimum(1);
        height->setMaximum(1000);

        gridLayout->addWidget(height, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        width = new QSpinBox(widget);
        width->setObjectName(QStringLiteral("width"));
        width->setMinimum(1);
        width->setMaximum(1000);

        gridLayout->addWidget(width, 1, 1, 1, 1);

        widget1 = new QWidget(newPicDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 110, 121, 25));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(widget1);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_2->addWidget(okButton, 0, 0, 1, 1);

        cancelButton = new QPushButton(widget1);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 0, 1, 1, 1);


        retranslateUi(newPicDialog);

        QMetaObject::connectSlotsByName(newPicDialog);
    } // setupUi

    void retranslateUi(QDialog *newPicDialog)
    {
        newPicDialog->setWindowTitle(QApplication::translate("newPicDialog", "Dialog", 0));
        label->setText(QApplication::translate("newPicDialog", "\346\226\260\345\273\272\345\233\276\347\211\207", 0));
        label_2->setText(QApplication::translate("newPicDialog", "\351\225\277\345\272\246", 0));
        height->setSuffix(QApplication::translate("newPicDialog", " \345\203\217\347\264\240", 0));
        label_3->setText(QApplication::translate("newPicDialog", "\351\253\230\345\272\246", 0));
        width->setSuffix(QApplication::translate("newPicDialog", " \345\203\217\347\264\240", 0));
        okButton->setText(QApplication::translate("newPicDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("newPicDialog", "CANCEL", 0));
    } // retranslateUi

};

namespace Ui {
    class newPicDialog: public Ui_newPicDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPICDIALOG_H
