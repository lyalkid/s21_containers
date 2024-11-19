#ifndef CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_
#define CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_

#include <iostream>

namespace s21 {
    template <typename T>
class list{
public:
    //List Member type
//    class LisIterator;
//    class ListConstIterator;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
//    using iterator = LisIterator <T>;
//    using const_iterator = ListConstIterator <T>;
    using size_type = std::size_t;

    //List Functions
    list();
    list(size_type n);
    list(std::initializer_list<value_type> const &items);
    list(const list &l) noexcept;
    list(list &&l) noexcept;
    ~list();
//    operator=(list &&l);

    //List Element access
    const_reference front();
    const_reference back();

    //List Iterators
//    iterator begin();
//    iterator end();

    //List Capacity
    bool empty();
    size_type size();
    size_type max_size();

    //List Modifiers
    void clear();
//    iterator insert(iterator pos, const_reference value);
//    void erase(iterator pos);
    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();
    void swap(list& other) noexcept;
    void merge(list& other) noexcept;
//    void splice(const_iterator pos, list& other);
    void reverse();
    void unique();
    void sort();

private:
    value_type list_;
    size_type size_;
    class Node{
    public:
        Node *pNext;
        Node *pPrev;
        T data;
        Node(const T& data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
            : data(data), pNext(pNext), pPrev(pPrev){}
    };
    Node *head_;
    Node *tail_;

};
}

#include "list.cpp"
#endif