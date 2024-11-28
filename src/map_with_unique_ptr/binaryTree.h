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
class TreeNode;

template <typename K, typename V>
class TreeIterator;

template <typename K, typename V>
class BinaryTree {
 public:
  using key_type = K;
  using mapped_type = V;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using sh_ptr_iterator = std::shared_ptr<TreeIterator<K, V>>;
  using iterator = TreeIterator<K, V>;

  BinaryTree() : root(nullptr), it(), size_() {}

  BinaryTree(K key, V value);

  ~BinaryTree();

  void insert(K key, V value, bool &is_inserted);

  shared_ptr<TreeNode<K, V>> find(std::shared_ptr<TreeNode<K, V>> node,
                                  K key) const;

  TreeNode<K, V> *findMin(std::shared_ptr<TreeNode<K, V>> node) const;

  TreeNode<K, V> *findMax(std::shared_ptr<TreeNode<K, V>> node) const;

  std::shared_ptr<TreeNode<K, V>> get_root();

  size_type size() const { return size_; }

  bool contains(const K &key) const { return this->find(root, key) != nullptr; }

  void destroyRecursive(TreeNode<K, V> *node);

  void in_order_tree_walk(std::shared_ptr<TreeNode<K, V>> node);

  friend class TreeIterator<K, V>;

  friend class map<K, V>;

 private:
  std::shared_ptr<TreeNode<K, V>> root;
  iterator it;
  size_t size_;
};

template <typename K, typename V>
class TreeIterator {
 public:
  using Node = TreeNode<K, V>;
  using value_type = std::pair<const K, V>;
  using reference = value_type &;
  using pointer = value_type *;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;

  TreeIterator() = default;

  TreeIterator(TreeNode<K, V> *node);

  TreeIterator(K key, V value);

  ~TreeIterator();
  void set_root(TreeNode<K, V> *root);
  TreeIterator &operator=(const TreeIterator &other);
  TreeIterator &operator++();
  TreeIterator &operator--();
  bool operator==(const TreeIterator &other) const;
  bool operator!=(const TreeIterator &other) const;
  reference operator*() const { return currentNode_->data; }

  pointer operator->() const { return &currentNode_->data; }
  friend class BinaryTree<K, V>;  //<K, V>;
  friend class map<K, V>;

 private:
  Node *treeRoot_;
  Node *currentNode_;
};

template <typename K, typename V>
class TreeNode {
 private:
  std::pair<K, V> data;
  TreeNode *parent;
  std::shared_ptr<TreeNode> right;
  std::shared_ptr<TreeNode> left;

  size_t lvl;

 public:
  //        using value = std::pair<K, V>;
  TreeNode() = default;

  TreeNode(K, V);

  ~TreeNode();

  std::pair<K, V> get_data() { return data; }

  bool equals(const TreeNode &other) const noexcept;

  TreeNode &operator=(const TreeNode &other);

  bool operator==(const TreeNode &other) const noexcept;

  //        template<template K, template  V>
  friend class BinaryTree<K, V>;  //<K, V>;
  friend class TreeIterator<K, V>;

  friend class map<K, V>;
};

//    template<typename K, typename V>
//    template<typename T>
//
//
//    template<typename K, typename V>
//    template<typename T>

}  // namespace s21
#include "binaryTree.tpp"
#include "node.tpp"
#include "treeIterator.tpp"

#endif  // BINARY_TREE_H_
