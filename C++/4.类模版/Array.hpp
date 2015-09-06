
#ifndef _ARRAY_DEF_H_
#define _ARRAY_DEF_H_

#include "Array.h"

template<typename T>
Array<T>::Array(int length)
{
    if( length < 0 )
    {
        length = 0;
    }
    
    mLength = length;
    mSpace = new T[mLength];
}

template<typename T>
Array<T>::Array(const Array& obj)
{
    mLength = obj.mLength;
    
    mSpace = new int[mLength];
    
    for(int i=0; i<mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
}

template<typename T>
int Array<T>::length()
{
    return mLength;
}

template<typename T>
Array<T>::~Array()
{
    mLength = -1;
    
    delete[] mSpace;
}

template<typename T>
T& Array<T>::operator[](int i)
{
    return mSpace[i];
}

template<typename T>
Array<T>& Array<T>::operator= (const Array<T>& obj)
{
    delete[] mSpace;
    
    mLength = obj.mLength;
    
    mSpace = new int[mLength];
    
    for(int i=0; i<mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
    
    return *this;
}

template<typename T>
bool Array<T>::operator== (const Array<T>& obj)
{
    bool ret = true;
    
    if( mLength == obj.mLength )
    {
        for(int i=0; i<mLength; i++)
        {
            if( mSpace[i] != obj.mSpace[i] )
            {
                ret = false;
                break;
            }
        }
    }
    else
    {
        ret = false;
    }
    
    return ret;
}

template<typename T>
bool Array<T>::operator!= (const Array& obj)
{
    return !(*this == obj);
}

#endif

