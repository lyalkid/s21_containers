#include "binaryTree.h"

namespace s21 {


template <typename K, typename V>
BinaryTree<K, V>::BinaryTree(/* args */) {
  root = nullptr;
  count = 0;
}

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree(Node<K, V> root) {
  this->root = root;
}

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree(K key, V value) {
  this->root = Node(key, value);
}

template <typename K, typename V>
BinaryTree<K, V>::~BinaryTree() {}

// insert
template <typename K, typename V>
Node<K, V> *BinaryTree<K, V>::insert(K key, V value) {
  Node<K, V> *temp = new Node(key, value);
  if (root == nullptr) {
    root = temp;
    return root;
  }

  Node<K, V> *parent = nullptr;
  Node<K, V> *current = root;
  while (current != nullptr) {
    parent = current;
    if (current->key >= key) {
      current = current->left;
    } else if (current->key <= key) {
      current = current->right;
    } else {
      return root;
    }
  }
  if (parent->key > key)
    parent->left = temp;
  else
    parent->right = temp;
  return root;
}

// get size
template <typename K, typename V>
size_t BinaryTree<K, V>::size() {
  return count;
}

template <typename K, typename V>
bool BinaryTree<K, V>::isEmpty() {
  return this->size() == 0;
}

}  // namespace s21
