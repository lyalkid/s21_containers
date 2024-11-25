#include "binaryTree.h"

// Constructors

namespace s21 {
//    template<typename K, typename V>
//    using value = std::pair<K, V>;
template <typename K, typename V>
Node<K, V>::Node()
    : data(nullptr), parent(nullptr), right(nullptr), left(nullptr), lvl(0) {}

template <typename K, typename V>
Node<K, V>::Node(K key, V value)
    : parent(nullptr), right(nullptr), left(nullptr), lvl(0) {
  data = std::make_pair(key, value);
}

template <typename K, typename V>

Node<K, V>::~Node() {}

template <typename K, typename V>
Node<K, V> &Node<K, V>::operator=(const Node<K, V> &other) {
  if (this == &other) {
    return *this;
  }
  // TODO: сделать конструктор присваивания, тут не хватает всех полей, которые
  // есть в Node
  this->~Node();
  data = std::make_pair(other.data.first, other.data.second);
  parent = other.parent;
  lvl = other.lvl;
  right = other.right;
  left = other.left;
  return *this;
}
}  // namespace s21
