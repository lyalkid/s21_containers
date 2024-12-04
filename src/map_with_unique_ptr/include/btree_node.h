
#ifndef CONTAINERS_BTREE_NODE_H
#define CONTAINERS_BTREE_NODE_H

//#include <stddef.h>

#include <iostream>
#include <memory>
//#include <string>

//#include "btree.h"
namespace  s21 {

    template<typename Key, typename T>
    class map;

    template<typename K, typename V>
    class btree;

    template<typename K, typename V>
    class btree_iterator;

    template<typename K, typename V>
    class btree_node {
    private:
        std::pair <K, V> data;
        btree_node *parent;
        std::shared_ptr <btree_node> right;
        std::shared_ptr <btree_node> left;


    public:
        //        using value = std::pair<K, V>;
        btree_node() = default;

        btree_node(K, V);

        ~btree_node() = default;

        std::pair <K, V> get_data() { return data; }

        bool equals(const btree_node &other) const noexcept;

        btree_node &operator=(const btree_node &other);

        bool operator==(const btree_node &other) const noexcept;


        //        template<template K, template  V>
        friend class btree<K, V>;  //<K, V>;
        friend class btree_iterator<K, V>;

        friend class map<K, V>;
    };
}
#include "../impl/btree_node.tpp"
#endif //CONTAINERS_BTREE_NODE_H
