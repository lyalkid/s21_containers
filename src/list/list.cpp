#include "list.h"

namespace s21 {
template <class T>
// List Functions
s21::list<T>::list() : size_(0), head_(nullptr), tail_(nullptr) {}

template <class T>
s21::list<T>::list(const std::initializer_list<value_type> &items)
    : size_(0), head_(nullptr), tail_(nullptr) {
  for (const auto &item : items) {
    push_back(item);
  }
}

template <class T>
s21::list<T>::list(const list &l) noexcept {
  if (l.head_ == nullptr) {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
  } else {
    Node *current = l.head_;
    while (current != nullptr) {
      push_back(current->data_);
      current = current->pNext;
    }
  }
}

template <class T>
s21::list<T>::list(list &&l) noexcept
    : size_(l.size_), head_(l.head_), tail_(l.tail_) {
  l.size_ = 0;
  l.head_ = nullptr;
  l.tail_ = nullptr;
}

template <class T>
s21::list<T>::~list() {
  clear();
}

// List Element access
template <class T>
const T &s21::list<T>::front() {
  return head_->data_;
}

template <class T>
const T &s21::list<T>::back() {
  return tail_->data_;
}

// List Iterator
template <class T>
typename s21::list<T>::iterator s21::list<T>::begin() {
  return iterator(head_);
}

template <class T>
typename s21::list<T>::iterator s21::list<T>::end() {
  return iterator(nullptr);
}

// List Capacity
template <class T>
bool s21::list<T>::empty() {
  return size_ == 0 ? true : false;
}

template <class T>
std::size_t s21::list<T>::size() {
  return size_;
}

template <class T>
std::size_t s21::list<T>::max_size() {
  return size_;
}

// List Modifiers
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
void s21::list<T>::erase(s21::list<T>::iterator pos) {
  Node current = pos.node_();
  Node prev = current.pPrev;

  if(current != nullptr){
  prev.pNext = current.pNext;
  delete current;
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
void s21::list<T>::pop_back() {
  if (head_ == nullptr) {
    throw std::out_of_range("Empty list");
  }
  if (head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
  } else {
    Node *tmp = tail_->pPrev;
    delete tail_;
    tmp->pNext = nullptr;
    tail_ = tmp;
  }
  --size_;
}

template <class T>
void s21::list<T>::push_front(const_reference value) {
  Node *new_node = new Node(value, head_, nullptr);
  head_->pPrev = new_node;
  head_ = new_node;
  ++size_;
}

template <class T>
void s21::list<T>::pop_front() {
  if (head_ == nullptr) {
    throw std::out_of_range("Empty list");
  }
  if (head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
  } else {
    Node *tmp = head_->pNext;
    delete head_;
    tmp->pPrev = nullptr;
    head_ = tmp;
  }
  --size_;
}

template <class T>
void s21::list<T>::swap(list<T> &other) noexcept {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
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

}  // namespace s21
