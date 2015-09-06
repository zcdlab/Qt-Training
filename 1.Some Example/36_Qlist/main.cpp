#include <QCoreApplication>
#include <Qlist>
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

/*
    QList <QString > list;
    for(int i=0;i<10;i++)
    {
        list.append(QString::number(i+100));
    }
    foreach (QString number , list)
    {
        qDebug()<<number;
    }
     qDebug()<<"\r";
    list.removeOne("100");
    foreach (QString number , list)
    {
        qDebug()<<number;
    }
    */

    QList<int > list;
    for(int i=0;i<10;i++)
    {
        list.append((i+100));
    }
    QListIterator <int > Iter(list);
    Iter.toFront();
    while(Iter.hasNext())
    {
    qDebug()<<Iter.next();

    }

    return a.exec();
}
