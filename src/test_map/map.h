#ifndef SRC_MAP_MAP_H_
#define SRC_MAP_MAP_H_

#include "binaryTree.h"

namespace s21 {
template <typename K, typename V>
class map : public BinaryTree<K, V> {
 public:
  map() : BinaryTree<K, V>(){};
  map(std::initializer_list<typename BinaryTree<K, V>::value_type> const& items)
      : BinaryTree<K, V>(items){};
  map(const map& m) : BinaryTree<K, V>(m){};
  map(map&& m) noexcept : BinaryTree<K, V>(std::move(m)){};

  // DESTRUCTOR
  ~map() = default;
};
}  // namespace s21

#endif  // SRC_MAP_MAP_H_