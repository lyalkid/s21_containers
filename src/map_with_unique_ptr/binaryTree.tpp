#include "binaryTree.h"

namespace s21 {

    template<typename K, typename V>
    BinaryTree<K, V>::BinaryTree(/* args */) {
        root = nullptr;
        count = 0;
    }

    template<typename K, typename V>
    BinaryTree<K, V>::BinaryTree(Node<K, V> root) {

        *(this->root) = root;
        count = 0;
    }

    template<typename K, typename V>
    BinaryTree<K, V>::BinaryTree(K key, V value) {
        this->root = Node(key, value);
        count = 0;
    }


    template<typename K, typename V>
    BinaryTree<K, V>::~BinaryTree() {

    }

    template<typename K, typename V>
    void BinaryTree<K, V>::destroyRecursive(Node<K, V> *node) {
        if (node != nullptr) {
            destroyRecursive(node->left);
            destroyRecursive(node->right);

        }
    }

// insert
    template<typename K, typename V>
    Node<K, V>* BinaryTree<K, V>::insert(K key, V value) {
        if (root == nullptr) {
            root = std::make_unique<Node<K, V>>(key, value);
            count++;
            root->parrent = nullptr;
            return root.get();
        }

//        Node<K, V> *temp = new Node(key, value);

        std::unique_ptr<Node<K, V>> temp = std::make_unique<Node<K, V>>(key, value);
        Node < K, V > *parent = nullptr;
        Node < K, V > *current = root.get();
        while (current != nullptr) {
            parent = current;
            // вот здесь можно чекать добавляем ли мы уже существующий ключ
            if (current->key >= key) {
                current = current->left.get();
            } else if (current->key < key) {
                current = current->right.get();
            }
        }
        temp->parrent = parent;
        temp->lvl = (parent->lvl) + 2;

        if (parent->key > key)
            parent->left = std::move(temp);
        else
            parent->right =  std::move(temp);;
        count++;
        return root.get();
    }

  //  template<typename K, typename V>
//    std::unique_ptr<Node<K, V>> BinaryTree<K, V>::find(std::unique_ptr<Node<K, V>> root, K key) {
//        Node < K, V > *res = nullptr;
//        if (root == nullptr || root->key == key) {
//            res = root;
//        }
//            // TODO : когда уберу дубликаты, сделать строгое неравенство
//        else {
//            if (key <= root->key) {
//                find(root->left, key);
//            } else {
//                find(root->right, key);
//            }
//        }
//        return res;
//    }
//
//    template<typename K, typename V>
//    std::unique_ptr<Node<K, V>> BinaryTree<K, V>::iterrative_find(std::unique_ptr<Node<K, V>> node, K key) {
//        while (node != nullptr && node->key != key) {
//            if (key <= node->key) {
//                node = node->left;
//            } else {
//                node = node->right;
//            }
//        }
//        return node;
//    }
//
//// обход дерева
//    template<typename K, typename V>
//    void BinaryTree<K, V>::in_order_tree_walk(std::unique_ptr<Node<K, V>> node) {
//        if (node != nullptr) {
//            in_order_tree_walk(node->right);
//            std::cout << std::string(node->lvl, ' ') << node->key << std::endl;
//            in_order_tree_walk(node->left);
//        }
//    }
//
//
//    template<typename K, typename V>
//    void BinaryTree<K, V>::remove(std::unique_ptr<Node<K, V>> node, K key) {
//        Node < K, V > *delete_node = iterrative_find(node, key);
//        Node < K, V > *parrent = delete_node->parrent;
//        if (delete_node->left == nullptr && delete_node->right == nullptr) {
//            if (parrent->left == delete_node) {
//                parrent->left->~Node();
//                parrent->left = nullptr;
//            } else {
//                parrent->right->~Node();
//                parrent->right = nullptr;
//            }
//            count--;
//        }
//    }
//
//
//// get size
//    template<typename K, typename V>
//    size_t BinaryTree<K, V>::size() {
//        return count;
//    }
//
//    template<typename K, typename V>
//    bool BinaryTree<K, V>::isEmpty() {
//        return count == 0;
//    }
//
//    template<typename K, typename V>
//    std::unique_ptr<Node<K, V>> BinaryTree<K, V>::get_root() {
//        return root;
//    }
}  // namespace s21
