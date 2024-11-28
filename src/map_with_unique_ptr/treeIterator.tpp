#include "binaryTree.h"

namespace s21 {

template <typename K, typename V>
TreeIterator<K, V> &TreeIterator<K, V>::operator=(
    const TreeIterator<K, V> &other) {
  if (this == &other) {
    return *this;
  }
  this->~TreeIterator();
  currentNode = other.currentNode;
  return *this;
}

template <typename K, typename V>
TreeIterator<K, V>::~TreeIterator() {}

template <typename K, typename V>
TreeIterator<K, V>::TreeIterator(TreeNode<K, V> *node) {
  currentNode = node;
}
template <typename K, typename V>
TreeIterator<K, V>::TreeIterator(K key, V value) {
  currentNode = TreeNode(key, value);
}

}  // namespace s21