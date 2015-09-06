/********************************************************************************
** Form generated from reading UI file 'vertexdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERTEXDIALOG_H
#define UI_VERTEXDIALOG_H

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

class Ui_vertexDialog
{
public:
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *x1;
    QLabel *label_4;
    QSpinBox *x2;
    QLabel *label_3;
    QSpinBox *y1;
    QLabel *label_5;
    QSpinBox *y2;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QWidget *widget2;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QSpinBox *r;
    QLabel *label_7;
    QSpinBox *g;
    QLabel *label_8;
    QSpinBox *b;

    void setupUi(QDialog *vertexDialog)
    {
        if (vertexDialog->objectName().isEmpty())
            vertexDialog->setObjectName(QStringLiteral("vertexDialog"));
        vertexDialog->resize(313, 201);
        label = new QLabel(vertexDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 51, 20));
        widget = new QWidget(vertexDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 40, 236, 48));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        x1 = new QSpinBox(widget);
        x1->setObjectName(QStringLiteral("x1"));
        x1->setMaximum(1000);

        gridLayout->addWidget(x1, 0, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        x2 = new QSpinBox(widget);
        x2->setObjectName(QStringLiteral("x2"));
        x2->setMaximum(1000);

        gridLayout->addWidget(x2, 0, 3, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        y1 = new QSpinBox(widget);
        y1->setObjectName(QStringLiteral("y1"));
        y1->setMaximum(1000);

        gridLayout->addWidget(y1, 1, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        y2 = new QSpinBox(widget);
        y2->setObjectName(QStringLiteral("y2"));
        y2->setMaximum(1000);

        gridLayout->addWidget(y2, 1, 3, 1, 1);

        widget1 = new QWidget(vertexDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(190, 110, 77, 54));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(widget1);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_2->addWidget(okButton, 0, 0, 1, 1);

        cancelButton = new QPushButton(widget1);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 1, 0, 1, 1);

        widget2 = new QWidget(vertexDialog);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(50, 100, 101, 74));
        gridLayout_3 = new QGridLayout(widget2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        r = new QSpinBox(widget2);
        r->setObjectName(QStringLiteral("r"));
        r->setMaximum(255);

        gridLayout_3->addWidget(r, 0, 1, 1, 1);

        label_7 = new QLabel(widget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        g = new QSpinBox(widget2);
        g->setObjectName(QStringLiteral("g"));
        g->setMaximum(255);

        gridLayout_3->addWidget(g, 1, 1, 1, 1);

        label_8 = new QLabel(widget2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        b = new QSpinBox(widget2);
        b->setObjectName(QStringLiteral("b"));
        b->setMaximum(255);

        gridLayout_3->addWidget(b, 2, 1, 1, 1);


        retranslateUi(vertexDialog);

        QMetaObject::connectSlotsByName(vertexDialog);
    } // setupUi

    void retranslateUi(QDialog *vertexDialog)
    {
        vertexDialog->setWindowTitle(QApplication::translate("vertexDialog", "Dialog", 0));
        label->setText(QApplication::translate("vertexDialog", "\345\203\217\347\264\240\350\214\203\345\233\264", 0));
        label_2->setText(QApplication::translate("vertexDialog", "\346\250\252\345\220\221\345\203\217\347\264\240", 0));
        x1->setSuffix(QApplication::translate("vertexDialog", " \345\203\217\347\264\240", 0));
        label_4->setText(QApplication::translate("vertexDialog", "\345\210\260", 0));
        x2->setSuffix(QApplication::translate("vertexDialog", " \345\203\217\347\264\240", 0));
        label_3->setText(QApplication::translate("vertexDialog", "\347\272\265\345\220\221\345\203\217\347\264\240", 0));
        y1->setSuffix(QApplication::translate("vertexDialog", " \345\203\217\347\264\240", 0));
        label_5->setText(QApplication::translate("vertexDialog", "\345\210\260", 0));
        y2->setSuffix(QApplication::translate("vertexDialog", " \345\203\217\347\264\240", 0));
        okButton->setText(QApplication::translate("vertexDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("vertexDialog", "CANCEL", 0));
        label_6->setText(QApplication::translate("vertexDialog", " R:", 0));
        label_7->setText(QApplication::translate("vertexDialog", " G:", 0));
        label_8->setText(QApplication::translate("vertexDialog", " B:", 0));
    } // retranslateUi

};

namespace Ui {
    class vertexDialog: public Ui_vertexDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERTEXDIALOG_H
