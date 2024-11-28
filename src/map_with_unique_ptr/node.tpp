#include "binaryTree.h"

// Constructors

namespace s21 {
//    template<typename K, typename V>
//    using value = std::pair<K, V>;
// template <typename K, typename V>
// TreeNode<K, V>::TreeNode()
//    : data(nullptr), parent(nullptr), right(nullptr), left(nullptr), lvl(0) {}

template <typename K, typename V>
TreeNode<K, V>::TreeNode(K key, V value)
    : parent(nullptr), right(nullptr), left(nullptr), lvl(0) {
  data = std::make_pair(key, value);
}

template <typename K, typename V>

TreeNode<K, V>::~TreeNode() {}

template <typename K, typename V>
TreeNode<K, V> &TreeNode<K, V>::operator=(const TreeNode<K, V> &other) {
  if (this == &other) {
    return *this;
  }
  // TODO: сделать конструктор присваивания, тут не хватает всех полей, которые
  // есть в TreeNode
  this->~TreeNode();
  data = std::make_pair(other.data.first, other.data.second);
  parent = other.parent;
  lvl = other.lvl;
  right = other.right;
  left = other.left;
  return *this;
}
template <typename K, typename V>
bool TreeNode<K, V>::operator==(const TreeNode &other) const noexcept {
  return this->equals(other);
}

template <typename K, typename V>
bool TreeNode<K, V>::equals(const TreeNode &other) const noexcept {
  if (this == &other) {
    return true;
  }
  return (data == other.data && parent == other.parent &&
          right == other.right && left == other.left && lvl == other.lvl);
}

}  // namespace s21
