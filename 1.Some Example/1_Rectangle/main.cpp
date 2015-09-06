#include "dialog.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    QList<int>  list;
    list<<1<<2<<3<<4<<5;
    QListIterator<int> i(list);
    for(;i.hasNext();)
        qDebug()<<i.next();
    w.show();

    return a.exec();
}
