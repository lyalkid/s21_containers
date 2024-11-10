#ifndef CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_
#define CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_
#include <iostream>
#include <limits>

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

  array();
  array(std::initializer_list<value_type> const &items);

  iterator begin();
  iterator end();

  size_type size();

  reference operator[](size_type item);

 private:
  T arr_[N];
  std::size_t size_ =
      N;  // ISO C++ forbids zero-size array, -pedantic флаг не пропускает
};
}  // namespace s21

namespace s21 {

template <class T, std::size_t N>
array<T, N>::array() : size_(N) {}
//краевые случаи - ноль и макс +
// TODO: как я могу работать с обработкой ошибок компиляции?

template <class T, std::size_t N>
array<T, N>::array(const std::initializer_list<T> &items) {
  std::copy(items.begin(), items.end(),
            arr_);  // TODO: arr_.begin() -  y not working?
}

template <class T, std::size_t N>
T *array<T, N>::begin() {
  return arr_;
}

template <class T, std::size_t N>
T *array<T, N>::end() {
  return arr_ + size_;
}

template <class T, std::size_t N>
std::size_t array<T, N>::size() {
  return size_;
}

template <class T, std::size_t N>
T &array<T, N>::operator[](std::size_t item) {
  if (item >= size_) {
    throw std::out_of_range("Array is out of bound");
  }
  return arr_[item];
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_