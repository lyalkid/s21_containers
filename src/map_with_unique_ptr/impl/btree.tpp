#include "../include/btree.h"

namespace s21 {
//    template<typename K, typename V>
using std::make_pair;
using std::make_shared;
using std::pair;
using std::shared_ptr;

template <typename K, typename V>
btree<K, V>::~btree() {
  this->clear();
  bt_root_ = nullptr;
}

template <typename K, typename V>
std::shared_ptr<btree_node<K, V>> btree<K, V>::get_root() {
  return bt_root_;
}

// insert
template <typename K, typename V>
void btree<K, V>::insert(const K key, V value) {
  if (bt_root_ == nullptr) {
    bt_root_ = std::make_shared<btree_node<K, V>>(key, value);
    bt_size_++;
    return;
  }

  bool is_inserted = false;
  node_ptr parent = nullptr;
  shared_ptr<btree_node<K, V>> current = bt_root_;
  shared_ptr<btree_node<K, V>> temp = make_shared<btree_node<K, V>>(key, value);

  while (current != nullptr) {
    parent = current;
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
typename btree<K, V>::node_ptr btree<K, V>::find_helper(node_ptr root,
                                                        K key) const {
  if (root == nullptr || root->data.first == key) {
    return root;
  }
  K r_key = root->data.first;
  if (key < r_key) {
    return find_helper(root->left, key);
  }
  return find_helper(root->right, key);
}

template <typename K, typename V>
typename btree<K, V>::iterator btree<K, V>::search(const K &key) const {
  node_ptr search = find_helper(bt_root_, key);
  if (search == nullptr) {
    return end();
  }
  iterator it(search, bt_root_);
  return it;
}

template <typename K, typename V>
typename btree<K, V>::iterator btree<K, V>::search(reference value) const {
  node_type *search = find_helper(bt_root_, value.first).get();
  if (search != nullptr && search->data.second == value.second) {
    iterator it(search, bt_root_);
    return it;
  }
  return end();
}
template <typename K, typename V>
bool btree<K, V>::contains(const key_type &key) const {
  //  bool contains = false;
  //  node_type *s =
  //  if (s != nullptr) contains = true;
  return find_helper(bt_root_, key).get() != nullptr;
}

template <typename K, typename V>
void btree<K, V>::in_order_tree_walk(std::shared_ptr<btree_node<K, V>> node,
                                     int space) {
  if (node != nullptr) {
    in_order_tree_walk(node->right, space + 2);
    std::cout << std::string(space, ' ') << node->data.first << std::endl;
    in_order_tree_walk(node->left, space + 2);
  }
  if (space == 0) std::cout << "-----\n";
}

template <typename K, typename V>
void btree<K, V>::remove(const key_type &key) {
  node_ptr current = find_helper(bt_root_, key);
  if (current != nullptr) {
    node_type *parent = current->parent;
    // case 1
    if (current->right == nullptr && current->left == nullptr) {
      if (current == bt_root_) {
        bt_root_.reset();
        bt_size_--;
      } else if (parent->left == current) {
        parent->left = nullptr;
        bt_size_--;
      } else if (parent->right == current) {
        parent->right = nullptr;
        bt_size_--;
      }
    }
    // cas2.1
    else if (current->right == nullptr) {
      if (current == bt_root_) {
        bt_root_ = current->left;
        bt_size_--;
      } else if (parent->left == current) {
        parent->left = current->left;
        bt_size_--;
      } else if (parent->right == current) {
        parent->right = current->left;
        bt_size_--;
      }
    }
    // cas2.2
    else if (current->left == nullptr) {
      if (current == bt_root_) {
        bt_root_ = current->right;
        bt_size_--;
      } else if (parent->left == current) {
        parent->left = current->right;
        bt_size_--;
      } else if (parent->right == current) {
        parent->right = current->right;
        bt_size_--;
      }
    }
    // case 3

    else {
      node_ptr successor = tree_successor(current);
      if (current == bt_root_) {
        bt_root_ = successor;
        bt_size_--;
      } else if (parent->left == current) {
        parent->left = successor;
        bt_size_--;
      } else if (parent->right == current) {
        parent->right = successor;
        bt_size_--;
      }
      successor->left = current->left;
    }
  }
}

template <typename K, typename V>
typename btree<K, V>::node_ptr btree<K, V>::tree_successor(
    node_ptr del_node) const {
  node_ptr successor_parent = del_node;
  node_ptr successor = del_node;
  node_ptr current = del_node->right;
  while (current != nullptr) {
    successor_parent = successor;
    successor = current;
    current = current->left;
  }
  if (successor != del_node->right) {
    successor_parent->left = successor->right;
    successor->right = del_node->right;
  }
  return successor;
}
template <typename K, typename V>
void btree<K, V>::clear() {
  clear_node(bt_root_);
  bt_root_.reset();
  bt_size_ = 0;
}
template <typename K, typename V>
void btree<K, V>::clear_node(node_ptr node) {
  if (node == nullptr) return;
  clear_node(node->left);
  clear_node(node->right);
  node->left.reset();
  node->right.reset();
  node->parent = nullptr;
  bt_size_--;
}
template <typename K, typename V>
bool btree<K, V>::empty() {
  return bt_root_ == nullptr;
}

template <typename K, typename V>
size_t btree<K, V>::size() const {
  return bt_size_;
}

template <typename K, typename V>
size_t btree<K, V>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(node_type);
}

template <typename K, typename V>
void btree<K, V>::swap(btree &other) {
  std::swap(bt_root_, other.bt_root_);
  std::swap(bt_size_, other.bt_size_);
}

template <typename K, typename V>
typename btree<K, V>::iterator btree<K, V>::begin() const {
  if (bt_root_ != nullptr) {
    node_ptr current_node_ = bt_root_->findMin(bt_root_);
    iterator it(current_node_, bt_root_);
    return it;
  }
  iterator tmp(nullptr, nullptr);
  return tmp;
}

template <typename K, typename V>
typename btree<K, V>::iterator btree<K, V>::end() const {
  // node_type * end_node;
  iterator end(nullptr, bt_root_);
  return end;
}

}  // namespace s21
