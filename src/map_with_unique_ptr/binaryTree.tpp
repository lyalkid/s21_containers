#include "binaryTree.h"

namespace s21 {

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree() {
  root = nullptr;
  count = 0;
}

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree(K key, V value) {
  this->root = std::make_shared<Node<K, V>>(key, value);
  count = 0;
}

template <typename K, typename V>
BinaryTree<K, V>::~BinaryTree() = default;

// insert
template <typename K, typename V>
Node<K, V> *BinaryTree<K, V>::insert(K key, V value) {
  if (root == nullptr) {
    root = std::make_shared<Node<K, V>>(key, value);
    count++;
  }
  /*
   * other cases
   * */
  return root.get();
}

}  // namespace s21
