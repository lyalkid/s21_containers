#ifndef CPP2_S21_CONTAINERS_1_SRC_VECTOR_VECTOR_TPP_
#define CPP2_S21_CONTAINERS_1_SRC_VECTOR_VECTOR_TPP_
#include "vector.h"
#include <utility>
namespace s21 {
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>    Vector Member functions                                              >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
template <class T>
s21::vector<T>::vector() : arr_(nullptr), size_(0), capacity_(0) {}

template <class T>
inline s21::vector<T>::~vector() {}

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
    clear();
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
    clear();
    arr_ = std::make_unique<T[]>(v.size());
    std::move(v.arr_.get(), v.arr_.get() + v.size_, arr_.get());
    size_ = v.size_;
    capacity_ = v.capacity_;
    v.clear();
  }

  return *this;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>    Vector Element access                                                >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
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

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>    Vector Iterators                                                     >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
template <class T>
T *s21::vector<T>::begin() const noexcept {
  return arr_.get();
}

template <class T>
T *s21::vector<T>::end() const noexcept {
  return arr_.get() + size_;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>    Vector Capacity                                                      >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
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
  clear();
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
    clear();
    arr_ = std::move(new_arr);
    capacity_ = size_;
  }
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>    Vector Modifiers                                                     >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
template <class T>
void s21::vector<T>::clear() noexcept {
  arr_.reset();
  arr_ = nullptr;
  size_ = 0;
}

template <class T>
T *s21::vector<T>::insert(iterator pos, const_reference value) noexcept {
  size_type index = pos - begin();
  vector<value_type> tmp(size_ + 1);

  for (size_type i = 0; i < tmp.size_; ++i) {
    if (i < index) {
      tmp.arr_[i] = arr_[i];
    }
    if (i == index) {
      if (i != 0) {
        tmp.arr_[i] = arr_[i - 1];
      }
      tmp.arr_[i] = value;
    }
    if (i > index && i != 0) {
      tmp.arr_[i] = arr_[i - 1];
    }
  }
  *this = std::move(tmp);
  tmp.clear();
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

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
-->>    Insert Many                                                          >>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
template <class T>
template <class... Args>
T *s21::vector<T>::insert_many(const_iterator pos, Args &&...args) noexcept {
  vector<value_type> tmpVector{args...};
  iterator index = (iterator)pos;
  for (size_type i = 0; i < tmpVector.size(); i++) {
    index = insert(index, tmpVector[i]);
    index++;
  }
  return index;
}

template <class T>
template <class... Args>
void s21::vector<T>::insert_many_back(Args &&...args) noexcept {
  const_iterator index = const_iterator(end());
  insert_many(index, args...);
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_VECTOR_VECTOR_TPP_