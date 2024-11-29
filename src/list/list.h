#ifndef CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_
#define CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_

#include <iostream>
#include <limits>

namespace s21 {
    template <typename T>
class list{
public:
    class ListIterator;
    //List Member type
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = list<T>::ListIterator;
    using const_iterator = const list<T>::ListIterator;
    using size_type = std::size_t;

    //List Functions
    list();
    list(size_type n);
    list(std::initializer_list<value_type> const &items);
    list(const list &l) noexcept;
    list(list &&l) noexcept;
    ~list();

    list &operator=(list &&l);
    list &operator=(const list &l);
    bool operator==(list const &l);
    bool operator!=(list const &l);


    //List Element access
    const_reference front();
    const_reference back();

    //List Iterators
    iterator begin();
    iterator end();

    //List Capacity
    bool empty();
    size_type size();
    size_type max_size();

    //List Modifiers
    void clear();
    iterator insert(iterator pos, const_reference value);
    void erase(iterator pos);
    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();
    void swap(list& other) noexcept;
    void merge(list& other) noexcept;
    void splice(const_iterator pos, list& other);
    void reverse() noexcept;
    void unique();
    void sort();

protected:
    value_type list_;
    size_type size_;
    class Node{
    public:
        Node *pNext;
        Node *pPrev;
        T data_;
        Node(const T& data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
            : data_(data), pNext(pNext), pPrev(pPrev){}
    };
    Node *head_;
    Node *tail_;

public:
    class ListIterator {
    public:
        ListIterator(Node* node = nullptr) : current(node) {};

        reference operator *() const {return current->data_;}
//TODO:: добавить обработку на итерацию с последнего/первого элемента
        ListIterator & operator++(){
        if(current) current = current->pNext;
        return *this;
    }

    ListIterator & operator--(){
        if(current) current = current->pPrev;
        return *this;
    }

    Node* getCurrent() const { return current;}

    bool operator==(const iterator& other) const {return current == other.current;}
    bool operator!=(const iterator& other) const {return current != other.current;}

private:
        Node* current;
    };
};
}

#include "list.tpp"
#endif