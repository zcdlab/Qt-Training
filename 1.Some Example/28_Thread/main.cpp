#include <QCoreApplication>
#include "thread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Thread mythread1;
    Thread mythread2;
    Thread mythread3;
    mythread1.name="t1";
    mythread2.name="t2";
    mythread3.name="t3";
    mythread1.start(QThread::HighestPriority);
    mythread2.start();
    mythread3.start(QThread::LowestPriority);

    return a.exec();
}
