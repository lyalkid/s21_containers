#ifndef CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_
#define CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_

#include <iostream>
#include <limits>

namespace s21 {
template <typename T>
class List {
 public:
  // List Member type
  using ValueType = T;
  using Reference = T &;
  using ConstReference = const T &;
  using SizeType = std::size_t;

  // Iterator
  class ListIterator;
  using Iterator = List<T>::ListIterator;
  using ConstIterator = const List<T>::ListIterator;

  // List Functions
  List();
  List(SizeType n);
  List(std::initializer_list<ValueType> const &items);
  List(const List &l) noexcept;
  List(List &&l) noexcept;
  ~List();

  // Operators
  List &operator=(const List &l);
  List &operator=(List &&l);
  bool operator==(List const &l);
  bool operator!=(List const &l);

  // List Element access
  ConstReference Front() const;
  ConstReference Back() const;

  // List Iterators
  Iterator Begin() const;
  Iterator End() const;

  // List Capacity
  bool Empty() const;
  SizeType Size() const;
  SizeType MaxSize() const;

  // List Modifiers
  void Clear();
  Iterator Insert(Iterator pos, ConstReference value);
  void Erase(Iterator pos);
  void PushBack(ConstReference value);
  void PopBack();
  void PushFront(ConstReference value);
  void PopFront();
  void Swap(List &other) noexcept;
  void Merge(List &other) noexcept;
  void Splice(ConstIterator pos, List &other);
  void Reverse() noexcept;
  void Unique();
  void Sort();

  // Insert many
  template <typename... Args>
  Iterator InsertMany(ConstIterator pos, Args &&...args) noexcept;
  template <typename... Args>
  void InsertManyBack(Args &&...args) noexcept;
  template <typename... Args>
  void InsertManyFront(Args &&...args) noexcept;

 protected:
  // List' node
  class Node {
   public:
    T data_;
    Node *p_next_;
    Node *p_prev_;
    Node(const T &data = T(), Node *p_next = nullptr, Node *p_prev = nullptr)
        : data_(data), p_next_(p_next), p_prev_(p_prev) {}
  };
  SizeType size_;
  Node *head_;
  Node *tail_;

 public:
  // Iterator
  class ListIterator {
   public:
    ListIterator(Node *node = nullptr) : current_(node) {};

    Reference operator*() const { return current_->data_; }

    ListIterator &operator++() {
      if (current_) current_ = current_->p_next_;
      return *this;
    }

    ListIterator &operator--() {
      if (current_) current_ = current_->p_prev_;
      return *this;
    }

    Node *GetCurrent() const { return current_; }

    bool operator==(const Iterator &other) const {
      return current_ == other.current_;
    }
    bool operator!=(const Iterator &other) const {
      return current_ != other.current_;
    }

   private:
    Node *current_;
  };
};
}  // namespace s21

#include "list.tpp"

#endif  // CPP_S21_CONTAINERS_1_SRC_LIST_LIST_H_
