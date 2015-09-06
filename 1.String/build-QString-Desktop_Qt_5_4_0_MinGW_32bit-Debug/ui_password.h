/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_password
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_firstPassword;
    QPushButton *pushButton_passWord;

    void setupUi(QDialog *password)
    {
        if (password->objectName().isEmpty())
            password->setObjectName(QStringLiteral("password"));
        password->resize(582, 61);
        widget = new QWidget(password);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 561, 36));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_firstPassword = new QLineEdit(widget);
        lineEdit_firstPassword->setObjectName(QStringLiteral("lineEdit_firstPassword"));

        horizontalLayout->addWidget(lineEdit_firstPassword);

        pushButton_passWord = new QPushButton(widget);
        pushButton_passWord->setObjectName(QStringLiteral("pushButton_passWord"));

        horizontalLayout->addWidget(pushButton_passWord);


        retranslateUi(password);

        QMetaObject::connectSlotsByName(password);
    } // setupUi

    void retranslateUi(QDialog *password)
    {
        password->setWindowTitle(QApplication::translate("password", "Dialog", 0));
        label->setText(QApplication::translate("password", "Input your Password First:", 0));
        pushButton_passWord->setText(QApplication::translate("password", "Sure_&&_Go", 0));
    } // retranslateUi

};

namespace Ui {
    class password: public Ui_password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
