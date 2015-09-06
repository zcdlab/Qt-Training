#ifndef OVERLOAD
#define OVERLOAD




#include "person.h"
#include <QtCore>

QDataStream &operator<<(QDataStream &out, person &person);
QDataStream &operator>>(QDataStream &out, person &person);



QDataStream &operator<<(QDataStream &out, person &person)
{
    //Write a person class to stream
    out<<person.age<<person.name;
    return out;
}
QDataStream &operator>>(QDataStream &in, person &person)
{
    //Read in a person class from stream
    in>>person.age>>person.name;
    return in;

}

#endif // OVERLOAD

