#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>

#include <iostream>
#include <memory>
#include <string>
// #include "node.h"

/// @brief
namespace s21 {

template <typename K, typename V>
class Node;

template <typename K, typename V>
class BinaryTree {
 private:
  // using data = std::pair<const K, V>;
  std::shared_ptr<Node<K, V>> root;
  size_t count;

 public:
  using key_type = K;
  using mapped_type = V;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

  BinaryTree();

  BinaryTree(K key, V value);

  ~BinaryTree();

  Node<K, V> *insert(K key, V value);

  //
  void destroyRecursive(Node<K, V> *node);
  //
  //
  //
  //        // methods
  //
  //        std::unique_ptr<Node<K,  V>> find(std::unique_ptr<Node<K,  V>> root,
  //        K key);
  //
  //        std::unique_ptr<Node<K,  V>> iterrative_find(std::unique_ptr<Node<K,
  //        V>> root, K key);
  //        // обход дерева
  //        void in_order_tree_walk(std::unique_ptr<Node<K,  V>> node);
  //
  //        void remove(std::unique_ptr<Node<K,  V>> , K key);
  //
  //        bool isEmpty();
  //
  //        size_t size();
  //
  //        std::unique_ptr<Node<K,  V>> get_root();
  //        // overload operators

  /*
   class Node
  */
};

template <typename K, typename V>
class Node {
 private:
  std::pair<K, V> data;
  std::shared_ptr<Node> parent;
  std::shared_ptr<Node> right;
  std::shared_ptr<Node> left;
  size_t lvl;
  // bool red;
  // bool isLeftChild;

 public:
  //        using value = std::pair<K, V>;
  Node();

  Node(K, V);

  ~Node();

  Node &operator=(const Node &other);

  //        template<template K, template  V>
  friend class BinaryTree<K, V>;  //<K, V>;
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

#endif  // BINARY_TREE_H_
