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
  /*
  iterator insert_many(const_iterator pos, Args&&... args); - Inserts before
  pos. void insert_many_back(Args&&... args); - Appends to the end of the
  container.
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
    arr_ = nullptr;
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
    arr_.reset();
    arr_ = nullptr;
    arr_ = std::make_unique<T[]>(v.size());
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
T &s21::vector<T>::operator[](size_type pos) noexcept {
  return arr_[pos];
}

template <class T>
const T &s21::vector<T>::operator[](size_type pos) const noexcept {
  return arr_[pos];
}

template <class T>
const T &s21::vector<T>::front() const noexcept {
  return arr_[0];
}

template <class T>
const T &s21::vector<T>::back() const noexcept {
  return arr_[size_ - 1];
}

template <class T>
T *s21::vector<T>::data() noexcept {
  return arr_.get();
}

template <class T>
const T *s21::vector<T>::data() const noexcept {
  return arr_.get();
}

// Vector Iterators
template <class T>
T *s21::vector<T>::begin() noexcept {
  return arr_.get();
}

template <class T>
T *s21::vector<T>::end() const noexcept {
  // if (size_ == 0) {
  //   return arr_.get();
  // } else {
  return arr_.get() + size_;
  // }
  // TODO: проверить на маке
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

template <class T>
std::size_t s21::vector<T>::max_size() const noexcept {
  constexpr auto max_size = std::numeric_limits<std::size_t>::max();
  return max_size / sizeof(T) / 2;
}

template <class T>
void s21::vector<T>::reserve(size_type size) {
  if (size > max_size()) {
    throw std::length_error(
        "Allocation impossible: vector capacity exceeded (reserve)");
  }
  std::unique_ptr<T[]> new_arr = std::make_unique<T[]>(size);
  std::copy(arr_.get(), arr_.get() + std::min(size, capacity_), new_arr.get());
  arr_.reset();
  arr_ = nullptr;
  arr_ = std::move(new_arr);
  size_ = std::exchange(capacity_, size);
}

template <class T>
std::size_t s21::vector<T>::capacity() const noexcept {
  return capacity_;
}

template <class T>
void s21::vector<T>::shrink_to_fit() noexcept {
  if (size_ < capacity_) {
    std::unique_ptr<T[]> new_arr = std::make_unique<T[]>(size_);
    std::copy(arr_.get(), arr_.get() + size_, new_arr.get());
    arr_.reset();
    arr_ = nullptr;
    arr_ = std::move(new_arr);
    capacity_ = size_;
  }
}
// Vector Modifiers
template <class T>
void s21::vector<T>::clear() noexcept {
  arr_.reset();
  arr_ = nullptr;
  size_ = 0;
}

template <class T>
T *s21::vector<T>::insert(iterator pos, const_reference value) noexcept {
  size_type index = pos - begin();

  if (size_ == capacity_) {
    reserve(capacity_ + 1);
    size_++;
  }
  arr_[index] = value;
  return arr_.get() + index;
}

template <class T>
void s21::vector<T>::erase(iterator pos) noexcept {
  if (pos < end()) {
    for (iterator i = pos; i < end(); i++) {
      *i += 1;
    }
    size_--;
  }
}

template <class T>
void s21::vector<T>::push_back(const_reference value) noexcept {
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ + 1 : 1);
  }
  arr_[size_++] = value;
  // TODO:пока непонятно что делать с nullptr
}

template <class T>
void s21::vector<T>::pop_back() noexcept {
  if (size_ > 0) {
    --size_;
  }
}

template <class T>
void s21::vector<T>::swap(s21::vector<T> &other) noexcept {
  std::swap(arr_, other.arr_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}
// Insert Many

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_1_SRC_VECTOR_VECTOR_H_