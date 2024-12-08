#ifndef S21_MAP_H_
#define S21_MAP_H_

#include "btree.h"

namespace s21 {

template <typename Key, typename T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename btree<key_type, mapped_type>::iterator;
  using const_iterator = const iterator;
  using size_type = size_t;
  using tree_type = btree<Key, T>;
    using insert_type = std::pair<iterator, bool> ;
  // Constructors
  map() {
      tree_ = new btree<Key, T>();
      size_ = 0;
  };

  //  map(const Key key, T value) : tree_(key, value), size_(1) {}

  map(std::initializer_list<value_type> const &items);

  map(const map &m);

  map(map &&m) noexcept;

  map &operator=(const map &other);
  map &operator=(map &&other) noexcept;

  ~map() = default;

  mapped_type &at(const key_type &key);

  mapped_type &operator[](const key_type &key);

  iterator begin(){
      return tree_->begin();
  }

  iterator end(){
      return tree_->end();
  }

  bool empty() const{
      return size_ == 0 || tree_ == nullptr;
  }

  size_type size() const{
      return size_;
  }

  void clear();

  std::pair<iterator, bool> insert(const value_type &value);

  std::pair<iterator, bool> insert(const Key &key, const T &obj);

  void erase(iterator pos);

  bool contains(const key_type &key) const;

 private:
  tree_type* tree_;
  size_type size_;
  void clearHelper(std::shared_ptr<btree_node<Key, T>> &node);
  insert_type insert_helper(const key_type &key, const mapped_type &obj);
};
}  // namespace s21

#include "../impl/s21_map.tpp"

#endif  // S21_MAP_H_