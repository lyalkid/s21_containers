#ifndef S21_MAP_H_
#define S21_MAP_H_

#include "binaryTree.h"

namespace s21 {

template <typename K, typename V>
class map : public BinaryTree<K, V> {}
}  // namespace s21

#include "s21_Map.tpp"
#endif  // S21_MAP_H_