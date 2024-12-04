
#ifndef CONTAINERS_BTREE_ITERATOR_H
#define CONTAINERS_BTREE_ITERATOR_H

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
  using node = btree_node<K, V>;
  using value_type = std::pair<const K, V>;
  using reference = value_type &;
  using pointer = value_type *;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;

  btree_iterator() = default;

  btree_iterator(btree_node<K, V> *node);

  btree_iterator(const btree_iterator<K, V> &other);

  btree_iterator(K key, V value);

  ~btree_iterator();

  void set_root(btree_node<K, V> *bt_root_);

  btree_iterator &operator=(const btree_iterator &other);

  btree_iterator &operator++();

  btree_iterator &operator--();

  btree_iterator operator++(int);

  btree_iterator operator--(int);

  bool operator==(const btree_iterator &other) const;

  bool operator!=(const btree_iterator &other) const;

  reference operator*() const { return currentNode_->data; }

  std::pair<K, V> *operator->() const { return &(currentNode_->data); }

  btree_node<K, V> *findMin(btree_node<K, V> *node) const;

  btree_node<K, V> *findMax(btree_node<K, V> *node) const;

  btree_node<K, V> *next(btree_node<K, V> *node) const;

  btree_node<K, V> *prev(btree_node<K, V> *node) const;

  friend class btree<K, V>;  //<K, V>;
  friend class map<K, V>;

 private:
  node *treeRoot_;
  node *currentNode_;
};
}  // namespace s21
#include "../impl/btree_iterator.tpp"

#endif  // CONTAINERS_BTREE_ITERATOR_H
