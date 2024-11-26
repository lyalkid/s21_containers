#include "binaryTree.h"

namespace s21 {
//    template<typename K, typename V>
    using std::pair;
    using std::make_shared;
    using std::make_pair;


    template<typename K, typename V>
    BinaryTree<K, V>::BinaryTree() {
        root = nullptr;
        it = nullptr;
        count = 0;

    }

    template<typename K, typename V>
    BinaryTree<K, V>::BinaryTree(K key, V value) {
        root = std::make_shared<TreeNode<K, V>>(key, value);
        it = TreeIterator<K, V>(key, value);
        count = 0;
    }

    template<typename K, typename V>
    BinaryTree<K, V>::~BinaryTree() = default;

// insert
    template<typename K, typename V>
    std::pair<typename BinaryTree<K, V>::iterator, bool> BinaryTree<K, V>::insert(K key, V value) {
        using btree_it = typename BinaryTree<K, V>::iterator;
//        bool flag = false;
        std::pair<btree_it, bool> result;
        if (root == nullptr) {
            root = std::make_shared<TreeNode<K, V>>(key, value);
            it = TreeIterator<K, V>(root.get());
            count++;
            result = std::make_pair(it, true);
            return result;
        }
        /*
         * other cases
         * */
        return result;
    }

}  // namespace s21
