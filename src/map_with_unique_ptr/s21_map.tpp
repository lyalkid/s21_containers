#include "s21_map.h"
namespace s21{
using std::pair;
using std::make_pair;
    template <typename Key, typename T>
    pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(const value_type &value){
        bool is_inserted = false;
        if(tree.find(tree.get_root(), value.first) == nullptr){
            is_inserted = true;
            tree.insert(value.first, value.second, is_inserted, it);
        }
        pair<typename map<Key, T>::iterator, bool> result = make_pair(it, is_inserted);
        return result;
    }

    template <typename Key, typename T>
    pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(const Key& key, const T& obj){
        bool is_inserted = false;
        if(tree.find(tree.get_root(), key) == nullptr){
            is_inserted = true;
            tree.insert(key, obj, is_inserted, it);
        }
        pair<typename map<Key, T>::iterator, bool> result = make_pair(it, is_inserted);
        return result;
    }

}