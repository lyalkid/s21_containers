
#ifndef CONTAINERS_BTREE_ITERATOR_H
#define CONTAINERS_BTREE_ITERATOR_H
#include "../../stack/stack.h"
#include "btree_node.h"
namespace s21 {
template <typename Key, typename T>
class map;

template <typename K, typename V>
class btree_node;

template <typename K, typename V>
class btree_iterator;

template <typename K, typename V>
class btree_iterator {
 public:
  using node_type = btree_node<K, V>;
  using value_type = std::pair<const K, V>;
  using reference = value_type &;

  using pointer = value_type *;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;

  btree_iterator() = default;

  btree_iterator(node_type *node);

  btree_iterator(const btree_iterator<K, V> &other);

  btree_iterator(K key, V value);
  btree_iterator(node_type *node, bool end_)
      : currentNode_(node), end_(end_) {};

  ~btree_iterator();

  btree_iterator &operator=(const btree_iterator &other);

  btree_iterator &operator++();
  const btree_iterator operator++(int);
  node_type *find_root();

  btree_iterator &operator--();

  void init_stack(btree_node<K, V> *root);
  btree_iterator operator--(int);

  bool operator==(const btree_iterator &other) const;

  bool operator!=(const btree_iterator &other) const;

  reference operator*() const { return currentNode_->data; }

  std::pair<const K, V> *operator->() const { return &(currentNode_->data); }

  friend class btree<K, V>;  //<K, V>;
  friend class map<K, V>;

 private:
  node_type *currentNode_;
  bool end_;
  s21::stack<value_type> nextStack;
  s21::stack<value_type> prevStack;
};
}  // namespace s21
#include "../impl/btree_iterator.tpp"

#endif  // CONTAINERS_BTREE_ITERATOR_H
