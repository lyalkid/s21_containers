#include "../include/s21_map.h"

namespace s21 {

// initializer list constructor, creates the map initizialized using
// std::initializer_list
    template<typename K, typename T>
    map<K, T>::map(std::initializer_list<value_type> const &items): map() {

        auto it = items.begin();
        while (it != items.end()) {
            //std::cout << "im in items"<< std::endl;
    insert(*it++);
        }
    }

// copy constructor
    template<typename K, typename T>
    map<K, T>::map(const map &m) : tree_(m.tree_), size_(m.size_) {}

    template<typename K, typename T>
    map<K, T>::map(map &&m) noexcept {
        tree_ = std::move(m.tree_);
        size_ = std::move(m.size_);

        //todo: во всех конструкторах перемещения сделать обнуление параметров
        m.tree_ = nullptr;
        m.size_ = 0;

    }

    template<typename K, typename T>
    map<K, T> &map<K, T>::operator=(const map &other) {
        if (this != &other) {
            tree_ = other.tree_;
            size_ = other.size_;
        }
        return *this;
    }

// todo: проверить все операторы во всех классах
    template<typename K, typename T>
    map<K, T> &map<K, T>::operator=(map &&other) noexcept {
        if (this != &other) {
            tree_ = std::move(other.tree_);
            size_ = std::move(other.size_);

            //todo: во всех операторах перемещения сделать обнуление параметров
            other.tree_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    template<typename K, typename T>
    typename map<K, T>::mapped_type &map<K, T>::at(const key_type &key) {
        iterator it = tree_->search(key);
        if (it == end()) {
            throw std::out_of_range("map::at");
        }
        return (it->second);
    }

    template<typename K, typename T>
    typename map<K, T>::mapped_type &map<K, T>::operator[](const key_type &key) {
         return (insert(std::make_pair(key, T())).first)->second;

    }


    template<typename K, typename T>
    typename map<K, T>::insert_type map<K, T>::insert(const value_type &value) {
        return insert_helper(value.first, value.second);
        bool is_contains = contains(value.first);
        if (!is_contains) {
            tree_->insert(value.first, value.second);
            size_++;
        }
        iterator it(tree_->find(tree_->bt_root_, value.first).get());

        insert_type res = std::make_pair(it, !is_contains);
        return res;
    }

    template<typename K, typename T>
    typename map<K, T>::insert_type map<K, T>::insert(const K &key, const T &obj) {
        return insert_helper(key, obj);

    }

    template<typename K, typename T>
    typename map<K, T>::insert_type map<K, T>::insert_helper(const K &key, const T &obj) {
        bool is_contains = contains(key);
        if (!is_contains) {
            tree_->
                    insert(key, obj);
            size_++;
        }
        iterator it(tree_->find(tree_->bt_root_, key).get());

        insert_type res = std::make_pair(it, (is_contains ? false : true));
        return
                res;
    }

    template<typename K, typename T>
    bool map<K, T>::contains(const key_type &key) const {
        return (tree_ != nullptr && tree_->contains(key));
    }

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
//   if (tree.find(tree.get_root(), value.first) == nullptr) {
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
//   if (tree.find(tree.get_root(), key) == nullptr) {
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