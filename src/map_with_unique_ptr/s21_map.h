#ifndef S21_MAP_H_
#define S21_MAP_H_

#include "binaryTree.h"

namespace s21 {

template <typename Key, typename T, typename compare>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

  // временно пустые
  class iterator;

  class const_iterator;

  // Constructors
  map();

  map(std::initializer_list<value_type> const &items);

  map(const map &m);

  map(map &&m);

  ~map();

  map &operator=(map &&m);

  mapped_type &at(const key_type &key);

  mapped_type &operator[](const key_type &key);

  iterator begin();

  iterator end();

  bool empty() const;

  size_type size() const;

  void clear();

  std::pair<iterator, bool> insert(const value_type &value);

  void erase(iterator pos);

  bool contains(const key_type &key) const;

 private:
  BinaryTree<key_type, mapped_type> tree;
};
}  // namespace s21

#include "s21_map.tpp"

#endif  // S21_MAP_H_