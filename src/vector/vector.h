#ifndef CPP2_S21_CONTAINERS_1_SRC_VECTOR_VECTOR_H_
#define CPP2_S21_CONTAINERS_1_SRC_VECTOR_VECTOR_H_

#include <iostream>

namespace s21 {
template <typename T>
class vector {
 public:
  // Vector Member type
  using value_type = T;
  using unique_ptr = std::unique_ptr<value_type[]>;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;
  // Vector Member functions
  vector();
  explicit vector(size_type n);
  ~vector() = default;
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  vector &operator=(const vector &v) noexcept;
  vector &operator=(vector &&v) noexcept;
  // Vector Element access
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos) noexcept;
  const_reference operator[](size_type pos) const noexcept;
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  iterator data() noexcept;
  const_iterator data() const noexcept;
  // Vector Iterators
  iterator begin() noexcept;
  iterator end() const noexcept;
  // Vector Capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void reserve(size_type size);
  size_type capacity() const noexcept;
  void shrink_to_fit() noexcept;
  // Vector Modifiers
  void clear() noexcept;
  iterator insert(iterator pos, const_reference value) noexcept;
  void erase(iterator pos) noexcept;
  void push_back(const_reference value) noexcept;
  void pop_back() noexcept;
  void swap(vector &other) noexcept;
  // Insert Many
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) noexcept;
  template <typename... Args>
  void insert_many_back(Args &&...args) noexcept;

 private:
  unique_ptr arr_;
  size_type size_, capacity_;
};
}  // namespace s21

namespace s21 {
template <class T>
template <class... Args>
T *s21::vector<T>::insert_many(const_iterator pos, Args &&...args) noexcept {}

template <class T>
template <class... Args>
void s21::vector<T>::insert_many_back(Args &&...args) noexcept {}
}  // namespace s21
#include "vector.tpp"
#endif  // CPP2_S21_CONTAINERS_1_SRC_VECTOR_VECTOR_H_