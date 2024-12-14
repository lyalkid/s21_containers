#include "queue.h"

template <class T>
s21::Queue<T>::Queue() : List<T>() {}

template <class T>
s21::Queue<T>::Queue(const std::initializer_list<ValueType> &items)
    : List<T>(items) {}

template <class T>
s21::Queue<T>::Queue(const Queue<T> &q) : List<T>(q) {}

template <class T>
s21::Queue<T>::Queue(Queue<T> &&q) : List<T>(q) {}

template <class T>
s21::Queue<T>::~Queue() {
  List<T>::Clear();
}

template <class T>
s21::Queue<T> &s21::Queue<T>::operator=(Queue &&q) {
  List<T>::operator=(std::move(q));
  return *this;
}

template <class T>
s21::Queue<T> &s21::Queue<T>::operator=(const Queue &q) {
  List<T>::operator=(std::move(q));
  return *this;
}

template <class T>
void s21::Queue<T>::Push(ConstReference value) {
  List<T>::PushBack(value);
}

template <class T>
void s21::Queue<T>::Pop() {
  List<T>::PopFront();
}

template <class T>
void s21::Queue<T>::Swap(Queue &other) noexcept {
  List<T>::Swap(other);
}
