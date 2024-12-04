#include "../include/btree_iterator.h"

namespace s21 {

template <typename K, typename V>
btree_iterator<K, V> &btree_iterator<K, V>::operator=(
    const btree_iterator<K, V> &other) {
  if (this == &other) {
    return *this;
  }
  this->~btree_iterator();
  currentNode_ = other.currentNode_;
  return *this;
}

template <typename K, typename V>
btree_iterator<K, V> &btree_iterator<K, V>::operator++() {
  currentNode_ = next(currentNode_);  // Переходим к следующему узлу
  return *this;
}

template <typename K, typename V>
btree_iterator<K, V>::btree_iterator(const btree_iterator<K, V> &other)
    : currentNode_(other.currentNode_), treeRoot_(other.treeRoot_) {}

template <typename K, typename V>
btree_iterator<K, V> &btree_iterator<K, V>::operator--() {
  currentNode_ = prev(currentNode_);  // Переходим к следующему узлу
  return *this;
}
template <typename K, typename V>
btree_iterator<K, V> btree_iterator<K, V>::operator++(int) {
  btree_iterator temp = *this;
  ++(*this);
  return temp;
}
template <typename K, typename V>
btree_iterator<K, V> btree_iterator<K, V>::operator--(int) {
  btree_iterator temp = *this;
  --(*this);
  return temp;
}

template <typename K, typename V>
bool btree_iterator<K, V>::operator==(const btree_iterator &other) const {
  return currentNode_ == other.currentNode_;
}

template <typename K, typename V>
bool btree_iterator<K, V>::operator!=(const btree_iterator &other) const {
  return currentNode_ != other.currentNode_;
}

template <typename K, typename V>
btree_iterator<K, V>::~btree_iterator() = default;

template <typename K, typename V>
btree_iterator<K, V>::btree_iterator(btree_node<K, V> *node) {
  currentNode_ = node;
}

template <typename K, typename V>
btree_iterator<K, V>::btree_iterator(K key, V value) {
  currentNode_ = btree_node(key, value);
}

template <typename K, typename V>
void btree_iterator<K, V>::set_root(btree_node<K, V> *root) {
  treeRoot_ = root;
}

}  // namespace s21