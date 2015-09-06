#include <stdio.h>
#include "Array.h"

Array::Array(int length)
{
    if( length < 0 )
    {
        length = 0;
    }
    
    mLength = length;
    mSpace = new int[mLength];
}

Array::Array(const Array& obj)
{
    mLength = obj.mLength;
    
    mSpace = new int[mLength];
    
    for(int i=0; i<mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
}

int Array::length()
{
    return mLength;
}

Array::~Array()
{
    mLength = -1;
    printf("%08X\n", mSpace);
    delete[] mSpace;
}

int& Array::operator[](int i)
{
    return mSpace[i];
}

Array& Array::operator= (const Array& obj)
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

bool Array::operator== (const Array& obj)
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

bool Array::operator!= (const Array& obj)
{
    return !(*this == obj);
}

