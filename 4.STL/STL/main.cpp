#include <QCoreApplication>
#include <algorithm>
#include <vector>
#include <iterator>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int count=0;

    qDebug()<<"/*********** Vector*************/\r\n";
    QVector<char> charVector;
    charVector.push_back('Z');
    charVector.push_back('B');
    charVector.push_back('F');
    charVector.push_back('D');
    charVector.push_back('E');

    QString str;
    foreach (str, charVector)
    {
        if(str.isEmpty())
            break;

        qDebug()<<str;
    }

    qSort(charVector);
    qDebug()<<"After Sort!";

    foreach (str, charVector)
    {
        if(str.isEmpty())
            break;

        qDebug()<<str;
    }

    QVector<int> intVector(10);
    QVector<int>::iterator iv=intVector.begin();
    for(iv=intVector.begin();iv!=intVector.end();iv++)
    {
        *iv=count;
        count++;
    }
    count=0;

    for(iv=intVector.begin();iv!=intVector.end();iv++)
    {
        qDebug()<<(*iv);
    }


    qDebug()<<"So Much For Vector!\r\n";


    qDebug()<<"/*********** List*************/\r\n";
    QList<int> intList;
    for(int i=0;i<10;i++)
    {
        intList.push_front(i+'0');
    }
    foreach (str, intList)
    {
        if(str.isEmpty())
            break;
        qDebug()<<str;
    }
    qSort(intList);
    qDebug()<<"After Sort!";
    foreach (str, intList)
    {
        if(str.isEmpty())
            break;
        qDebug()<<str;
    }
    qDebug()<<"So Much For List!\r\n";

    qDebug()<<"/*********** Map*************/\r\n";
    QMap<QString,int> map;
    map.insertMulti("cindy",1);
    map.insert("Sarah",2);
    map.insert("John",3);
    QMapIterator<QString,int> i(map);
    while(i.hasNext())
    {
        i.next();
        qDebug()<<i.key()<<"  "<<i.value();
    }


    QMap<QString,int>::iterator j=map.find("Sarah");
    qDebug()<<j.key()<<"  "<<j.value();


    qDebug()<<"So Much For Map!\r\n";


    /*QHash<Key, T>	This has almost the same API as QMap,
     *  but provides significantly faster lookups. QHash stores its data in an arbitrary order.*/
    qDebug()<<"/*********** Hash************/\r\n";
    QHash<int,QString> hash;
    hash.insert(3,"John");
    hash.insert(2,"Sarah");
    hash.insertMulti(1,"cindy");
    QHashIterator<int,QString> hashi(hash);
    while(hashi.hasNext())
    {
        hashi.next();
        qDebug()<<hashi.key()<<"  "<<hashi.value();
    }
    qDebug()<<"So Much For Hash!\r\n";

    qDebug()<<"/*********** Set************/\r\n";
    QSet<float> set;
    set.insert(1.1);
    set.insert(2.2);
    set.insert(3.3);
    set.insert(4.4);
    set.insert(5.5);
    QSetIterator<float> f(set);
    float ff;
    foreach (ff, set)
    {
        qDebug()<<ff;
    }


    qDebug()<<"So Much For Set!\r\n";



    return a.exec();
}
