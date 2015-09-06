#include "dialog.h"
#include "ui_dialog.h"


#include <QGridLayout>
const static double PI=3.1416;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    Radius_label=new QLabel(this);
    Radius_label->setText("Radius");

    Radius_lineEdit=new QLineEdit(this);
    Radius_lineEdit->setText("1");

    Area_label=new QLabel(this);

    Calc_pushButton=new QPushButton(this);
    Calc_pushButton->setText(tr("Cacl!"));

    QGridLayout *mainLayout;
    mainLayout=new QGridLayout(this);

    mainLayout->addWidget(Radius_label,0,0);
    mainLayout->addWidget(Radius_lineEdit,0,1);
    mainLayout->addWidget(Area_label,1,0);
    mainLayout->addWidget(Calc_pushButton,1,1);



    connect(Calc_pushButton,SIGNAL(clicked()),this,SLOT(showArea()));

}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::showArea()
{
    bool Flag;
    QString RadiusStr;
    QString AreaStr;
    RadiusStr=Radius_lineEdit->text();
    int RadiusInt=RadiusStr.toInt(&Flag);
    double Area;
    Area=RadiusInt*RadiusInt*PI;
    Area_label->setText(AreaStr.setNum(Area));


}
