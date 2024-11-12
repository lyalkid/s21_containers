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
array<T, N> &array<T, N>::operator=(const array<T, N> &other) {
  if (this != &other) {
    std::copy(other.arr_, other.arr_ + N, arr_);
  }
  return *this;
}
template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(array<T, N> &&other) {
  if (this != &other) {
    std::move(other.arr_, other.arr_ + N, arr_);
  }
  return *this;
}
// Array Element access
template <class T, std::size_t N>
T &array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Array size is less that you think!");
  }
  return arr_[pos];
}
template <class T, std::size_t N>
const T &array<T, N>::at(size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Array size is less that you think!");
  }
  return arr_[pos];
}
template <class T, std::size_t N>
T &array<T, N>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Array is out of bound");
  }
  return arr_[pos];
}
template <class T, std::size_t N>
const T &array<T, N>::operator[](size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Array is out of bound");
  }
  return arr_[pos];
}
template <class T, std::size_t N>
const T &array<T, N>::front() {
  return arr_[0];
}
template <class T, std::size_t N>
const T &array<T, N>::front() const {
  return arr_[0];
}
template <class T, std::size_t N>
const T &array<T, N>::back() {
  return arr_[N - 1];
}
template <class T, std::size_t N>
const T &array<T, N>::back() const {
  return arr_[N - 1];
}
template <class T, std::size_t N>
T *array<T, N>::data() {
  return arr_;
}
template <class T, std::size_t N>
const T *array<T, N>::data() const {
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
bool array<T, N>::empty() {
  return size_ == 0 ? true : false;
}
template <class T, std::size_t N>
bool array<T, N>::empty() const {
  return size_ == 0 ? true : false;
}
template <class T, std::size_t N>
std::size_t array<T, N>::size() noexcept {
  return size_;
}

template <class T, std::size_t N>
std::size_t array<T, N>::size() const noexcept {
  return size_;
}
template <class T, std::size_t N>
std::size_t array<T, N>::max_size() {
  return size();
}
template <class T, std::size_t N>
std::size_t array<T, N>::max_size() const {
  return size();
}
// Array Modifiers
template <class T, std::size_t N>
void array<T, N>::swap(array<T, N> &other) {
  std::swap_ranges(arr_, arr_ + N, other.arr_);
}
template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill(arr_, arr_ + N, value);
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_TPP_