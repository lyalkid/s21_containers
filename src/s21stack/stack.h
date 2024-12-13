#ifndef CPP_S21_CONTAINERS_1_SRC_STACK_STACK_H_
#define CPP_S21_CONTAINERS_1_SRC_STACK_STACK_H_

#include <iostream>

namespace s21{
    template <typename T>
class stack{
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = std::size_t;

        stack();
        stack(std::initializer_list<value_type> const &items);
        stack(const stack &s);
        stack(stack &&s);
        ~stack();
        stack &operator=(stack &&s);
        stack &operator=(const stack &s);

        const_reference top();

        bool empty();
        size_type size();

        void push(const_reference value);
        void pop();
        void swap(stack& other);
        void clear();

    private:
        size_type size_;
        class Node{
        public:
         T data_;
         Node *pNext;
         Node(const T& data = T(), Node *pNext = nullptr):
         data_(data), pNext(pNext){}
        };
        Node *head_;
    };
}


#include "stack.tpp"
#endif