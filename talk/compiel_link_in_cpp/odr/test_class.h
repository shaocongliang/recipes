#ifndef test_class_H
#define test_class_H
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

static long int all_alloc = 0; // THIS will get linked in two times!

template <typename T>
class test_class
{
private:
    test_class() {}
    static test_class<T>* pinstance;

public:
    ~test_class() {}
    static test_class& instance() {
        if(pinstance == NULL) {
            pinstance = new test_class();
        }
        return *pinstance;
    }

    void throwIn(T item, const char* file, long line, const char* _compiler, long count) {
        int status;
        all_alloc += sizeof(T) * count ;
        std::cout<<"All memory:" << all_alloc << " all_alloc addr: " << &all_alloc << std::endl;
    }
};

template <class T> test_class<T>*  test_class<T>::pinstance = NULL;

#endif