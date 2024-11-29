#include "binaryTree.h"

namespace s21 {
//    template<typename K, typename V>
using std::make_pair;
using std::make_shared;
using std::pair;
using std::shared_ptr;

template <typename K, typename V>
binary_tree<K, V>::binary_tree(K key, V value) {
  root = std::make_shared<btree_node<K, V>>(key, value);
  it = btree_iterator(root.get());
  it.set_root(root.get());
  size_ = 0;
}

template <typename K, typename V>
binary_tree<K, V>::~binary_tree() = default;

template <typename K, typename V>
std::shared_ptr<btree_node<K, V>> binary_tree<K, V>::get_root() {
  return root;
}

// insert
template <typename K, typename V>
void binary_tree<K, V>::insert(K key, V value, bool &is_inserted) {
  if (root == nullptr) {
    root = std::make_shared<btree_node<K, V>>(key, value);
    // it = btree_iterator<K, V>(root.get());
    size_++;
    is_inserted = true;
    it.currentNode_ = root.get();
    it.set_root(root.get());
    return;
  }

  is_inserted = false;
  btree_node<K, V> *parent = nullptr;
  shared_ptr<btree_node<K, V>> current = root;
  shared_ptr<btree_node<K, V>> temp = make_shared<btree_node<K, V>>(key, value);
  //  if(this->find(root, key) != nullptr){
  //      return;
  //  }
  while (current != nullptr) {
    parent = current.get();
    current = key < current->data.first ? current->left : current->right;
  }
  temp->parent = parent;
  temp->lvl = temp->parent->lvl + 2;
  if (parent == nullptr) {
    root = temp;
    is_inserted = true;
  } else if (key < parent->data.first) {
    parent->left = temp;
    //            parent->left->parent = parent;
    is_inserted = true;
    it.currentNode_ = parent->left.get();
  } else {
    parent->right = temp;
    //            parent->left->parent = parent;

    is_inserted = true;
    it.currentNode_ = parent->right.get();
  }
  if (is_inserted) size_++;
}

template <typename K, typename V>
shared_ptr<btree_node<K, V>> binary_tree<K, V>::find(
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
void binary_tree<K, V>::in_order_tree_walk(
    std::shared_ptr<btree_node<K, V>> node) {
  if (node != nullptr) {
    in_order_tree_walk(node->right);
    std::cout << std::string(node->lvl, ' ') << node->data.first << std::endl;
    in_order_tree_walk(node->left);
  }
}

}  // namespace s21
