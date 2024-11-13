#ifndef CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_TPP_
#define CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_TPP_
#include "array.h"

namespace s21 {
// Array Member functions
template <class T, std::size_t N>
array<T, N>::array() : size_(N) {}

template <class T, std::size_t N>
array<T, N>::array(const std::initializer_list<T> &items) {
  std::copy(items.begin(), items.end(), arr_);
}

template <class T, std::size_t N>
array<T, N>::array(const array<T, N> &a) {
  std::copy(a.arr_, a.arr_ + N, arr_);
}

template <class T, std::size_t N>
array<T, N>::array(array<T, N> &&a) {
  std::move(a.arr_, a.arr_ + N, arr_);
}

template <class T, std::size_t N>
array<T, N>::~array() {}

template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(const array<T, N> &a) noexcept {
  if (this != &a) {
    std::copy(a.arr_, a.arr_ + N, arr_);
  }
  return *this;
}

template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(array<T, N> &&a) noexcept {
  if (this != &a) {
    std::move(a.arr_, a.arr_ + N, arr_);
  }
  return *this;
}

// Array Element access
template <class T, std::size_t N>
T &array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("You went out of range (at)");
  }
  return arr_[pos];
}

template <class T, std::size_t N>
const T &array<T, N>::at(size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("You went out of range (at)");
  }
  return arr_[pos];
}

template <class T, std::size_t N>
T &array<T, N>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Array is out of bound (operator[])");
  }
  return arr_[pos];
}

template <class T, std::size_t N>
const T &array<T, N>::operator[](size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Array is out of bound operator[]");
  }
  return arr_[pos];
}

template <class T, std::size_t N>
const T &array<T, N>::front() const noexcept {
  return arr_[0];
}

template <class T, std::size_t N>
const T &array<T, N>::back() const noexcept {
  return arr_[N - 1];
}

template <class T, std::size_t N>
T *array<T, N>::data() noexcept {
  return arr_;
}

template <class T, std::size_t N>
const T *array<T, N>::data() const noexcept {
  return arr_;
}

// Array Iterators
template <class T, std::size_t N>
T *array<T, N>::begin() noexcept {
  return arr_;
}

template <class T, std::size_t N>
T *array<T, N>::end() noexcept {
  return arr_ + size_;
}

// Array Capacity
template <class T, std::size_t N>
bool array<T, N>::empty() const noexcept {
  return size_ == 0 ? true : false;
}

template <class T, std::size_t N>
std::size_t array<T, N>::size() const noexcept {
  return size_;
}

template <class T, std::size_t N>
std::size_t array<T, N>::max_size() const noexcept {
  return size_;
}

// Array Modifiers
template <class T, std::size_t N>
void array<T, N>::swap(array<T, N> &other) noexcept {
  std::swap_ranges(arr_, arr_ + N, other.arr_);
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) noexcept {
  std::fill(arr_, arr_ + N, value);
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_TPP_