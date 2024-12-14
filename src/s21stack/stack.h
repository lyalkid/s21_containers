#ifndef CPP_S21_CONTAINERS_1_SRC_STACK_STACK_H_
#define CPP_S21_CONTAINERS_1_SRC_STACK_STACK_H_

#include <iostream>

namespace s21 {
template <typename T>
class Stack {
 public:
  // Stack Member type
  using ValueType = T;
  using Reference = T &;
  using ConstReference = const T &;
  using SizeType = std::size_t;

  // Stack Functions
  Stack();
  Stack(std::initializer_list<ValueType> const &items);
  Stack(const Stack &s);
  Stack(Stack &&s);
  ~Stack();

  // Operators
  Stack &operator=(Stack &&s);
  Stack &operator=(const Stack &s);

  // Stack Element access
  ConstReference Top() const;

  // Stack Capacity
  bool Empty() const;
  SizeType Size() const;

  // Stack Modifiers
  void Push(ConstReference value);
  void Pop();
  void Swap(Stack &other);
  void Clear();

  // Insert many
  template <typename... Args>
  void InsertManyBack(Args &&...args) noexcept;

 private:
  class Node {
   public:
    T data_;
    Node *p_next_;
    Node(const T &data = T(), Node *p_next = nullptr)
        : data_(data), p_next_(p_next) {}
  };
  SizeType size_;
  Node *head_;
};
}  // namespace s21

#include "stack.tpp"

#endif  // CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_