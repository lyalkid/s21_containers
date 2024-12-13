#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "../s21set/set.h"
namespace s21 {
template <typename Key>
class multiset : public set<Key> {
 public:
  using key_type = Key;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = set_iterator<key_type, key_type>;
  using const_iterator = const iterator;
  using size_type = size_t;
  using insert_type = std::pair<iterator, bool>;
  using insert_many_type = s21::vector<insert_type>;

  using mapped_type = std::pair<key_type, key_type>;

  using node_type = btree_node<key_type, key_type>;
  using tree_type = btree<key_type, key_type>;
  multiset() : set<Key>() {}
  multiset(std::initializer_list<value_type> const &items) : set<Key>(items) {}
  multiset(const set<Key> &m) : set<Key>(m) {}
  multiset(set<Key> &&m) noexcept : set<Key>(m) {}
  ~multiset() = default;

  using set<Key>::begin;
  using set<Key>::end;
  using set<Key>::empty;
  using set<Key>::max_size;
  using set<Key>::size;
  using set<Key>::clear;
  using set<Key>::erase;
  using set<Key>::swap;
  using set<Key>::merge;
  using set<Key>::find;
  using set<Key>::contains;
  insert_type insert(const value_type &value) override {
    bool flag = contains(value);

    set<key_type>::tree_->insert(value, value);
    set<key_type>::size_++;

    iterator it(set<key_type>::tree_->find_helper(
        set<key_type>::tree_->bt_root_, value));

    insert_type res = std::make_pair(it, !flag);
    return res;
  }
  size_type count(const Key &key) {
    size_type res = 0;
    for (auto it = begin(); it != end(); it++) {
      if (*it == key) {
        res += 1;
      }
      if (*it > key) break;
    }
    return res;
  }

  std::pair<iterator, iterator> equal_range(const Key &key) {
    std::pair<iterator, iterator> res = std::make_pair<iterator, iterator>();
    size_t count = 0;
    for (auto it = begin(); it != end(); it++) {
      if (*it == key && count == 0) {
        res.first = it;
        count++;
      }
      if (*it != key && count >= 1) {
        res.second = it--;
        break;
      }
    }
    return res;
  }
  iterator lower_bound(const Key &key) {
    auto it = begin();
    for (; it != end(); it++) {
      if (*it >= key) return it;
    }
    return it;
  }
  iterator upper_bound(const Key &key) {
    auto it = begin();
    for (; it != end(); it++) {
      if (*it > key) return it;
    }
    return it;
  }
};
}  // namespace s21


#endif