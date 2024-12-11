#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>

#include <iostream>
#include <limits>
#include <memory>
#include <string>

#include "btree_iterator.h"
#include "btree_node.h"

// todo: разбить функции по блокам

namespace s21 {

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
  using const_iterator = const iterator;
  using size_type = size_t;
  using sh_ptr_iterator = std::shared_ptr<btree_iterator<K, V>>;
  using node_ptr = std::shared_ptr<btree_node<K, V>>;

  // todo: вынести реализации в .tpp файл
  btree() : bt_root_(std::make_shared<node_type>(K{}, V{})), bt_size_() {
    int c = 1;
  }

  // todo: вынести реализации в .tpp файл
  btree(const btree &other)
      : bt_root_(other.bt_root_), bt_size_(other.bt_size_) {}

  // todo: вынести реализации в .tpp файл
  btree(btree &&bt) noexcept {
    bt_root_ = std::move(bt.bt_root_);
    bt_size_ = std::move(bt.bt_size_);
  }

  // todo: вынести реализации в .tpp файл
  btree(K key, V value) {
    bt_root_ = std::make_shared<node_type>(key, value);
    bt_size_ = 1;
  }
  // todo: вынести реализации в .tpp файл

  btree(value_type data) {
    bt_root_ = std::make_shared<node_type>(data.first, data.second);
    bt_size_ = 1;
  }

  ~btree();
  // todo: вынести реализации в .tpp файл
  btree &operator=(const btree &other) {
    if (this != &other) {
      bt_root_.reset();
      bt_root_ = other.bt_root_;
      bt_size_ = other.bt_size_;
    }
    return *this;
  }
  // todo: вынести реализации в .tpp файл
  btree &operator=(btree &&other) noexcept {
    if (this != &other) {
      bt_root_ = std::move(other.bt_root_);
      bt_size_ = std::move(other.bt_size_);
    }
    return *this;
  }

  void insert(K key, V value);
  void insert(value_type data) { insert(data.first, data.second); }
  void remove(const key_type &key);
  void remove1(node_ptr remove_node);
  void remove2(node_ptr remove_node);
  void remove3(node_ptr remove_node);
    void remove4(node_ptr remove_node);
  iterator begin() const;
  iterator end() const;
  node_ptr find_helper(node_ptr root, K key) const;

  // todo: написать тесты на эти методы
  iterator search(const K &key) const;
  iterator search(reference value) const;
  bool contains(const key_type &key) const;

  void clear();

  void clear_node(node_ptr node);

  void swap(btree &other);

  void merge(btree &other);

  bool empty();

  size_t size() const;

  size_t max_size() const;

  node_ptr get_root();

  node_ptr tree_successor(node_ptr del_node) const;

  void in_order_tree_walk(node_ptr node, int space);
  friend class btree_iterator<K, V>;

  friend class map<K, V>;

 private:
  key_type root() const {
    return bt_root_ != nullptr ? bt_root_->data.first : nullptr;
  }

  node_ptr bt_root_;
  size_type bt_size_;
};

}  // namespace s21

#include "../impl/btree.tpp"

#endif  // BINARY_TREE_H_
