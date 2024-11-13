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
  explicit vector(const vector &v);
  explicit vector(vector &&v);
  vector &operator=(const vector &v) noexcept;
  vector &operator=(
      vector &&v) noexcept;  //	assignment operator overload for moving
  // Vector Element access
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  /*
   const_reference front()	access the first element
   const_reference back()	access the last element
   T* data()	direct access to the underlying array
   */
  // Vector Iterators
  iterator begin() noexcept;  // returns an iterator to the beginning
  iterator end() noexcept;    // returns an iterator to the end
  // Vector Capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  /*
  size_type max_size()	returns the maximum possible number of elements
  void reserve(size_type size)	allocate storage of size elements and copies
  current array elements to a newely allocated array size_type capacity()
  returns the number of elements that can be held in currently allocated storage
  void shrink_to_fit()	reduces memory usage by freeing unused memory
  */
  // Vector Modifiers
  /*
  void clear() clears the contents
  noexplicit iterator insert(iterator pos, const_reference value)	inserts
  elements into concrete pos and returns the iterator that points to the new
  element void erase(iterator pos)erases element at pos void
  push_back(const_reference value)	adds an element to the end void
  pop_back()	removes the last element void swap(vector& other)	swaps
  the contents
  */
 private:
  unique_ptr arr_;
  size_type size_, capacity_;
};
}  // namespace s21

namespace s21 {
// Vector Member functions
template <class T>
s21::vector<T>::vector() : arr_(nullptr), size_(0), capacity_(0) {}

template <class T>
s21::vector<T>::vector(size_type n)
    : arr_(std::make_unique<value_type[]>(n)), size_(n), capacity_(n) {
  std::fill(arr_.get(), arr_.get() + n, T());
}

template <class T>
s21::vector<T>::vector(const std::initializer_list<T> &items)
    : arr_(std::make_unique<value_type[]>(items.size())),
      size_(items.size()),
      capacity_(items.size()) {
  std::copy(items.begin(), items.end(), arr_.get());
}

template <class T>
s21::vector<T>::vector(const s21::vector<T> &v)
    : arr_(std::make_unique<value_type[]>(v.size())),
      size_(v.size()),
      capacity_(v.size()) {
  std::copy(v.arr_.get(), v.arr_.get() + v.size_, arr_.get());
}

template <class T>
s21::vector<T>::vector(s21::vector<T> &&v)
    : arr_(std::make_unique<value_type[]>(v.size())),
      size_(v.size()),
      capacity_(v.size()) {
  if (&v != this) {
    std::move(v.arr_.get(), v.arr_.get() + v.size_, arr_.get());
  }
}

template <class T>
s21::vector<T> &s21::vector<T>::operator=(const s21::vector<T> &v) noexcept {
  if (this != &v) {
    arr_.reset();
    arr_ = std::make_unique<T[]>(v.size());
    std::copy(v.arr_.get(), v.arr_.get() + v.size_, arr_.get());
    size_ = v.size_;
    capacity_ = v.capacity_;
  }
  return *this;
}

template <class T>
s21::vector<T> &s21::vector<T>::operator=(s21::vector<T> &&v) noexcept {
  if (this != &v) {
    // Не очищаем целевой вектор
    arr_.reset();
    arr_ = std::make_unique<T[]>(v.size());
    // Перемещаем элементы
    std::move(v.arr_.get(), v.arr_.get() + v.size_, arr_.get());
    size_ = v.size_;
    capacity_ = v.capacity_;
    v.arr_.reset();
    v.size_ = v.capacity_ = 0;
  }

  return *this;
}

// Vector Element access
template <class T>
T &s21::vector<T>::at(size_type pos) {
  if (pos >= size_ || !size_) {
    throw std::out_of_range("Vector out of bound(at)");
  }
  return arr_[pos];
}

template <class T>
const T &s21::vector<T>::at(size_type pos) const {
  if (pos >= size_ || !size_) {
    throw std::out_of_range("Vector out of bound(at)");
  }
  return arr_[pos];
}

template <class T>
T &s21::vector<T>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range (operator[])");
  }
  return arr_[pos];
}

template <class T>
const T &s21::vector<T>::operator[](size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range (operator[])");
  }
  return arr_[pos];
}
// Vector Iterators
template <class T>
T *s21::vector<T>::begin() noexcept {
  return arr_.get();
}

template <class T>
T *s21::vector<T>::end() noexcept {
  if (size_ == 0) {
    return arr_.get();
  } else {
    return arr_.get() + size_ - 1;
  }
}
// Vector Capacity
template <class T>
bool s21::vector<T>::empty() const noexcept {
  return size_ > 0 ? false : true;
}

template <class T>
std::size_t s21::vector<T>::size() const noexcept {
  return size_;
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_1_SRC_VECTOR_VECTOR_H_