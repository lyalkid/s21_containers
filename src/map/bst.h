#ifndef BST_H
#define BST_H
#include "node.h"


template <typename T>
class bst {
 private:
  Node<T> root;

 public:
  bst(/* args */);
   bst(Node<T> root);
   bst(T value);
  ~bst();

};
#include "bst.tpp"


#endif // BST_H
