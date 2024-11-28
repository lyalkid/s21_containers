#ifndef S21_MAP_H_
#define S21_MAP_H_

#include "binaryTree.h"

namespace s21 {

template <typename Key, typename T>
class map {
 private:
  size_t size_;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using iterator = typename BinaryTree<key_type, mapped_type>::iterator;

  class const_iterator;

  // Constructors
  map() = default;

  map(std::initializer_list<value_type> const &items);

  map(const map &m);

  map(map &&m);

  ~map() {}

  map &operator=(map &&m);

  mapped_type &at(const key_type &key);

  mapped_type &operator[](const key_type &key);

  iterator begin();

  iterator end();

  bool empty() const;

  size_type size() const;

  void clear();

  std::pair<iterator, bool> insert(const value_type &value);

  std::pair<iterator, bool> insert(const Key &key, const T &obj);

  void erase(iterator pos);

  bool contains(const key_type &key) const;

 private:
  BinaryTree<key_type, mapped_type> tree;
  iterator it;
  void clearHelper(std::shared_ptr<TreeNode<Key, T>> &node);
};
}  // namespace s21

#include "s21_map.tpp"

#endif  // S21_MAP_H_