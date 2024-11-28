#include "s21_map.h"
namespace s21 {
using std::make_pair;
using std::pair;
template <typename Key, typename T>
pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  bool is_inserted = false;
  if (tree.find(tree.get_root(), value.first) == nullptr) {
    is_inserted = true;
    tree.insert(value.first, value.second, is_inserted, it);
  }
  pair<typename map<Key, T>::iterator, bool> result =
      make_pair(it, is_inserted);
  if (is_inserted) size_++;
  return result;
}

template <typename Key, typename T>
pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(const Key& key,
                                                               const T& obj) {
  bool is_inserted = false;
  if (tree.find(tree.get_root(), key) == nullptr) {
    is_inserted = true;
    tree.insert(key, obj, is_inserted, it);
  }
  pair<typename map<Key, T>::iterator, bool> result =
      make_pair(it, is_inserted);
  if (is_inserted) size_++;
  return result;
}
template <typename Key, typename T>
void map<Key, T>::clear() {
  size_ = 0;
  clearHelper(tree.root);
  tree.size_ = 0;
}
template <typename Key, typename T>
void map<Key, T>::clearHelper(std::shared_ptr<TreeNode<Key, T>>& node) {
  if (node) {
    clearHelper(node->left);
    clearHelper(node->right);
    node.reset();  // Освобождаем узел
  }
}
template <typename Key, typename T>
bool map<Key, T>::contains(const Key& key) const {
  return tree.contains(key);
}
template <typename Key, typename T>
bool map<Key, T>::empty() const {
  return this->size() == 0;
}
template <typename Key, typename T>
size_t map<Key, T>::size() const {
  return size_;
}

}  // namespace s21