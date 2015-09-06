#include "timer.h"

#include <QtCore>
#include <QDebug>
Timer::Timer()
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
    timer->start(1000);
}


void Timer::timerSlot()
{
    qDebug()<<"timer executed!";
}
