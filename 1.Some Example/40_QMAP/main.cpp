#include <QCoreApplication>

#include <QMap>
#include <QDebug>
#include <QHash>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QHash<int,QString>Employees;

    Employees.insert(1,"jason");
    Employees.insert(2,"Sarah");
    Employees.insert(3,"Bob");
    //Employees.insertMulti(1,"Alice");
    foreach (int i, Employees.keys())
    {
        qDebug()<<Employees[i];
    }


    QHashIterator<int,QString>Itera(Employees);
    while(Itera.hasNext())
    {
        Itera.next();
        qDebug()<<Itera.key()<<" = "<<Itera.value();
    }
    return a.exec();
}
