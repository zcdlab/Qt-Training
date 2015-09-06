
#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

template<typename T>
class SmartPointer
{
protected:
    T* m_pointer;
public:
    SmartPointer();
    SmartPointer(const T* pointer);
    ~SmartPointer();
    T* operator->();
    T& operator*();
};

#endif
