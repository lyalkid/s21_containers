#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>
#include <memory>
#include <iostream>
#include <string>
//#include "node.h"

/// @brief
namespace s21 {

    template<typename K, typename V>
    class Node;

    template<typename K, typename V>
    class BinaryTree {
    private:
        std::unique_ptr<Node<K, V>> root;
        size_t count;


    public:
        BinaryTree();

        BinaryTree(Node<K, V> root);

        BinaryTree(K key, V value);

        ~BinaryTree();
        Node<K, V>* insert(K key, V value);

        //
        void destroyRecursive(Node<K, V> *node);
//
//
//
//        // methods
//
//        std::unique_ptr<Node<K, V>> find(std::unique_ptr<Node<K, V>> root, K key);
//
//        std::unique_ptr<Node<K, V>> iterrative_find(std::unique_ptr<Node<K, V>> root, K key);
//        // обход дерева
//        void in_order_tree_walk(std::unique_ptr<Node<K, V>> node);
//
//        void remove(std::unique_ptr<Node<K, V>> , K key);
//
//        bool isEmpty();
//
//        size_t size();
//
//        std::unique_ptr<Node<K, V>> get_root();
//        // overload operators
    };

/*
 class Node
*/
    template<typename K, typename V>
    class Node {
    private:
        K key;
        V value;
        Node* parrent;
        std::unique_ptr<Node> right;
        std::unique_ptr<Node> left;
        size_t lvl;
        // bool red;
        // bool isLeftChild;

    public:
        Node(K key, V Value);

        ~Node();

        Node &operator=(const Node &other);

        friend class BinaryTree<K, V>;
    };

}  // namespace s21
#include "binaryTree.tpp"
#include "node.tpp"

#endif  // BINARY_TREE_H_
