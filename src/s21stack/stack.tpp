#include "stack.h"

namespace s21 {
template <class T>
Stack<T>::Stack() : size_(0), head_(nullptr) {}

template <class T>
Stack<T>::Stack(const std::initializer_list<ValueType> &items)
    : size_(0), head_(nullptr) {
  for (const auto &item : items) {
    Push(item);
  }
}

template <class T>
Stack<T>::Stack(const Stack &s) : size_(0), head_(nullptr) {
  Stack<int> tmp_stack;
  Node *current = s.head_;
  while (current) {
    tmp_stack.Push(current->data_);
    current = current->p_next_;
  }
  while (!tmp_stack.Empty()) {
    this->Push(tmp_stack.Top());
    tmp_stack.Pop();
  }
}

template <class T>
Stack<T>::Stack(Stack &&s) : size_(s.size_), head_(s.head_) {
  s.size_ = 0;
  s.head_ = nullptr;
}

template <class T>
Stack<T>::~Stack() {
  Clear();
}

template <class T>
Stack<T> &Stack<T>::operator=(Stack &&s) {
  if (this != &s) {
    this->head_ = s.head_;
    this->size_ = s.size_;

    s.head_ = nullptr;
    s.size_ = 0;
  }
  return *this;
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack &s) {
  if (this != &s) {
    this->Clear();

    s21::Stack<T> tmp_stack;
    Node *current = s.head_;
    while (current != nullptr) {
      tmp_stack.Push(current->data_);
      current = current->p_next_;
    }

    while (!tmp_stack.Empty()) {
      this->Push(tmp_stack.Top());
      tmp_stack.Pop();
    }
  }
  return *this;
}

template <class T>
const T &Stack<T>::Top() const {
  return head_->data_;
}

template <class T>
bool Stack<T>::Empty() const {
  return size_ == 0 ? true : false;
}

template <class T>
size_t Stack<T>::Size() const {
  return size_;
}

template <class T>
void Stack<T>::Push(ConstReference value) {
  Node *new_node = new Node(value, head_);
  if (head_ == nullptr) {
    head_ = new_node;
  } else {
    new_node->p_next_ = head_;
    head_ = new_node;
  }
  ++size_;
}

template <class T>
void Stack<T>::Pop() {
  if (head_ == nullptr) return;
  Node *next_node = head_->p_next_;
  delete head_;
  head_ = next_node;
  --size_;
}

template <class T>
void Stack<T>::Swap(Stack &other) {
  std::swap(head_, other.head_);
  std::swap(size_, other.size_);
}

template <class T>
void Stack<T>::Clear() {
  Node *current = head_;
  while (current != nullptr) {
    Node *next_node = current->p_next_;
    delete current;
    current = next_node;
  }
  head_ = nullptr;
  size_ = 0;
}

template <class T>
template <class... Args>
void Stack<T>::InsertManyBack(Args &&...args) noexcept {
  Stack<ValueType> tmp_stack = {args...};

  Stack<ValueType> tmp_stack_rev;
  Node *current = tmp_stack.head_;
  while (current != nullptr) {
    tmp_stack_rev.Push(current->data_);
    current = current->p_next_;
  }

  while (!tmp_stack_rev.Empty()) {
    this->Push(tmp_stack_rev.Top());
    tmp_stack_rev.Pop();
  }
}

}  // namespace s21