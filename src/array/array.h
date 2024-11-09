#ifndef CPP2_S21_CONTAINERS_1_SRC_ARRAY_H_
#define CPP2_S21_CONTAINERS_1_SRC_ARRAY_H_
#include <iostream>
#include <limits>

namespace s21 {
template <typename T, std::size_t N>
  class array{
    public:
      using value_type = T;
      using reference = T &;
      using const_reference = const T &;
      using iterator = T *;
      using const_iterator = const T *;
      using size_type = std::size_t;

      size_type GetSize();
      array();

    private:
      T arr_[N];
      std::size_t size_ = N; //ISO C++ forbids zero-size array, -pedantic флаг не пропускает
  };
} //namespace s21

namespace s21 {
  template<class T, std::size_t N> 
  std::size_t array<T, N>::GetSize() {
    return size_;
  }

  template<class T, std::size_t N> 
  array<T, N>::array():size_(N) {}
  //краевые случаи - ноль и макс +
  //TODO: как я могу работать с обработкой ошибок компиляции?
}

#endif //CPP2_S21_CONTAINERS_1_SRC_ARRAY_H_