#include "binaryTree.h"

namespace s21 {

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree(/* args */) {
  root = nullptr;
  count = 0;
}

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree(Node<K, V> root) {
  this->root = root;
}

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree(K key, V value) {
  this->root = Node(key, value);
}

template <typename K, typename V>
BinaryTree<K, V>::~BinaryTree() {}

// insert
template <typename K, typename V>
Node<K, V> *BinaryTree<K, V>::insert(K key, V value) {
  Node<K, V> *temp = new Node(key, value);
  if (root == nullptr) {
    root = temp;
    count++;
    return root;
  }

  Node<K, V> *parent = nullptr;
  Node<K, V> *current = root;
  while (current != nullptr) {
    parent = current;

    // вот здесь можно чекать добавляем ли мы уже существующий ключ
    if (current->key >= key) {
      current = current->left;
    } else if (current->key < key) {
      current = current->right;
    }
  }
  if (parent->key > key)
    parent->left = temp;
  else
    parent->right = temp;
  temp->lvl = (parent->lvl) + 2;
  count++;
  return root;
}

template <typename K, typename V>
Node<K, V> *BinaryTree<K, V>::find(Node<K, V> *root, K key) {
  if (root == nullptr || root->key == key) {
    return root;
  }
  // TODO : когда уберу дубликаты, сделать строгое неравенство
  if (key <= root->key) {
    find(root->left, key);
  } else {
    find(root->right, key);
  }
}

// обход дерева
template <typename K, typename V>
void BinaryTree<K, V>::in_order_tree_walk(Node<K, V> *node) {
  if (node != nullptr) {
    in_order_tree_walk(node->right);
    std::cout << std::string(node->lvl, ' ') << node->key << std::endl;
    in_order_tree_walk(node->left);
  }
}

// get size
template <typename K, typename V>
size_t BinaryTree<K, V>::size() {
  return count;
}

template <typename K, typename V>
bool BinaryTree<K, V>::isEmpty() {
  return count == 0;
}

template <typename K, typename V>
Node<K, V> *BinaryTree<K, V>::get_root() {
  return root;
}

}  // namespace s21
