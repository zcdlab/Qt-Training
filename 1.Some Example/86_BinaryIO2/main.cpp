#include <QCoreApplication>
#include "person.h"
#include <QtCore>
#include "overload.h"


void save()
{
    person person1;
    person1.age=36;
    person1.name="Bryan";
    person person2;
    person2.age=18;
    person2.name="Heather";


    QFile file("d:/filefile.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"could not open the file!";
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_4);

    out << person1;
    out << person2;


    file.flush();
    file.close();


}

void load()
{
    person person1;
    person person2;
    QFile file("d:/filefile.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"could not open the file!";
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_4);

    in >> person1;
    in >> person2;

    qDebug()<<person1.age<<"  "<<person1.name<<"\n"<<person2.age<<"  "<<person2.name;

    file.close();

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    save();
    load();
    return a.exec();
}
