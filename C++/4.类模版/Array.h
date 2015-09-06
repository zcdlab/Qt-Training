
#ifndef _ARRAY_H_
#define _ARRAY_H_

template<typename T>
class Array
{
private:
    int mLength;
    T* mSpace;

public:
    Array(int length);
    Array(const Array& obj);
    int length();
    ~Array();
    T& operator[](int i);
    Array& operator= (const Array& obj);
    bool operator== (const Array& obj);
    bool operator!= (const Array& obj);
};

#endif
