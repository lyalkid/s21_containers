#ifndef CPP_S21_CONTAINERS_1_SRC_QUEUE_QUEUE_H_
#define CPP_S21_CONTAINERS_1_SRC_QUEUE_QUEUE_H_


#include <iostream>
#include "../list/list.h"

namespace s21{
    template <typename T>
class queue : public list<T>{
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t;

        queue();
        queue(std::initializer_list<value_type> const &items);
        queue(const queue &q);
        queue(queue &&q);
        ~queue();

        queue &operator=(queue &&q);
        queue &operator=(const queue &q);

        using list<T>::front;
        using list<T>::back;

        using list<T>::empty;
        using list<T>::size;

        void push(const_reference value);
        void pop();
        using list<T>::swap;
    };
}

#include "queue.tpp"
#endif
