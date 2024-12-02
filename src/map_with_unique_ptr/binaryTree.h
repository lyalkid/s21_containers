#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>

#include <iostream>
#include <memory>
#include <string>
// #include "node.h"

/// @brief
namespace s21 {
    using std::shared_ptr;

    template<typename Key, typename T>
    class map;

    template<typename K, typename V>
    class btree_node;

    template<typename K, typename V>
    class btree_iterator;

    template<typename K, typename V>
    class btree_const_iterator;

    template<typename K, typename V>
    class btree {
    public:
        using key_type = K;
        using mapped_type = V;
        using value_type = std::pair<const key_type, mapped_type>;
        using node_type = btree_node<K, V>;
        using reference = value_type &;
        using const_reference = const value_type &;
        using iterator = btree_iterator<K, V>;
        using const_iterator = btree_const_iterator<K, V>;
        using size_type = size_t;
        using sh_ptr_iterator = std::shared_ptr<btree_iterator<K, V>>;
        using node_ptr = shared_ptr<btree_node<K, V>>;


        btree() : bt_root_(nullptr), bt_size_() {}


        btree(const btree &other) : bt_root_(other.bt_root_), bt_size_(other.bt_size_) {}

        btree(btree &&bt) noexcept {
            bt_root_ = std::move(bt.bt_root_);
            bt_size_ = std::move(bt.size_);
        }

        btree(K key, V value) {
            bt_root_ = std::make_shared<node_type >>(key, value);
            bt_size_ = 1;
        }

        btree(value_type data){
            bt_root_ = std::make_shared<node_type >>(data.first, data.second);
            bt_size_ = 1;
        }

        ~btree();

        btree &operator=(const btree &other) {
            if (this != &other) {
                bt_root_.reset();
                bt_root_ = other.bt_root_;
                bt_size_ = other.bt_size_;
            }
            return *this;
        }

        btree &operator=(btree &&other) noexcept {
            if (this == &other) {
                bt_root_ = std::move(other.bt_root_);
                bt_size_ = std::move(other.bt_size_);
            }
            return *this;
        }


        void insert(K key, V value, bool &is_inserted);

        node_ptr find(node_ptr node,
                      K key) const;


        node_ptr get_root();

        size_type size() const { return bt_size_; }

        bool contains(const K &key) const { return this->find(bt_root_, key) != nullptr; }

        void destroyRecursive(btree_node<K, V> *node);

        void in_order_tree_walk(node_ptr node);

        friend class btree_iterator<K, V>;

        friend class map<K, V>;

    private:
        node_ptr bt_root_;
        //iterator bt_it_;
        size_t bt_size_;
    };

    template<typename K, typename V>
    class btree_const_iterator {

    };

    template<typename K, typename V>
    class btree_iterator {
    public:
        using node = btree_node<K, V>;
        using value_type = std::pair<const K, V>;
        using reference = value_type &;
        using pointer = value_type *;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;

        btree_iterator() = default;

        btree_iterator(btree_node<K, V> *node);

        btree_iterator(const btree_iterator<K, V> &other);

        btree_iterator(K key, V value);

        ~btree_iterator();

        void set_root(btree_node<K, V> *bt_root_);

        btree_iterator &operator=(const btree_iterator &other);

        btree_iterator &operator++();

        btree_iterator &operator--();

        btree_iterator operator++(int);

        btree_iterator operator--(int);


        bool operator==(const btree_iterator &other) const;

        bool operator!=(const btree_iterator &other) const;

        reference operator*() const { return currentNode_->data; }

        std::pair<K, V> *operator->() const { return &(currentNode_->data); }

        btree_node<K, V> *findMin(btree_node<K, V> *node) const;

        btree_node<K, V> *findMax(btree_node<K, V> *node) const;

        btree_node<K, V> *next(btree_node<K, V> *node) const;

        btree_node<K, V> *prev(btree_node<K, V> *node) const;


        friend class btree<K, V>;  //<K, V>;
        friend class map<K, V>;

    private:
        node *treeRoot_;
        node *currentNode_;
    };

    template<typename K, typename V>
    class btree_node {
    private:
        std::pair<K, V> data;
        btree_node *parent;
        std::shared_ptr<btree_node> right;
        std::shared_ptr<btree_node> left;

        size_t lvl;

    public:
        //        using value = std::pair<K, V>;
        btree_node() = default;

        btree_node(K, V);

        ~btree_node() = default;

        std::pair<K, V> get_data() { return data; }

        bool equals(const btree_node &other) const noexcept;

        btree_node &operator=(const btree_node &other);

        bool operator==(const btree_node &other) const noexcept;


        //        template<template K, template  V>
        friend class btree<K, V>;  //<K, V>;
        friend class btree_iterator<K, V>;

        friend class map<K, V>;
    };

//    template<typename K, typename V>
//    template<typename T>
//
//
//    template<typename K, typename V>
//    template<typename T>

}  // namespace s21
#include "binaryTree.tpp"
#include "node.tpp"
#include "treeIterator.tpp"

#endif  // BINARY_TREE_H_
