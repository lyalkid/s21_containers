#ifndef BST_H
#define BST_H
#include "node.h"

template <typename T>
class BST {
 private:
  Node<T> root;

 public:
  BST(/* args */);
  ~BST();
};
template <typename T>
BST<T>::BST(/* args */) {
  root = Node<T>();
}
template <typename T>
BST<T>::~BST() {}

#endif BST_H
