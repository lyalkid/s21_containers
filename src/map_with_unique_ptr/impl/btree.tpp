#include "binaryTree.h"

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
void btree<K, V>::insert(K key, V value, bool &is_inserted) {
  if (bt_root_ == nullptr) {
    bt_root_ = std::make_shared<btree_node<K, V>>(key, value);
    bt_size_++;
    is_inserted = true;

    return;
  }

  is_inserted = false;
  btree_node<K, V> *parent = nullptr;
  shared_ptr<btree_node<K, V>> current = bt_root_;
  shared_ptr<btree_node<K, V>> temp = make_shared<btree_node<K, V>>(key, value);
  //  if(this->find(bt_root_, key) != nullptr){
  //      return;
  //  }
  while (current != nullptr) {
    parent = current.get();
    current = key < current->data.first ? current->left : current->right;
  }
  temp->parent = parent;
  temp->lvl = temp->parent->lvl + 2;
  if (parent == nullptr) {
    bt_root_ = temp;
    is_inserted = true;
  } else if (key < parent->data.first) {
    parent->left = temp;
    //            parent->left->parent = parent;
    is_inserted = true;
    // bt_it_.currentNode_ = parent->left.get();
  } else {
    parent->right = temp;
    //            parent->left->parent = parent;

    is_inserted = true;
    // bt_it_.currentNode_ = parent->right.get();
  }
  if (is_inserted) bt_size_++;
}

template <typename K, typename V>
shared_ptr<btree_node<K, V>> btree<K, V>::find(
    std::shared_ptr<btree_node<K, V>> node, K key) const {
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
void btree<K, V>::in_order_tree_walk(std::shared_ptr<btree_node<K, V>> node) {
  if (node != nullptr) {
    in_order_tree_walk(node->right);
    std::cout << std::string(node->lvl, ' ') << node->data.first << std::endl;
    in_order_tree_walk(node->left);
  }
}
template <typename K, typename V>
void btree<K, V>::remove(const key_type key) {

}

}  // namespace s21
