#include "bst.h"
template <typename T>
bst<T>::bst(/* args */) {
  root = nullptr;
}
template <typename T>
bst<T>::bst(Node<T> root) {
  this->root = root;
}


template <typename T>
bst<T>::bst(T value) {
  this->root = Node(value) ;
}

template <typename T>
bst<T>::~bst() {}





