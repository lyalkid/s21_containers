#include "btree_node.h"
// Constructors

namespace s21 {

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
  if (this != &other) {
    data = std::move(other.data);
    parent = std::move(other.parent);
    right = std::move(other.right);
    left = std::move(other.left);
    end_data = std::move(other.end_data);
  }
  return *this;
}

template <typename K, typename V>
bool btree_node<K, V>::operator==(const btree_node &other) const noexcept {
  return this->equals(other);
}

template <typename K, typename V>
bool btree_node<K, V>::operator!=(const btree_node &other) const noexcept {
  return (!this->equals(other));
}

template <typename K, typename V>
bool btree_node<K, V>::equals(const btree_node &other) const noexcept {
  if (this == &other) {
    return true;
  }
  return (data == other.data && parent.lock() == other.parent.lock() &&
          right == other.right && left == other.left);
}

template <typename K, typename V>
typename btree_node<K, V>::node_ptr btree_node<K, V>::next(node_ptr node) {
  if (node->right != nullptr) {
    return findMin(node->right);
  }
  node_ptr parent = node->parent.lock();
  while (parent != nullptr && node == parent->right) {
    node = parent;
    parent = parent->parent.lock();
  }
  return parent;
}

template <typename K, typename V>
typename btree_node<K, V>::node_ptr btree_node<K, V>::prev(node_ptr node) {
  if (node->left != nullptr) {
    return findMax(node->left);
  }
  node_ptr parent = node->parent.lock();
  ;
  while (parent && node == parent->left) {
    node = parent;
    parent = parent->parent.lock();
    ;
  }
  return parent;
}

template <typename K, typename V>
typename btree_node<K, V>::node_ptr btree_node<K, V>::findMin(
    node_ptr node) const {
  node_ptr res;
  if (node->left == nullptr) {
    res = node;
    return node;
  }
  res = findMin(node->left);
  return findMin(node->left);
}

template <typename K, typename V>
typename btree_node<K, V>::node_ptr btree_node<K, V>::findMax(
    node_ptr node) const {
  if (node->right == nullptr) {
    return node;
  }
  return findMax(node->right);
}

}  // namespace s21
