
#ifndef CONTAINERS_BTREE_NODE_H
#define CONTAINERS_BTREE_NODE_H

#include <stddef.h>

#include <iostream>
#include <memory>
#include <string>

namespace s21 {
template <typename Key>
class set;
template <typename Key, typename T>
class map;

template <typename K, typename V>
class btree;

template <typename K, typename V>
class btree_iterator;

template <typename K, typename V>
class set_iterator;
template <typename K, typename V>
class btree_node {
 public:
  using node_ptr = std::shared_ptr<btree_node>;
  using node_type = btree_node<K, V>;

 private:
  std::pair<const K, V> data;
  node_ptr parent;
  node_ptr right;
  node_ptr left;

  std::pair<const K, V> end_data;

 public:
  using value = std::pair<K, V>;
  btree_node()
      : data(std::make_pair(K{}, V{})),
        parent(nullptr),
        left(nullptr),
        right(nullptr),
        end_data(std::make_pair(K{}, V{})) {}

  btree_node(const K key, V value)
      : data(key, value),
        parent(nullptr),
        right(nullptr),
        left(nullptr),
        end_data(std::make_pair(K{}, V{})) {}

  btree_node(const btree_node &other)
      : data(other.data),
        parent(other.parent),
        right(other.right),
        left(other.left),
        end_data(std::make_pair(K{}, V{})) {}

  btree_node(btree_node &&other) noexcept;

  //  ~btree_node() ;

  std::pair<const K, V> get_data() const { return data; }

  bool equals(const btree_node &other) const noexcept;

  btree_node &operator=(const btree_node &other);

  btree_node &operator=(btree_node &&other) noexcept;

  bool operator==(const btree_node &other) const noexcept;

  bool operator!=(const btree_node &other) const noexcept;

  node_ptr next(node_ptr node);

  node_ptr prev(node_ptr node);

  node_ptr findMin(node_ptr node) const;

  node_ptr findMax(node_ptr node) const;

  bool has_next() { return right != nullptr || left != nullptr; }

  //        template<template K, template  V>
  friend class btree<K, V>;  //<K, V>;
  friend class btree_iterator<K, V>;
  friend class set_iterator<K, V>;
  friend class map<K, V>;
  friend class set<K>;
};
}  // namespace s21
#include "../impl/btree_node.tpp"

#endif  // CONTAINERS_BTREE_NODE_H
