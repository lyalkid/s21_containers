#ifndef CPP_S21_CONTAINERS_1_SRC_QUEUE_QUEUE_H_
#define CPP_S21_CONTAINERS_1_SRC_QUEUE_QUEUE_H_

#include <iostream>

#include "../s21list/list.h"

namespace s21 {
template <typename T>
class Queue : protected List<T> {
 public:
  // Queue Member type
  using ValueType = T;
  using Reference = T &;
  using ConstReference = const T &;
  using SizeType = size_t;

  // Queue Member functions
  Queue();
  Queue(std::initializer_list<ValueType> const &items);
  Queue(const Queue &q);
  Queue(Queue &&q);
  ~Queue();

  // Operators
  Queue &operator=(Queue &&q);
  Queue &operator=(const Queue &q);

  // Queue Element access
  using List<T>::Front;
  using List<T>::Back;

  // Queue Capacity
  using List<T>::Empty;
  using List<T>::Size;

  // Queue Modifiers
  void Push(ConstReference value);
  void Pop();
  void Swap(Queue &other) noexcept;

  // Insert mane
  using List<T>::InsertManyBack;
};
}  // namespace s21

#include "queue.tpp"
#endif
