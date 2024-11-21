#include "binaryTree.h"

// Constructors

namespace s21 {

template <typename K, typename V>
Node<K, V>::Node(K key, V value) {
  this->key = key;
  this->value = value;
//  red = false;
  parrent = nullptr;
  right = nullptr;
  left = nullptr;
}

// Destructor
template <typename K, typename V>
Node<K, V>::~Node() {
  // TODO: реализовать деструктор
}

// overload operators
template <typename K, typename V>
Node<K, V>& Node<K, V>::operator=(const Node<K, V>& other) {
  if (this == &other) {
    return *this;
  }

  this->~Node();
  value = other.value;
  right = other.right;
  left = other.left;
  return *this;
}

}  // namespace s21
