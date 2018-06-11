#ifndef VECTOR_H
#define VECTOR_H
#include "iterator.h"
namespace sctoys{
    template <typename T>
    class Vector{
        iterator<random_access_iterator<random_access_iterator_tag, T> > iter_;
    };
};
#endif