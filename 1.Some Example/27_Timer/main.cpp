#include <QCoreApplication>
#include "timer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Timer mTimer;

    return a.exec();
}
