#include "widget.h"
#include <QApplication>
#include "connection.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnection())
        return 0;
    Widget w;
    w.show();

    return a.exec();
}
