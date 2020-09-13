// util.h
#ifndef _UTIL_H_
#define _UTIL_H_

#include <memory.h>
#include <string>

#include "test_class.h"

template <class T> T* allocate(size_t count, const char* f, long l, const char* sth)
{
    T* tmp = new T[count];
    memset(tmp, 0, count * sizeof(T));
    test_class<T*>::instance().throwIn(tmp, f, l, sth, count);
    return tmp;
}

#define alloc_mem(type,count) allocate<type>(count, __FILE__, __LINE__, (char*)0)

#endif