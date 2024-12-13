
#ifndef CONTAINERS_BTREE_ITERATOR_H
#define CONTAINERS_BTREE_ITERATOR_H

#include "btree_node.h"

namespace s21 {
template <typename Key, typename T>
class map;

template <typename K, typename V>
class btree_node;

template <typename K, typename V>
class btree;

template <typename K>
class set;
template <typename K, typename V>
class btree_iterator {
 public:
  using node_type = btree_node<K, V>;
  using node_ptr = std::shared_ptr<node_type>;
  using value_type = std::pair<const K, V>;
  using reference = value_type &;
  using pointer = value_type *;

  // default constructor
  btree_iterator()
      : current_node_(nullptr),
        root_(nullptr),
        data_(std::make_pair(K{}, V{})) {};

  // init iterator
  btree_iterator(node_ptr node) : current_node_(node), root_(nullptr) {
    if (node == nullptr) {
      data_ = (std::make_pair(K{}, V{}));
    } else {
      data_ = (std::make_pair(node->data.first, node->data.second));
    }
  };

  // copy constructor
  btree_iterator(const btree_iterator &other)
      : current_node_(other.current_node_),
        root_(other.root_),
        data_(other.data_) {};

  // move constructor
  btree_iterator(btree_iterator &&other) {
    data_ = std::make_pair(std::move(other.data_.first),
                           std::move(other.data_.second));
    current_node_ = std::move(other.current_node_);
    root_ = std::move(other.root_);
  };

  // destructor
  ~btree_iterator() {
    current_node_.reset();
    root_.reset();
  }

  // constructor for end
  btree_iterator(node_ptr current_node, node_ptr root)
      : current_node_(current_node), root_(root) {
    if (current_node_ == nullptr) {
      data_ = (std::make_pair(K{}, V{}));
    } else {
      data_ =
          (std::make_pair(current_node->data.first, current_node->data.second));
    }
  };

  btree_iterator &operator=(const btree_iterator &other) {
    if (this != &other) {
      data_ = other.data_;
      current_node_ = other.current_node_;
      root_ = other.root_;
    }
    return *this;
  }

  btree_iterator &operator=(btree_iterator &&other) noexcept {
    if (this != &other) {
      data_ = (other.data_);
      current_node_ = std::move(other.current_node_);
      root_ = std::move(other.root_);
    }
    return *this;
  }

  // increment
  btree_iterator &operator++() {
    if (current_node_ != nullptr) {
      current_node_ = current_node_->next(current_node_);
      if (current_node_)
        data_ = std::make_pair(current_node_->data.first,
                               current_node_->data.second);
    }
    return *this;
  }

  btree_iterator operator++(int) {
    btree_iterator temp = *this;
    ++(*this);
    return temp;
  }

  // decrement
  btree_iterator &operator--() {
    if (current_node_ == nullptr) {
      current_node_ = root_->findMax(root_);
    } else {
      current_node_ = current_node_->prev(current_node_);
    }
    data_ =
        std::make_pair(current_node_->data.first, current_node_->data.second);

    return *this;
  }

  btree_iterator operator--(int) {
    btree_iterator temp = *this;
    --(*this);
    return temp;
    //!= nullptr ? temp : *this;
  }

  bool operator==(const btree_iterator &other) {
    return current_node_ == other.current_node_;
  }

  bool operator!=(const btree_iterator &other) {
    return current_node_ != other.current_node_;
  }

  reference operator*() const {
    if (current_node_ != nullptr) return (current_node_->data);

    return (root_->end_data);
  }

  value_type *operator->() const {
    if (current_node_ != nullptr) return &(current_node_->data);

    return &(root_->end_data);
  }

  friend class btree<K, V>;

  friend class btree_node<K, V>;
  friend class map<K, V>;
  friend class set<K>;

 protected:
  node_ptr current_node_;
  node_ptr root_;
  std::pair<K, V> data_;
};

}  // namespace s21
#include "../impl/btree_iterator.tpp"

#endif  // CONTAINERS_BTREE_ITERATOR_H
