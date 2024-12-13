#include "map.h"

namespace s21 {

// initializer list constructor, creates the map initizialized using
// std::initializer_list

// copy constructor
template <typename K, typename T>
map<K, T>::map(const map &m) : tree_(m.tree_), size_(m.size_) {}

template <typename K, typename T>
map<K, T>::map(map &&m) noexcept {
  tree_ = std::move(m.tree_);
  size_ = std::move(m.size_);

  // todo: во всех конструкторах перемещения сделать обнуление параметров
  m.tree_ = nullptr;
  m.size_ = 0;
}

template <typename K, typename T>
map<K, T> &map<K, T>::operator=(const map &other) {
  if (this != &other) {
    tree_ = other.tree_;
    size_ = other.size_;
  }
  return *this;
}

// todo: проверить все операторы во всех классах
template <typename K, typename T>
map<K, T> &map<K, T>::operator=(map &&other) noexcept {
  if (this != &other) {
    tree_ = std::move(other.tree_);
    size_ = std::move(other.size_);

    // todo: во всех операторах перемещения сделать обнуление параметров
    other.tree_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <typename K, typename T>
typename map<K, T>::mapped_type &map<K, T>::at(const key_type &key) {
  iterator it = tree_->search(key);
  if (it != end()) {
    return (it->second);
  }
  throw std::out_of_range("map::at");
}

template <typename K, typename T>
typename map<K, T>::mapped_type &map<K, T>::operator[](const key_type &key) {
  return (insert(std::make_pair(key, T())).first)->second;
}

template <typename K, typename T>
typename map<K, T>::insert_type map<K, T>::insert(const value_type &value) {
  return insert_helper(value.first, value.second);
  //  bool is_contains = contains(value.first);
  //  if (!is_contains) {
  //    tree_->insert(value.first, value.second);
  //    size_++;
  //  }
  //  iterator it(tree_->find_helper(tree_->bt_root_, value.first).get());
  //
  //  insert_type res = std::make_pair(it, !is_contains);
  //  return res;
}

template <typename K, typename T>
typename map<K, T>::insert_type map<K, T>::insert(const K &key, const T &obj) {
  return insert_helper(key, obj);
}

template <typename K, typename T>
typename map<K, T>::insert_type map<K, T>::insert_or_assign(const K &key,
                                                            const T &obj) {
  bool is_contains = contains(key);
  if (!is_contains) {
    insert(key, obj);
  } else {
    iterator temp = find(key);
    temp.current_node_->data.second = obj;
  }
  iterator iter = find(key);
  insert_type res = std::make_pair(iter, !is_contains);
  return res;
}

template <typename K, typename T>
typename map<K, T>::insert_type map<K, T>::insert_helper(const K &key,
                                                         const T &obj) {
  bool is_contains = true;

  is_contains = contains(key);
  if (!is_contains) {
    tree_->insert(key, obj);
    size_++;
  }
  iterator it(tree_->find_helper(tree_->bt_root_, key));

  insert_type res = std::make_pair(it, !is_contains);
  return res;
}

// todo :  поменять возвращаемый тип
template <typename K, typename T>
void map<K, T>::erase(iterator pos) {
  if (pos != end()) {
    tree_->remove(pos->first);
    size_ = tree_->size();

    //  pos.current_node_.reset();
  }
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::find(const K &key) const {
  return tree_->search(key);
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::find(value_type value) const {
  return tree_->search(value);
}

template <typename K, typename T>
bool map<K, T>::contains(const key_type &key) const {
  return (tree_ != nullptr && tree_->contains(key));
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::begin() {
  return size_ != 0 ? tree_->begin() : tree_->end();
}

template <typename K, typename T>
typename map<K, T>::iterator map<K, T>::end() {
  return tree_->end();
}

template <typename K, typename T>
void map<K, T>::clear() noexcept {
  tree_->clear();
  size_ = 0;
}

template <typename K, typename T>
void map<K, T>::swap(map &other) noexcept {
  std::swap(tree_, other.tree_);
  std::swap(size_, other.size_);
}

template <typename K, typename T>
void map<K, T>::merge(map &other) noexcept {
  for (auto iter = other.begin(); !other.empty() && iter != other.end();
       iter++) {
    if (!contains(iter.current_node_->data.first)) {
      insert(iter.current_node_->data.first, iter.current_node_->data.second);
      other.erase(iter);
    }
  }
}

template <typename K, typename T>
template <typename... Args>
typename map<K, T>::insert_many_type map<K, T>::insert_many(Args &&...args) {
  auto res = tree_->insert_many(args...);
  size_ = tree_->size();
  return res;
}

// template <typename K, typename T>
// typename map<K, T>::iterator map<K, T>::find_helper(const K &key) const {
//     return tree_->find_helper(key);
// }
//
//
//     template <typename K, typename T>
//     typename map<K, T>::iterator map<K, T>::find_helper( reference value)
//     const {
//         return tree_->find_helper(value);
//     }

// using std::make_pair;
// using std::pair;
// template <typename Key, typename T>
// using iterator = typename btree<Key, T>::iterator;
//
// template <typename Key, typename T>
// map<Key, T>::map(const map &m) : tree(m.tree), size_(m.size_) {}
// template <typename Key, typename T>
// map<Key, T>::map(map &&m) : tree(std::move(m.tree)), size_(m.size_) {
//   m.size_ = 0;
// }
// template <typename Key, typename T>
// pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
//     const value_type &value) {
//   bool is_inserted = false;
//   if (tree.find_helper(tree.get_root(), value.first) == nullptr) {
//     is_inserted = true;
//     tree.insert(value.first, value.second, is_inserted);
//   }
//   pair<typename map<Key, T>::iterator, bool> result =
//       make_pair(tree.it, is_inserted);
//   if (is_inserted) size_++;
//   return result;
// }
//
// template <typename Key, typename T>
// pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(const Key
// &key,
//                                                                const T &obj)
//                                                                {
//   bool is_inserted = false;
//   if (tree.find_helper(tree.get_root(), key) == nullptr) {
//     is_inserted = true;
//     tree.insert(key, obj, is_inserted);
//   }
//   pair<typename map<Key, T>::iterator, bool> result =
//       make_pair(tree.it, is_inserted);
//   if (is_inserted) size_++;
//   return result;
// }
//
// template <typename Key, typename T>
// void map<Key, T>::clear() {
//   size_ = 0;
//   clearHelper(tree.root);
//   tree.size_ = 0;
// }
//
// template <typename Key, typename T>
// void map<Key, T>::clearHelper(std::shared_ptr<btree_node<Key, T>> &node) {
//   if (node) {
//     clearHelper(node->left);
//     clearHelper(node->right);
//     node.reset();  // Освобождаем узел
//   }
// }
//
// template <typename Key, typename T>
// bool map<Key, T>::contains(const Key &key) const {
//   return tree.contains(key);
// }
//
// template <typename Key, typename T>
// bool map<Key, T>::empty() const {
//   return this->size() == 0;
// }
//
// template <typename Key, typename T>
// size_t map<Key, T>::size() const {
//   return size_;
// }
//
// template <typename Key, typename T>
// iterator<Key, T> map<Key, T>::begin() {
//   btree_node<Key, T> *current = tree.root.get();
//   while (current->left != nullptr) {
//     current = current->left.get();
//   }
//
//   tree.it.currentNode_ = current;
//   iterator &ref = tree.it;
//   return ref;
// }
//
// template <typename Key, typename T>
// iterator<Key, T> map<Key, T>::end() {
//   btree_node<Key, T> *current = tree.root.get();
//   while (current->right != nullptr) {
//     current = current->right.get();
//   }
//   tree.it.currentNode_ = current->right.get();
//   return tree.it;
// }

}  // namespace s21