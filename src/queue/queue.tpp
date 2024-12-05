#include "queue.h"

template <class T>
s21::queue<T>::queue() : list<T>() {}

template <class T>
s21::queue<T>::queue(const std::initializer_list<value_type> &items) : list<T>(items){}

template <class T>
s21::queue<T>::queue(const queue<T> &q): list<T>(q){}

template <class T>
s21::queue<T>::queue(queue<T> &&q) : list<T>(&q) {}

template <class T>
s21::queue<T>::~queue(){
    list<T>::clear();
}

template <class T>
s21::queue<T> &s21::queue<T>::operator=(queue&& q) {
    list<T>::operator=(std::move(q));
    return *this;
}

template<class T>
s21::queue<T> &s21::queue<T>::operator=(const queue &q){
    list<T>::operator=(std::move(q));
    return *this;
}

template <class T>
void s21::queue<T>::push(const_reference value){
    list<T>::push_back(value);
}

template <class T>
void s21::queue<T>::pop() {
    list<T>::pop_front();
}

