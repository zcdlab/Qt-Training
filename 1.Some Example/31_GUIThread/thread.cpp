#include "thread.h"
#include <QtCore>
Thread::Thread(QObject *parent) : QThread(parent)
{

}

void Thread::run()
{
    for(int i=0;i<100000000;i++)
    {
        QMutex mutex;
        mutex.lock();
        if(this->stop) break;
        mutex.unlock();

        emit numberChanged(i);
        this->msleep(100);
    }
}
