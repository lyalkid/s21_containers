#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>

#include <iostream>
#include <string>
//#include "node.h"

/// @brief
namespace s21 {

template <typename K, typename V>
class Node;

// BinaryTree
template <typename K, typename V>
class BinaryTree {
 private:
  Node<K, V> *root;
  size_t count;
  // bool color;

 public:
  BinaryTree();

  BinaryTree(Node<K, V> root);

  BinaryTree(K key, V value);

  ~BinaryTree();

  // обход дерева
  void in_order_tree_walk(Node<K, V> *node);

  // methods
  Node<K, V> *insert(K key, V value);

  void remove(K key);

  Node<K, V> *find(Node<K, V> *root, K key);

  bool isEmpty();

  size_t size();

  Node<K, V> *get_root();
  // overload operators
};

/*
 class Node
*/
template <typename K, typename V>
class Node {
 private:
  K key;
  V value;
  Node *parrent;
  Node *right;
  Node *left;
  size_t lvl;
  // bool red;
  // bool isLeftChild;

 public:
  Node(K key, V Value);

  ~Node();

  Node &operator=(const Node &other);

  friend class BinaryTree<K, V>;
};

}  // namespace s21
#include "binaryTree.tpp"
#include "node.tpp"

#endif  // BINARY_TREE_H_
