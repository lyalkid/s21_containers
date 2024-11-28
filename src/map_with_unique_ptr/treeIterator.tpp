#include "binaryTree.h"

namespace s21 {

    template<typename K, typename V>
    TreeIterator<K, V> &TreeIterator<K, V>::operator=(
            const TreeIterator<K, V> &other) {
        if (this == &other) {
            return *this;
        }
        this->~TreeIterator();
        currentNode_ = other.currentNode_;
        return *this;
    }

    template<typename K, typename V>
    TreeIterator<K, V> &TreeIterator<K, V>::operator++() {
        currentNode_ = next(currentNode_); // Переходим к следующему узлу
        return *this;
    }

    template<typename K, typename V>
    TreeIterator<K, V>::TreeIterator(const TreeIterator<K, V>& other)
            : currentNode_(other.currentNode_) , treeRoot_(other.treeRoot_){}

    template<typename K, typename V>
    TreeIterator<K, V> &TreeIterator<K, V>::operator--() {
        currentNode_ = prev(currentNode_); // Переходим к следующему узлу
        return *this;
    }
    template<typename K, typename V>
    TreeIterator<K, V> TreeIterator<K, V>::operator++(int) {
        TreeIterator temp = *this;
        ++(*this);
        return temp;
    }
    template<typename K, typename V>
    TreeIterator<K, V> TreeIterator<K, V>::operator--(int) {
        TreeIterator temp = *this;
        --(*this);
        return temp;
    }

    template<typename K, typename V>
    bool TreeIterator<K, V>::operator==(const TreeIterator &other) const {
        return currentNode_ == other.currentNode_;
    }

    template<typename K, typename V>
    bool TreeIterator<K, V>::operator!=(const TreeIterator &other) const {
        return currentNode_ != other.currentNode_;
    }

    template<typename K, typename V>
    TreeIterator<K, V>::~TreeIterator() {}

    template<typename K, typename V>
    TreeIterator<K, V>::TreeIterator(TreeNode<K, V> *node) {
        currentNode_ = node;
    }

    template<typename K, typename V>
    TreeIterator<K, V>::TreeIterator(K key, V value) {
        currentNode_ = TreeNode(key, value);
    }

    template<typename K, typename V>
    void TreeIterator<K, V>::set_root(TreeNode<K, V> *root) {
        treeRoot_ = root;
    }


    template<typename K, typename V>
    TreeNode<K, V> *TreeIterator<K, V>::findMin(
            TreeNode<K, V> *node) const {
        if (node->left == nullptr) {
            return node;
        }
        return findMin(node->left.get());
    }

    template<typename K, typename V>
    TreeNode<K, V> *TreeIterator<K, V>::findMax(
            TreeNode<K, V> *node) const {
        if (node->right == nullptr) {
            return node;
        }
        return findMax(node->right.get());
    }

    template<typename K, typename V>
    TreeNode<K, V> *TreeIterator<K, V>::next(TreeNode<K, V> *node) const {

        if(node->right!= nullptr){
            return findMin(node->right.get());
        }
        TreeNode<K, V>* parent = node->parent;
        while(parent && node == parent->right.get()){
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }


    template<typename K, typename V>
    TreeNode<K, V> *TreeIterator<K, V>::prev    (TreeNode<K, V> *node) const {


        if(node->left!= nullptr){
            return findMax(node->left.get());
        }
        TreeNode<K, V>* parent = node->parent;
        while(parent && node == parent->left.get()){
            node = parent;
            parent = parent->parent;
        }
        return parent;


    }
}  // namespace s21