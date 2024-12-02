#include "binaryTree.h"
// Constructors

namespace s21 {

template <typename K, typename V>
btree_node<K, V>::btree_node(K key, V value)
    : parent(nullptr), right(nullptr), left(nullptr), lvl(0) {
  data = std::make_pair(key, value);
}


template <typename K, typename V>
btree_node<K, V> &btree_node<K, V>::operator=(const btree_node<K, V> &other) {
  if (this == &other) {
    return *this;
  }
  // TODO: сделать конструктор присваивания, тут не хватает всех полей, которые
  // есть в btree_node
  this->~btree_node();
  data = std::make_pair(other.data.first, other.data.second);
  parent = other.parent;
  lvl = other.lvl;
  right = other.right;
  left = other.left;
  return *this;
}
template <typename K, typename V>
bool btree_node<K, V>::operator==(const btree_node &other) const noexcept {
  return this->equals(other);
}

template <typename K, typename V>
bool btree_node<K, V>::equals(const btree_node &other) const noexcept {
  if (this == &other) {
    return true;
  }
  return (data == other.data && parent == other.parent &&
          right == other.right && left == other.left && lvl == other.lvl);
}





}  // namespace s21
