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
  end_ = other.end_;
  return *this;
}

template <typename K, typename V>
btree_iterator<K, V> &btree_iterator<K, V>::operator++() {
  //  if (end_ || !currentNode_) {
  //    return *this;
  //  }
  //  if (currentNode_->right  != nullptr) {
  //    currentNode_ = currentNode_->next(currentNode_);  // Переходим к
  //    следующему узлу end_ = false;
  //  }
  //  else{
  //      node_type * parent = currentNode_;
  //      while (parent->parent && parent->parent->right.get() == parent) {
  //          parent = parent->parent;
  //      }
  //      if (parent->parent == nullptr) {
  ////          currentNode_ = parent->parent;
  //          end_ = true;
  //      } else {
  //          currentNode_ = parent->parent;
  //      }
  //  }

  return *this;
}

template <typename K, typename V>
typename btree_iterator<K, V>::node_type *btree_iterator<K, V>::find_root() {
  node_type *parent = currentNode_;
  node_type *current = currentNode_;
  while (parent != nullptr) {
    parent = current->parent;
    current = parent;
  }
  return parent;
}

template <typename K, typename V>
const btree_iterator<K, V> btree_iterator<K, V>::operator++(int) {
  ++(*this);
  return *this;
}
template <typename K, typename V>
btree_iterator<K, V>::btree_iterator(const btree_iterator<K, V> &other)
    : currentNode_(other.currentNode_), end_(other.end_) {}

template <typename K, typename V>
btree_iterator<K, V> &btree_iterator<K, V>::operator--() {
  if (end_ || !currentNode_) {
  }
  currentNode_ =
      currentNode_->prev(currentNode_);  // Переходим к следующему узлу
  return *this;
}
template <typename K, typename V>
btree_iterator<K, V> btree_iterator<K, V>::operator--(int) {
  --(*this);
  return *this;
}

template <typename K, typename V>
bool btree_iterator<K, V>::operator==(const btree_iterator &other) const {
  return end_ ? (end_ == other.end_)
              : (currentNode_ == other.currentNode_ && end_ == other.end_);
}

template <typename K, typename V>
bool btree_iterator<K, V>::operator!=(const btree_iterator &other) const {
  bool res = end_ ? (end_ != other.end_)
                  : (currentNode_ != other.currentNode_ && end_ != other.end_);
  if (res) {
    int c = 1;
  } else {
    int v = 1;
  }

  return res;
}

template <typename K, typename V>
btree_iterator<K, V>::~btree_iterator() = default;

template <typename K, typename V>
btree_iterator<K, V>::btree_iterator(node_type *node) {
  currentNode_ = node;
  end_ = false;
}

template <typename K, typename V>
btree_iterator<K, V>::btree_iterator(K key, V value) {
  currentNode_ = btree_node(key, value);
}

template <typename K, typename V>
void btree_iterator<K, V>::init_stack(btree_node<K, V> *root) {
  if (root != nullptr) {
    init_stack(root->right.get());
    nextStack.push(root->data);
    init_stack(root->left.get());
  }
}

}  // namespace s21