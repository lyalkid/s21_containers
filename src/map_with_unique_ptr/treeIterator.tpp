#include "binaryTree.h"

namespace s21 {

template <typename K, typename V>
TreeIterator<K, V> &TreeIterator<K, V>::operator=(
    const TreeIterator<K, V> &other) {
  if (this == &other) {
    return *this;
  }
  this->~TreeIterator();
  currentNode_ = other.currentNode_;
  return *this;
}

template <typename K, typename V>
TreeIterator<K, V> &TreeIterator<K, V>::operator++() {}

template <typename K, typename V>
TreeIterator<K, V> &TreeIterator<K, V>::operator--() {}

template <typename K, typename V>
bool TreeIterator<K, V>::operator==(const TreeIterator &other) const {
  return currentNode_ == other.currentNode_;
}

template <typename K, typename V>
bool TreeIterator<K, V>::operator!=(const TreeIterator &other) const {
  return currentNode_ != other.currentNode_;
}

template <typename K, typename V>
TreeIterator<K, V>::~TreeIterator() {}

template <typename K, typename V>
TreeIterator<K, V>::TreeIterator(TreeNode<K, V> *node) {
  currentNode_ = node;
}

template <typename K, typename V>
TreeIterator<K, V>::TreeIterator(K key, V value) {
  currentNode_ = TreeNode(key, value);
}

template <typename K, typename V>
void TreeIterator<K, V>::set_root(TreeNode<K, V> *root) {
  treeRoot_ = root;
}
}  // namespace s21