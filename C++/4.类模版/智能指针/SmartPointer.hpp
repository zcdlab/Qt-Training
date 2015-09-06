
#ifndef _SMARTPOINTER_DEF_H_
#define _SMARTPOINTER_DEF_H_

#include "SmartPointer.h"

template<typename T>
SmartPointer<T>::SmartPointer()
{
    m_pointer = NULL;
}

template<typename T>
SmartPointer<T>::SmartPointer(const T* pointer)
{
    m_pointer = const_cast<T*>(pointer);
}

template<typename T>
SmartPointer<T>::~SmartPointer()
{
    delete m_pointer;
}

template<typename T>
T* SmartPointer<T>::operator->()
{
    return m_pointer;
}

template<typename T>
T& SmartPointer<T>::operator*()
{
    return *m_pointer;    
}    

#endif
