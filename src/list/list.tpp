#include "list.h"

namespace s21 {
template <class T>
s21::List<T>::List() : size_(0), head_(nullptr), tail_(nullptr) {}

template <class T>
s21::List<T>::List(SizeType n) : size_(0), head_(nullptr), tail_(nullptr){
    for(SizeType i = 0; i < n; ++i){
        PushBack(T());
    }
}

template <class T>
s21::List<T>::List(const std::initializer_list<ValueType> &items)
    : size_(0), head_(nullptr), tail_(nullptr) {
  for (const auto &item : items) {
        PushBack(item);
  }
}

template <class T>
s21::List<T>::List(const List &l) noexcept :  size_(0), head_(nullptr), tail_(nullptr){
    Node *current = l.head_;
    while (current != nullptr) {
    PushBack(current->data_);
      current = current->p_next_;
    }
  }

template <class T>
s21::List<T>::List(List &&l) noexcept
    : size_(l.size_), head_(l.head_), tail_(l.tail_) {
  l.size_ = 0;
  l.head_ = nullptr;
  l.tail_ = nullptr;
}

template <class T>
s21::List<T>::~List() {
  Clear();
}

template <class T>
s21::List<T> &s21::List<T>::operator=(List &&l){
  if(this != &l){
      this->Clear();

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
s21::List<T> &s21::List<T>::operator=(const List &l){
  if(this != &l){
    this->Clear();

    Node *current = l.head_;
    while (current != nullptr){
        this->PushBack(current->data_);
      current = current->p_next_;
    }
  }
  return  *this;
}

template <class T>
bool s21::List<T>::operator==(const List<T> &l){
  if(size_ != l.size_) return false;

  Node *current = head_;
  Node *current_second = l.head_;

  while (current != nullptr){
    if(current->data_ != current_second->data_){
      return false;
    }
    current = current->p_next_;
    current_second = current_second->p_next_;
  }
  return true;
}

template <class T>
bool s21::List<T>::operator!=(const List<T> &l) {
  if(size_ != l.size_) return true;

  Node *current = head_;
  Node *current_second = l.head_;

  while (current != nullptr){
    if(current->data_ != current_second->data_){
      return true;
    }
    current = current->p_next_;
    current_second = current_second->p_next_;
  }
  return false;
}


template <class T>
const T &s21::List<T>::Front() const{
  return head_->data_;
}

template <class T>
const T &s21::List<T>::Back() const{
  return tail_->data_;
}


template <class T>
typename s21::List<T>::Iterator s21::List<T>::Begin() {
  return Iterator(head_);
}

template <class T>
typename s21::List<T>::Iterator s21::List<T>::End() {
  return Iterator(nullptr);
}


template <class T>
bool s21::List<T>::Empty() const{
  return size_ == 0 ? true : false;
}

template <class T>
std::size_t s21::List<T>::Size() const{
  return size_;
}

// TODO: уточнить что должно выводиться
template <class T>
std::size_t s21::List<T>::MaxSize() const{
  constexpr auto max_size = std::numeric_limits<std::size_t>::max();
  return max_size/ sizeof(T)/2;
}

// List Modifiers
template <class T>
void s21::List<T>::Clear() {
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
typename s21::List<T>::Iterator s21::List<T>::Insert(Iterator pos, ConstReference value) {
  Node *current = pos.GetCurrent();
  if (current == head_){
    PushFront(value);
    return (head_);
  }else if(current == nullptr){
    PushBack(value);
    return (tail_);
  }else{
    Node *prev_node = current->p_prev_;
    Node *new_node = new Node(value, nullptr, nullptr);

    prev_node->p_next_ = new_node;
    new_node->p_next_ = current;

    current->p_prev_ = new_node;
    new_node->p_prev_ = prev_node;
    size_++;
    return Iterator(new_node);
  }
}


template <class T>
void s21::List<T>::Erase(Iterator pos) {
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
void s21::List<T>::PushBack(ConstReference value) {
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
void s21::List<T>::PopBack() {
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
void s21::List<T>::PushFront(ConstReference value) {
  Node *new_node = new Node(value, head_, nullptr);
  if(head_ == nullptr){
    head_ = new_node;
  }else {
    head_->p_prev_ = new_node;
    head_ = new_node;
  }
  ++size_;
}

template <class T>
void s21::List<T>::PopFront() {
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
void s21::List<T>::Swap(List &other) noexcept {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}

template <class T>
void s21::List<T>::Merge(List &other) noexcept {
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

  this->Sort();
}


template <class T>
void s21::List<T>::Splice(ConstIterator pos, List &other) {

  if(head_ == nullptr){
    *this = std::move(other);
    return;
  }

Node *current = pos.GetCurrent();
Node *prev_node = current->p_prev_;
Node *second_list = other.head_;

while(second_list != nullptr){
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
other.Clear();
}

template <class T>
void s21::List<T>::Reverse() noexcept {
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
void s21::List<T>::Unique() {
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
void s21::List<T>::Sort() {
  if (size_ < 2) return;

  for (Iterator it = this->Begin(); it != this->End(); ++it) {
    for (Iterator it_2 = this->Begin(); it_2 != this->End(); ++it_2) {
      Iterator next = it_2;
      ++next;

      if (next != this->End() && *next < *it_2) {
        std::swap(*it_2, *next);
      }
    }
  }
}

}  // namespace s21
