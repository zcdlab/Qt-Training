#include <QCoreApplication>
#include <QtCore>
#include <QFile>
#include <QString>
#include <QMap>
#include <QDebug>

void save()
{
    int num=48;
    QMap <qint64,QString >map;
    map.insert(49,"One");
    map.insert(50,"Two");
    map.insert(51,"Three");

    QFile file("D:\\myfile.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"Could not open file";
        return;
    }


    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_4);
    out<<num<<map;


    file.flush();
    file.close();
}


void load()
{
    int num=48;
    QMap <qint64,QString >map;
    map.insert(49,"One");
    map.insert(50,"Two");
    map.insert(51,"Three");

    QFile file("D:\\myfile.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Could not open file";
        return;
    }


    QDataStream in(&file);
    //out.setVersion(QDataStream::Qt_5_4);
    in>>num>>map;

    file.close();
    qDebug()<<"num= "<<num;
    foreach (QString item, map.values())
    {
        qDebug()<<item;
    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    save();
    load();
    return a.exec();
}

