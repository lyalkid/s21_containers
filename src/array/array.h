#ifndef CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_
#define CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_
#include <iostream>
#include <limits>
#include <stdexcept>

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
  array(const array &a);  // TODO:copy (const?) +
  array(array &&a);       // move
  ~array();               // destr

  iterator begin() noexcept;
  iterator end() noexcept;

  bool empty();
  bool empty() const;
  size_type size() noexcept;
  size_type size() const noexcept;
  size_type max_size();
  size_type max_size() const;

  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  array &operator=(const array &other);
  array &operator=(array &&other);  // TODO:original empty? no+

  /*
reference at(size_type pos)	access specified element with bounds checking
const_reference front()	access the first element
const_reference back()	access the last element
iterator data()	direct access to the underlying array
*/

  void swap(array &other);
  void fill(const_reference value);

 private:
  T arr_[N];
  std::size_t size_ = N;

  // ISO C++ forbids zero-size array, -pedantic флаг не пропускает
};
}  // namespace s21

namespace s21 {

template <class T, std::size_t N>
array<T, N>::array() : size_(N) {}
//краевые случаи - ноль и макс +
// TODO: как я могу работать с обработкой ошибок компиляции?  +

template <class T, std::size_t N>
array<T, N>::array(const std::initializer_list<T> &items) {
  std::copy(items.begin(), items.end(),
            arr_);  // TODO: arr_.begin() -  y not working? +
}

template <class T, std::size_t N>
array<T, N>::array(const s21::array<T, N> &a) {
  std::copy(a.arr_, a.arr_ + size_, arr_);
}

template <class T, std::size_t N>
array<T, N>::array(s21::array<T, N> &&a) {
  std::move(a.arr_, a.arr_ + N, arr_);
}

template <class T, std::size_t N>
array<T, N>::~array() {}

template <class T, std::size_t N>
T *array<T, N>::begin() noexcept {
  return arr_;
}

template <class T, std::size_t N>
T *array<T, N>::end() noexcept {
  return arr_ + size_;
}

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

template <class T, std::size_t N>
T &array<T, N>::operator[](std::size_t pos) {
  if (pos >= size_) {
    throw std::out_of_range("Array is out of bound");
  }
  return arr_[pos];
}

template <class T, std::size_t N>
const T &array<T, N>::operator[](std::size_t pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Array is out of bound");
  }
  return arr_[pos];
}

template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(const s21::array<T, N> &other) {
  // TODO: проверить size_ = other.size_; + нет надобности еслиразмер разный
  // даже не скомпилится +
  std::copy(other.arr_, other.arr_ + N, arr_);
  return *this;
}

template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(array<T, N> &&other) {
  // TODO: size_ = other.size_; +
  std::move(other.arr_, other.arr_ + N, arr_);
  return *this;
}

template <class T, std::size_t N>
void array<T, N>::swap(array<T, N> &other) {
  std::swap_ranges(arr_, arr_ + N, other.arr_);
  // TODO:swap_ranges
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill(arr_, arr_ + N, value);
  // TODO:std::fill
}


}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_ARRAY_ARRAY_H_