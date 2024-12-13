#include "list.h"

namespace s21 {
template <class T>
s21::list<T>::list() : head_(nullptr), tail_(nullptr), size_(0) {}

template <class T>
s21::list<T>::list(SizeType n) : head_(nullptr), tail_(nullptr), size_(0) {
  for (SizeType i = 0; i < n; ++i) {
    push_back(T());
  }
}

template <class T>
s21::list<T>::list(const std::initializer_list<ValueType> &items)
    : head_(nullptr), tail_(nullptr), size_(0) {
  for (const auto &item : items) {
    push_back(item);
  }
}

template <class T>
s21::list<T>::list(const list &l) noexcept
    : head_(nullptr), tail_(nullptr), size_(0) {
  Node *current = l.head_;
  while (current != nullptr) {
    push_back(current->data_);
    current = current->p_next_;
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

template <class T>
s21::list<T> &s21::list<T>::operator=(list &&l) {
  if (this != &l) {
    this->clear();

    this->head_ = l.head_;
    this->tail_ = l.tail_;
    this->size_ = l.size_;

    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.size_ = 0;
  }
  return *this;
}

template <class T>
s21::list<T> &s21::list<T>::operator=(const list &l) {
  if (this != &l) {
    this->clear();

    Node *current = l.head_;
    while (current != nullptr) {
      this->push_back(current->data_);
      current = current->p_next_;
    }
  }
  return *this;
}

template <class T>
bool s21::list<T>::operator==(const list<T> &l) {
  if (size_ != l.size_) return false;

  Node *current = head_;
  Node *current_second = l.head_;

  while (current != nullptr) {
    if (current->data_ != current_second->data_) {
      return false;
    }
    current = current->p_next_;
    current_second = current_second->p_next_;
  }
  return true;
}

template <class T>
bool s21::list<T>::operator!=(const list<T> &l) {
  if (size_ != l.size_) return true;

  Node *current = head_;
  Node *current_second = l.head_;

  while (current != nullptr) {
    if (current->data_ != current_second->data_) {
      return true;
    }
    current = current->p_next_;
    current_second = current_second->p_next_;
  }
  return false;
}

template <class T>
const T &s21::list<T>::front() const {
  return head_->data_;
}

template <class T>
const T &s21::list<T>::back() const {
  return tail_->data_;
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
bool s21::list<T>::empty() const {
  return size_ == 0 ? true : false;
}

template <class T>
std::size_t s21::list<T>::size() const {
  return size_;
}

// TODO: уточнить что должно выводиться
template <class T>
std::size_t s21::list<T>::max_size() const {
  constexpr auto max_size = std::numeric_limits<std::size_t>::max();
  return max_size / sizeof(T) / 2;
}

// list Modifiers
template <class T>
void s21::list<T>::clear() {
  Node *current = head_;
  while (current != nullptr) {
    Node *next = current->p_next_;
    delete current;
    current = next;
  }
  head_ = nullptr;
  tail_ = nullptr;
  size_ = 0;
}

template <class T>
typename s21::list<T>::iterator s21::list<T>::insert(iterator pos,
                                                     ConstReference value) {
  Node *current = pos.GetCurrent();
  if (current == head_) {
    push_front(value);
    return (head_);
  } else if (current == nullptr) {
    push_back(value);
    return (tail_);
  } else {
    Node *prev_node = current->p_prev_;
    Node *new_node = new Node(value, nullptr, nullptr);

    prev_node->p_next_ = new_node;
    new_node->p_next_ = current;

    current->p_prev_ = new_node;
    new_node->p_prev_ = prev_node;
    size_++;
    return iterator(new_node);
  }
}

template <class T>
void s21::list<T>::erase(iterator pos) {
  Node *delete_node = pos.GetCurrent();
  if (delete_node == nullptr) {
    return;
  }

  Node *prev_node = delete_node->p_prev_;
  Node *next_node = delete_node->p_next_;

  if (delete_node == head_) {
    head_ = next_node;
    if (head_ != nullptr) {
      head_->p_prev_ = nullptr;
    }
  } else if (delete_node == tail_) {
    tail_ = prev_node;
    if (tail_ != nullptr) {
      tail_->p_next_ = nullptr;
    }
  } else {
    prev_node->p_next_ = next_node;
    next_node->p_prev_ = prev_node;
  }

  delete delete_node;
  --size_;
}

template <class T>
void s21::list<T>::push_back(ConstReference value) {
  Node *new_node = new Node(value, nullptr, tail_);
  if (head_ == nullptr) {
    head_ = new_node;
  } else {
    tail_->p_next_ = new_node;
  }
  tail_ = new_node;
  ++size_;
}

template <class T>
void s21::list<T>::pop_back() {
  if (head_ == nullptr) {
    return;
  }
  if (head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
  } else {
    Node *tmp = tail_->p_prev_;
    delete tail_;
    tmp->p_next_ = nullptr;
    tail_ = tmp;
  }
  --size_;
}

template <class T>
void s21::list<T>::push_front(ConstReference value) {
  Node *new_node = new Node(value, head_, nullptr);
  if (head_ == nullptr) {
    head_ = new_node;
  } else {
    head_->p_prev_ = new_node;
    head_ = new_node;
  }
  ++size_;
}

template <class T>
void s21::list<T>::pop_front() {
  if (head_ == nullptr) {
    return;
  }
  if (head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
  } else {
    Node *tmp = head_->p_next_;
    delete head_;
    tmp->p_prev_ = nullptr;
    head_ = tmp;
  }
  --size_;
}

template <class T>
void s21::list<T>::swap(list &other) noexcept {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}

template <class T>
void s21::list<T>::merge(list &other) noexcept {
  if (this == &other) return;
  if (other.head_ == nullptr) return;

  if (head_ == nullptr) {
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
  } else {
    tail_->p_next_ = other.head_;
    other.head_->p_prev_ = tail_;
    tail_ = other.tail_;
  }
  size_ += other.size_;

  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;

  this->sort();
}

template <class T>
void s21::list<T>::splice(ConstIterator pos, list &other) {
  if (head_ == nullptr) {
    *this = std::move(other);
    return;
  }

  Node *current = pos.GetCurrent();
  Node *prev_node = current->p_prev_;
  Node *second_list = other.head_;

  while (second_list != nullptr) {
    Node *new_node = new Node(second_list->data_, current, prev_node);
    if (prev_node != nullptr) {
      prev_node->p_next_ = new_node;
    } else {
      head_ = new_node;
    }

    if (current != nullptr) {
      current->p_prev_ = new_node;
    } else {
      tail_ = new_node;
    }

    prev_node = new_node;
    second_list = second_list->p_next_;
  }

  size_ += other.size_;
  other.clear();
}

template <class T>
void s21::list<T>::reverse() noexcept {
  Node *current = head_;
  Node *tmp_ = nullptr;

  while (current != nullptr) {
    tmp_ = current->p_next_;
    current->p_next_ = current->p_prev_;
    current->p_prev_ = tmp_;
    current = current->p_prev_;
  }
  std::swap(head_, tail_);
}

template <class T>
void s21::list<T>::unique() {
  Node *current = head_;
  while (current != nullptr) {
    Node *next = current->p_next_;
    if (next != nullptr) {
      if (current->data_ == next->data_) {
        current->p_next_ = next->p_next_;
        delete next;
        --size_;
      }
    }
    current = current->p_next_;
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
