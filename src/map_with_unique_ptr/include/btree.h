#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>

#include <iostream>
#include <memory>
#include <string>
// #include "node.h"

/// @brief
namespace s21 {
using std::shared_ptr;

template <typename Key, typename T>
class map;

template <typename K, typename V>
class btree_node;

template <typename K, typename V>
class btree_iterator;

template <typename K, typename V>
class btree {
 public:
  using key_type = K;
  using mapped_type = V;
  using value_type = std::pair<const key_type, mapped_type>;
  using node_type = btree_node<K, V>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = btree_iterator<K, V>;
  using size_type = size_t;
  using sh_ptr_iterator = std::shared_ptr<btree_iterator<K, V>>;
  using node_ptr = shared_ptr<btree_node<K, V>>;

  btree() : bt_root_(nullptr), bt_size_() {}

  btree(const btree &other)
      : bt_root_(other.bt_root_), bt_size_(other.bt_size_) {}

  btree(btree &&bt) noexcept {
    bt_root_ = std::move(bt.bt_root_);
    bt_size_ = std::move(bt.size_);
  }

  btree(K key, V value) {
    bt_root_ = std::make_shared < node_type >> (key, value);
    bt_size_ = 1;
  }

  btree(value_type data) {
    bt_root_ = std::make_shared < node_type >> (data.first, data.second);
    bt_size_ = 1;
  }

  ~btree();

  btree &operator=(const btree &other) {
    if (this != &other) {
      bt_root_.reset();
      bt_root_ = other.bt_root_;
      bt_size_ = other.bt_size_;
    }
    return *this;
  }

  btree &operator=(btree &&other) noexcept {
    if (this == &other) {
      bt_root_ = std::move(other.bt_root_);
      bt_size_ = std::move(other.bt_size_);
    }
    return *this;
  }

  void insert(K key, V value, bool &is_inserted);

  node_ptr find(node_ptr node, K key) const;

  void remove(const key_type key);

  node_ptr get_root();

  size_type size() const { return bt_size_; }

  bool contains(const K &key) const {
    return this->find(bt_root_, key) != nullptr;
  }

  void destroyRecursive(btree_node<K, V> *node);

  void in_order_tree_walk(node_ptr node);

  friend class btree_iterator<K, V>;

  friend class map<K, V>;

 private:
  node_ptr bt_root_;
  size_t bt_size_;
};

}  // namespace s21

#include "../impl/btree.tpp"

#endif  // BINARY_TREE_H_
