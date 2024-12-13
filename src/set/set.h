
#ifndef S21_SET_H
#define S21_SET_H

#include "../map_with_unique_ptr/include/btree.h"
#include "../vector/vector.h"
namespace s21 {
template <typename Key>
class set {
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
  ;
  using node_type = btree_node<key_type, key_type>;
  using tree_type = btree<key_type, key_type>;
  set() {
    tree_ = std::make_shared<tree_type>();
    size_ = 0;
  }

  set(std::initializer_list<value_type> const &items) : set() {
    auto it = items.begin();
    while (it != items.end()) {
      // std::cout << "im in items"<< std::endl;
      insert(*it++);
    }
  }

  set(const set &m) : tree_(m.tree_), size_(m.size_) {}

  set(set &&m) noexcept {
    tree_ = std::move(m.tree_);
    size_ = std::move(m.size_);

    // todo: во всех конструкторах перемещения сделать обнуление параметров
    m.tree_ = nullptr;
    m.size_ = 0;
  }

  set &operator=(const set &other) {
    if (this != &other) {
      tree_ = other.tree_;
      size_ = other.size_;
    }
    return *this;
  }

  set &operator=(set &&other) noexcept {
    if (this != &other) {
      tree_ = std::move(other.tree_);
      size_ = std::move(other.size_);

      // todo: во всех операторах перемещения сделать обнуление параметров
      other.tree_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }

  ~set() = default;

  iterator begin() { return tree_->begin_si(); }
  iterator end() { return tree_->end_si(); }
  bool empty() const { return size_ == 0 || tree_ == nullptr; }
  size_type size() { return size_; }
  size_type max_size() { return tree_->max_size(); }

  void clear() {
    tree_->clear();
    size_ = 0;
  }
  insert_type insert(const value_type &value) {
    bool flag = contains(value);
    if (!flag) {
      tree_->insert(value, value);
      size_++;
    }
    iterator it(tree_->find_helper(tree_->bt_root_, value));

    insert_type res = std::make_pair(it, !flag);
    return res;
  }

  void erase(iterator pos) {
    if (pos != end()) {
      tree_->remove(*pos);
      size_ = tree_->size();
    }
  }

  void swap(set &other) {
    std::swap(tree_, other.tree_);
    std::swap(size_, other.size_);
  }

  void merge(set &other) {
    for (auto iter = other.begin(); !other.empty() && iter != other.end();
         iter++) {
      if (!contains(*iter)) {
        insert(*iter);
        other.erase(iter);
      }
    }
  }

  iterator find(const Key &key) {
    set_iterator s_iter(tree_->search(key));
    return s_iter;
  }
  bool contains(const Key &key) {
    return (tree_ != nullptr && tree_->contains(key));
  }

  //   s21::vector<std::pair<iterator,bool>> insert_many(Args&&... args){

  //   }

 private:
  shared_ptr<tree_type> tree_;
  size_type size_;
};
}  // namespace s21
#include "set.tpp"

#endif