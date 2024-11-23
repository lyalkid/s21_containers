#include <iostream>
// #include <list>

#include "list.h"

int main() {
  s21::list<int> mylist_ = {4, 1, 1, 2, 4, 3, 3, 4, 4};
  s21::list<int> mylist_2 = {2, 4, 12, 38};

  s21::list<int>::iterator it = mylist_.begin();
  ++it;
  mylist_.erase(it);

  for (s21::list<int>::iterator it = mylist_.begin(); it != mylist_.end();
       ++it) {
    std::cout << *it << " ";
  }

  return 0;
}

template <class T>
s21::list<T>::list() : size_(0), head_(nullptr), tail_(nullptr) {}

template <class T>
s21::list<T>::list(const std::initializer_list<value_type> &items)
    : size_(0), head_(nullptr), tail_(nullptr) {
  for (const auto &item : items) {
    push_back(item);
  }
}

template <class T>
void s21::list<T>::push_back(const_reference value) {
  Node *new_node = new Node(value, nullptr, tail_);
  if (head_ == nullptr) {
    head_ = new_node;
  } else {
    tail_->pNext = new_node;
  }
  tail_ = new_node;
  ++size_;
}

template <class T>
typename s21::list<T>::iterator s21::list<T>::begin() {
  return iterator(head_);
}

template <class T>
typename s21::list<T>::iterator s21::list<T>::end() {
  return iterator(nullptr);
}

template <class T>
const T &s21::list<T>::front() {
  return head_->data_;
}

template <class T>
s21::list<T>::~list() {
  clear();
}

template <class T>
void s21::list<T>::clear() {
  Node *current = head_;
  while (current) {
    Node *next = current->pNext;
    delete current;
    current = next;
  }
}

template <class T>
void s21::list<T>::sort() {
  if (size_ < 2) return;

  for (iterator it = this->begin(); it != this->end(); ++it) {
    for (iterator it_2 = this->begin(); it_2 != this->end(); ++it_2) {
      iterator next = it_2;
      ++next;

      if (next != this->end() && *next < *it_2) {
        std::swap(*it_2, *next);
      }
    }
  }
}

template <class T>
void s21::list<T>::merge(list<T> &other) noexcept {
  if (this == &other) return;
  if (other.head_ == nullptr) return;

  if (head_ == nullptr) {
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
  } else {
    tail_->pNext = other.head_;
    other.head_->pPrev = tail_;
    tail_ = other.tail_;
  }
  size_ += other.size_;

  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;

  this->sort();
}

template <class T>
void s21::list<T>::reverse() noexcept {
  Node *current = head_;
  Node *tmp_ = nullptr;

  while (current != nullptr) {
    tmp_ = current->pNext;
    current->pNext = current->pPrev;
    current->pPrev = tmp_;
    current = current->pPrev;
  }
  std::swap(head_, tail_);
}

template <class T>
void s21::list<T>::push_front(const_reference value) {
  Node *new_node = new Node(value, head_, nullptr);
  head_->pPrev = new_node;
  head_ = new_node;
  ++size_;
}

template <class T>
void s21::list<T>::unique() {
  Node *current = head_;
  while (current != nullptr) {
    Node *next = current->pNext;
    if (next != nullptr) {
      if (current->data_ == next->data_) {
        current->pNext = next->pNext;
        delete next;
      }
    }
    current = current->pNext;
  }
}

template <class T>
void s21::list<T>::erase(s21::list<T>::iterator pos) {
  Node current = pos.node_();
  Node prev = current.pPrev;

  if(current != nullptr){
    prev.pNext = current.pNext;
    delete current;
  }
}