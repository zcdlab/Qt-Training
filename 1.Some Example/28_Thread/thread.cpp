#include "thread.h"

Thread::Thread()
{

}

void Thread::run()
{
    QMutex mutex;
        //qDebug()<<this->name<<"Running";
    for (int i=0;i<10000;i++)
    {
        mutex.lock();

        qDebug()<<this->name<<"  "<<i;
        mutex.unlock();
    }
}
