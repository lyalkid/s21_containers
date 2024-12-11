#include "set.h"
namespace s21 {
    template<typename Key, typename T>
    typename set<Key, T>::insert_type set<Key, T>::insert(const value_type &value) {
        return insert_helper();
    }

    template<typename Key, typename T>
    typename set<Key, T>::insert_type set<Key, T>::insert_helper(const Key &key,
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
}