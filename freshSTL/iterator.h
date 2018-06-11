//
// Created by mark on 16-12-19.
//

#ifndef STL_ITERATOR_H
#define STL_ITERATOR_H
#include <stddef.h>
namespace sctoys{
    struct input_iterator_tag{ };
    struct output_iterator_tag{ };
    struct forward_iterator_tag : public input_iterator_tag{ };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag{ };

    template <typename Category, typename T, typename Distance = ptrdiff_t , typename Pointer = T*, typename Reference = T&>
    struct input_iteator{
        typedef Category iterator_category;
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
    };

    template <typename Category, typename T, typename Distance = ptrdiff_t , typename Pointer = T*, typename Reference = T&>
    struct forward_iteator{
        typedef Category iterator_category;
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
    };

    template <typename Category, typename T, typename Distance = ptrdiff_t , typename Pointer = T*, typename Reference = T&>
    struct bidirectional_iterator{
        typedef Category iterator_category;
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
    };

    template <typename Category, typename T, typename Distance = ptrdiff_t , typename Pointer = T*, typename Reference = T&>
    struct random_access_iterator{
        typedef Category iterator_category;
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
    };

    template <typename Iterator>
    struct iterator{
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };
    template <typename T>
    struct iterator<T*> {
        typedef random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_tyep;
        typedef T* pointer_type;
        typedef T& reference;
    };

    template <typename Iterator>
    struct iterator_traits{
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };

    template <typename Iterator, typename Distance>
    void __advance(Iterator &it, Distance n, const input_iterator_tag &itertag){
        while(n--) {
            it++;
        }
    }

    template <typename Iterator, typename Distance>
    void __advance(Iterator &it, Distance n, const random_access_iterator_tag &itertag){
        it += n;
    } 
    template <typename Iterator, typename Distance>
    void advance(Iterator &it, Distance n) {

    }
}
#endif //MY_PRINTF_ITERATOR_H
