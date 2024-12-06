
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
class btree;

template <typename K, typename V>
class btree_iterator {
 public:
  using node_type = btree_node<K, V>;
  using node_ptr = std::shared_ptr<node_type>;
  using value_type = std::pair<const K, V>;
  using reference = value_type &;
  using pointer = value_type *;

  // default constructor
  btree_iterator() : current_node_(nullptr), root_(nullptr) {};

  // init iterator
  btree_iterator(node_ptr node) : current_node_(node) {};

  // copy constructor
  btree_iterator(const btree_iterator &other)
      : current_node_(other.current_node_), root_(other.root_) {};

  // move constructor
  btree_iterator(btree_iterator &&other) {
    current_node_ = std::move(other.current_node_);
    root_ = std::move(other.root_);
  };

  // destructor
  ~btree_iterator() = default;

  // constructor for end
  btree_iterator(node_type *current_node, node_ptr root)
      : current_node_(current_node), root_(root) {};

  btree_iterator &operator=(const btree_iterator &other) {
    if (this != &other) {
      current_node_ = other.current_node_;
      root_ = other.root_;
    }
    return *this;
  }

  btree_iterator &operator=(btree_iterator &&other) noexcept {
    if (this != &other) {
      current_node_ = std::move(other.current_node_);
      root_ = std::move(other.root_);
    }
    return *this;
  }

  // increment
  btree_iterator &operator++() {
    if (current_node_ != nullptr)
      current_node_ = current_node_->next(current_node_);
    return *this;
  }

  btree_iterator operator++(int) {
    //    btree_iterator temp = *this;
    ++(*this);
    return *this;
  }

  // decrement
  btree_iterator &operator--() {
    if (current_node_ == nullptr) {
      current_node_ = root_->findMax(root_.get());
    } else {
      current_node_ = current_node_->prev(current_node_);
    }
    return *this;
  }

  btree_iterator operator--(int) {
    //    btree_iterator temp = *this;
    --(*this);

    return *this;
  }

  bool operator==(const btree_iterator &other) {
    return current_node_ == other.current_node_;
  }

  bool operator!=(const btree_iterator &other) {
    return current_node_ != other.current_node_;
  }

  reference operator*() const { return current_node_->data; }

  value_type *operator->() const { return &(current_node_->data); }

  friend class btree<K, V>;
  friend class btree_node<K, V>;

 private:
  node_type *current_node_;
  node_ptr root_;
};

}  // namespace s21
#include "../impl/btree_iterator.tpp"

#endif  // CONTAINERS_BTREE_ITERATOR_H
