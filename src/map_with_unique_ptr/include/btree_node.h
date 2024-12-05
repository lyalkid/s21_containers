
#ifndef CONTAINERS_BTREE_NODE_H
#define CONTAINERS_BTREE_NODE_H

// #include <stddef.h>

#include <iostream>
#include <memory>
// #include <string>

// #include "btree.h"
namespace s21 {

template <typename Key, typename T>
class map;

template <typename K, typename V>
class btree;

template <typename K, typename V>
class btree_iterator;

template <typename K, typename V>
class btree_node {
 private:
  std::pair<const K, V> data;
  btree_node *parent;
  std::shared_ptr<btree_node> right;
  std::shared_ptr<btree_node> left;

 public:
  using node_type = btree_node<K, V>;
  //        using value = std::pair<K, V>;
  btree_node() = default;

  btree_node(const K key, V value)
      : data(key, value), parent(nullptr), right(nullptr), left(nullptr) {}
  btree_node(const btree_node &other)
      : data(other.data),
        parent(other.parent),
        right(other.right),
        left(other.left) {}
  btree_node(btree_node &&other) noexcept;

  ~btree_node() = default;

  std::pair<const K, V> get_data() const { return data; }

  bool equals(const btree_node &other) const noexcept;

  btree_node &operator=(const btree_node &other);
  btree_node &operator=(btree_node &&other) noexcept;

  bool operator==(const btree_node &other) const noexcept;

  bool operator!=(const btree_node &other) const noexcept;

  node_type *next(node_type *node);

  node_type *prev(node_type *node) const;
  node_type *findMin(node_type *node) const;

  node_type *findMax(node_type *node) const;

  //        template<template K, template  V>
  friend class btree<K, V>;  //<K, V>;
  friend class btree_iterator<K, V>;

  friend class map<K, V>;
};
}  // namespace s21
#include "../impl/btree_node.tpp"
#endif  // CONTAINERS_BTREE_NODE_H
