
#include "mainwindow.h"
#include <QApplication>
/*简单的函数模版
template<typename T>
void change(T& a,T& b)
{
    T temp=a;
    a=b;
    b=temp;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int c=1;
    int b=2;
    qDebug()<<c<<"   "<<b<<endl;
    change<int>(c,b);
    qDebug()<<c<<"   "<<b<<endl;

    return a.exec();
}
*/



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


