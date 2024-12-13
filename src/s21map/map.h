#ifndef S21_MAP_H_
#define S21_MAP_H_

#include "../s21btree/btree.h"

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
  using insert_type = std::pair<iterator, bool>;
  using insert_many_type = s21::vector<std::pair<iterator, bool>>;

  // Constructors
  map() {
    tree_ = std::make_shared<tree_type>();
    size_ = 0;
  }

  map(std::initializer_list<value_type> const &items) : map() {
    auto it = items.begin();
    while (it != items.end()) {
      // std::cout << "im in items"<< std::endl;
      insert(*it++);
    }
  }

  map(const map &m);

  map(map &&m) noexcept;

  map &operator=(const map &other);

  map &operator=(map &&other) noexcept;

  ~map() = default;

  // element access
  mapped_type &at(const key_type &key);

  mapped_type &operator[](const key_type &key);

  // iterator
  iterator begin();

  iterator end();

  // size and capacity
  bool empty() const { return size_ == 0 || tree_ == nullptr; }

  size_type size() const { return size_; }

  size_type max_size() const { return tree_->max_size(); }

  // insertion
  insert_type insert(const_reference value);

  insert_type insert(const Key &key, const T &obj);

  insert_type insert_or_assign(const Key &key, const T &obj);

  void erase(iterator pos);

  void clear() noexcept;

  // find
  iterator find(const Key &key) const;

  iterator find(value_type value) const;

  // check contains
  bool contains(const key_type &key) const;

  // modifications
  void swap(map &other) noexcept;

  void merge(map &other) noexcept;

  // advanced
  template <typename... Args>
  insert_many_type insert_many(Args &&...args);

 private:
  shared_ptr<tree_type> tree_;
  size_type size_;

  void clearHelper(std::shared_ptr<btree_node<Key, T>> &node);

  insert_type insert_helper(const key_type &key, const mapped_type &obj);
};
}  // namespace s21

#include "map.tpp"

#endif  // S21_MAP_H_