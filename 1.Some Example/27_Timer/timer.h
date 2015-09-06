#ifndef TIMER_H
#define TIMER_H

#include <QtCore>
class Timer :QObject
{

    Q_OBJECT

public:
    Timer();

    QTimer *timer;


public slots:
    void timerSlot();
};

#endif // TIMER_H
