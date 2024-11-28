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
template <typename K, typename V>
class TreeNode;

template <typename K, typename V>
class TreeIterator;

template <typename K, typename V>
class BinaryTree {
 private:
  // TreeIterator<K, V>* it;
  //  TreeIterator<K, V> it;
  // using data = std::pair<const K, V>;
  std::shared_ptr<TreeNode<K, V>> root;
  size_t count;

 public:
  using key_type = K;
  using mapped_type = V;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using sh_ptr_iterator = std::shared_ptr<TreeIterator<K, V>>;
  using iterator = TreeIterator<K, V>;
  // TreeIterator<K, V>;

  BinaryTree() : root(nullptr), count() {}

  BinaryTree(K key, V value);

  ~BinaryTree();

  void insert(K key, V value, bool &is_inserted, iterator &it);

  shared_ptr<TreeNode<K, V>> find(std::shared_ptr<TreeNode<K, V>> node,
                                  K key) const;

  TreeNode<K, V> *findMin(std::shared_ptr<TreeNode<K, V>> node) const;

  TreeNode<K, V> *findMax(std::shared_ptr<TreeNode<K, V>> node) const;

  std::shared_ptr<TreeNode<K, V>> get_root();

  //
  void destroyRecursive(TreeNode<K, V> *node);
  //
  //
  //
  //        // methods
  //
  //        std::unique_ptr<TreeNode<K,  V>> find(std::unique_ptr<TreeNode<K,
  //        V>> root, K key);
  //
  //        std::unique_ptr<TreeNode<K,  V>>
  //        iterrative_find(std::unique_ptr<TreeNode<K, V>> root, K key);
  //        // обход дерева
  void in_order_tree_walk(std::shared_ptr<TreeNode<K, V>> node);
  //
  //        void remove(std::unique_ptr<TreeNode<K,  V>> , K key);
  //
  //        bool isEmpty();
  //
  //        size_t size();
  //
  //        std::unique_ptr<TreeNode<K,  V>> get_root();
  //        // overload operators

  /*
   class TreeNode
  */
  friend class TreeIterator<K, V>;
};

template <typename K, typename V>
class TreeIterator {
 public:
  using Node = TreeNode<K, V>;
  using value_type = std::pair<const K, V>;
  using reference = value_type &;
  using pointer = value_type *;

  TreeIterator() = default;

  TreeIterator(TreeNode<K, V> *node);

  TreeIterator(K key, V value);

  ~TreeIterator();

  TreeIterator &operator=(const TreeIterator &other);

  friend class BinaryTree<K, V>;  //<K, V>;
 private:
  Node *currentNode;
};

template <typename K, typename V>
class TreeNode {
 private:
  std::pair<K, V> data;
  std::shared_ptr<TreeNode> parent;
  std::shared_ptr<TreeNode> right;
  std::shared_ptr<TreeNode> left;

  //        TreeNode *parent;
  //        TreeNode *right;
  //        TreeNode *left;
  size_t lvl;
  // bool red;
  // bool isLeftChild;

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
