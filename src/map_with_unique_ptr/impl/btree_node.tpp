#include "../include/btree_node.h"
// Constructors

namespace s21 {

template <typename K, typename V>
btree_node<K, V>::btree_node(const K key, V value) {
  data = std::make_pair(key, value);
  parent = nullptr;
  right = nullptr;
  left = nullptr;
}

template <typename K, typename V>
btree_node<K, V>::btree_node(btree_node &&other) noexcept {
  data = std::move(other.data);
  parent = std::move(other.parent);
  right = std::move(other.right);
  left = std::move(other.left);
}

template <typename K, typename V>
btree_node<K, V> &btree_node<K, V>::operator=(const btree_node<K, V> &other) {
  if (this == &other) {
    return *this;
  }
  this->~btree_node();
  data = std::make_pair(other.data.first, other.data.second);
  parent = other.parent;
  right = other.right;
  left = other.left;
  return *this;
}
template <typename K, typename V>
btree_node<K, V> &btree_node<K, V>::operator=(
    btree_node<K, V> &&other) noexcept {
  if (this == &other) {
    data = std::move(other.data);
    parent = std::move(other.parent);
    right = std::move(other.right);
    left = std::move(other.left);
  }
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
          right == other.right && left == other.left);
}

}  // namespace s21
