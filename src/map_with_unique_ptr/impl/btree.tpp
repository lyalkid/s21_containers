#include "../include/btree.h"

namespace s21 {
//    template<typename K, typename V>
using std::make_pair;
using std::make_shared;
using std::pair;
using std::shared_ptr;

template <typename K, typename V>
btree<K, V>::~btree() = default;

template <typename K, typename V>
std::shared_ptr<btree_node<K, V>> btree<K, V>::get_root() {
  return bt_root_;
}

// insert
template <typename K, typename V>
void btree<K, V>::insert(K key, V value, bool& is_inserted) {
  if (bt_root_ == nullptr) {
    bt_root_ = std::make_shared<btree_node<K, V>>(key, value);
    bt_size_++;
    is_inserted = true;
    return;
  }

  is_inserted = false;
  node_type* parent = nullptr;
  shared_ptr<btree_node<K, V>> current = bt_root_;
  shared_ptr<btree_node<K, V>> temp = make_shared<btree_node<K, V>>(key, value);

  while (current != nullptr) {
    parent = current.get();
    current = key < current->data.first ? current->left : current->right;
  }
  temp->parent = parent;
  if (parent == nullptr) {
    bt_root_ = temp;
    is_inserted = true;
  } else if (key < parent->data.first) {
    parent->left = temp;
    is_inserted = true;
  } else {
    parent->right = temp;

    is_inserted = true;
  }
  if (is_inserted) bt_size_++;
}

template <typename K, typename V>
typename btree<K, V>::node_ptr btree<K, V>::find(node_ptr node, K key) const {
  if (node == nullptr || node->data.first == key) {
    return node;
  }
  K r_key = node->data.first;
  if (key < r_key) {
    return find(node->left, key);
  }
  return find(node->right, key);
}

template <typename K, typename V>
typename btree<K, V>::node_type* btree<K, V>::findMin(node_type* node) const {
  if (node->left == nullptr) {
    return node;
  }
  return findMin(node->left.get());
}

template <typename K, typename V>
typename btree<K, V>::node_type* btree<K, V>::findMax(node_type* node) const {
  if (node->right == nullptr) {
    return node;
  }
  return findMax(node->right.get());
}

template <typename K, typename V>
typename btree<K, V>::node_type* btree<K, V>::next(node_type* node) const {
  if (node->right != nullptr) {
    return findMin(node->right.get());
  }
  node_type* parent = node->parent;
  while (parent && node == parent->right.get()) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}

template <typename K, typename V>
typename btree<K, V>::node_type* btree<K, V>::prev(node_type* node) const {
  if (node->left != nullptr) {
    return findMax(node->left.get());
  }
  node_type* parent = node->parent;
  while (parent && node == parent->left.get()) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}

template <typename K, typename V>
typename btree<K, V>::node_type* btree<K, V>::tree_successor(
    node_type* node) const {}

template <typename K, typename V>
void btree<K, V>::in_order_tree_walk(std::shared_ptr<btree_node<K, V>> node) {
  if (node != nullptr) {
    in_order_tree_walk(node->right);
    std::cout << std::string(node->lvl, ' ') << node->data.first << std::endl;
    in_order_tree_walk(node->left);
  }
}
template <typename K, typename V>
void btree<K, V>::remove(const key_type key) {}

}  // namespace s21
