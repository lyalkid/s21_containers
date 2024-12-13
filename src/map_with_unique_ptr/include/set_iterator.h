#ifndef CONTAINERS_SET_ITERATOR_H
#define CONTAINERS_SET_ITERATOR_H

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


template <typename K,typename V>
class btree_iterator ;


template <typename K, typename V>
class set_iterator {
 public:
  using node_type = btree_node<K, V>;
  using node_ptr = std::shared_ptr<node_type>;
  using value_type = K;
  using reference = value_type &;
  using pointer = value_type *;

  set_iterator(const btree_iterator<K, V> &iter){
    current_node_ = iter.current_node_;
    root_=iter.root_;
    data_=iter.data_;
  }

  // default constructor
  set_iterator()
      : current_node_(nullptr),
        root_(nullptr),
        data_(std::make_pair(K{}, V{})) {};

  // init iterator
  set_iterator(node_ptr node) : current_node_(node), root_(nullptr) {
    if (node == nullptr) {
      data_ = (std::make_pair(K{}, V{}));
    } else {
      data_ = (std::make_pair(node->data.first, node->data.second));
    }
  };

  // copy constructor
  set_iterator(const set_iterator &other)
      : current_node_(other.current_node_),
        root_(other.root_),
        data_(other.data_) {};

  // move constructor
  set_iterator(set_iterator &&other) {
    data_ = std::make_pair(std::move(other.data_.first),
                           std::move(other.data_.second));
    current_node_ = std::move(other.current_node_);
    root_ = std::move(other.root_);
  };

  // destructor
  ~set_iterator() {
    current_node_.reset();
    root_.reset();
  }

  // constructor for end
  set_iterator(node_ptr current_node, node_ptr root)
      : current_node_(current_node), root_(root) {
    if (current_node_ == nullptr) {
      data_ = (std::make_pair(K{}, V{}));
    } else {
      data_ =
          (std::make_pair(current_node->data.first, current_node->data.second));
    }
  };

  set_iterator &operator=(const set_iterator &other) {
    if (this != &other) {
      data_ = other.data_;
      current_node_ = other.current_node_;
      root_ = other.root_;
    }
    return *this;
  }

  set_iterator &operator=(set_iterator &&other) noexcept {
    if (this != &other) {
      data_ = (other.data_);
      current_node_ = std::move(other.current_node_);
      root_ = std::move(other.root_);
    }
    return *this;
  }

  // increment
  set_iterator &operator++() {
    if (current_node_ != nullptr) {
        auto  temp = current_node_->next(current_node_);
      current_node_= temp;
        if (current_node_)
        data_ = std::make_pair(current_node_->data.first,
                               current_node_->data.second);
    }
    return *this;
  }

  set_iterator operator++(int) {
    set_iterator temp = *this;
    ++(*this);
    return temp;
  }

  // decrement
  set_iterator &operator--() {
    if (current_node_ == nullptr) {
      current_node_ = root_->findMax(root_);
    } else {
      current_node_ = current_node_->prev(current_node_);
    }
    data_ =
        std::make_pair(current_node_->data.first, current_node_->data.second);

    return *this;
  }

  set_iterator operator--(int) {
    set_iterator temp = *this;
    --(*this);
    return temp;
    //!= nullptr ? temp : *this;
  }

  bool operator==(const set_iterator &other) {
    return current_node_ == other.current_node_;
  }

  bool operator!=(const set_iterator &other) {
    return current_node_ != other.current_node_;
  }

  reference operator*() const {
    if (current_node_ != nullptr) {
      return (current_node_->data.second);
    }
    return (root_->end_data.second);
  }

  value_type *operator->() const {
    if (current_node_ != nullptr) return &(current_node_->data);

    return &(root_->end_data);
  }

  friend class btree<K, V>;

  friend class btree_node<K, V>;
  friend class map<K, V>;
  friend class set<K>;
  friend class btree_iterator<K, V> ;

 protected:
  node_ptr current_node_;
  node_ptr root_;
  std::pair<K, V> data_;
};

}  // namespace s21

#endif  // CONTAINERS_set_iterator_H
