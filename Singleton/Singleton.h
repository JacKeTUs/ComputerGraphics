#ifndef SINGLETON_H
#define SINGLETON_H

#include <stdio.h>

template <class T>
class Singleton
{
public:
    static T* getInstanse();
protected:
    Singleton() {}
private:
    static T* instanse;
};

template <class T>
T* Singleton<T>::instanse = NULL;

template <class T>
T *Singleton<T>::getInstanse()
{
    if (!instanse)
        instanse = new T;
    return instanse;
}

#endif // SINGLETON_H
