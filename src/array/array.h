#ifndef CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_
#define CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_
#include <iostream>

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;
  // Array Member functions
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array();
  array &operator=(const array &a) noexcept;
  array &operator=(array &&a) noexcept;
  // Array Element access
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  iterator data() noexcept;
  const_iterator data() const noexcept;
  // Array Iterators
  iterator begin() noexcept;
  iterator end() noexcept;
  // Array Capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  // Array Modifiers
  void swap(array &other) noexcept;
  void fill(const_reference value) noexcept;

 private:
  value_type arr_[N];
  size_type size_ = N;
};
}  // namespace s21

#include "array.tpp"
#endif  // CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_