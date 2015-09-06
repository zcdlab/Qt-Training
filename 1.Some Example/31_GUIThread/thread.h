#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = 0);

    void run();
    bool stop;

signals:
    void numberChanged(int num);

public slots:
};

#endif // THREAD_H
