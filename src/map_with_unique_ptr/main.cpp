#include <iostream>
#include <map>
#include "s21_Map.h"

#include "binaryTree.h"
using std::map;
using std::string;
using namespace s21;

int main() {
  s21::map<int, char> BinaryTree;
  BinaryTree.insert(5, 's');
  (BinaryTree.insert(3, 'd'));
  (BinaryTree.insert(7, 'a'));
  (BinaryTree.insert(2, 'f'));
  (BinaryTree.insert(5, 'r'));
  (BinaryTree.insert(8, 'y'));
  (BinaryTree.insert(11, 'd'));
  (BinaryTree.insert(12, 'a'));
  (BinaryTree.insert(14, 'f'));
  (BinaryTree.insert(12, 'r'));
  (BinaryTree.insert(18, 'y'));
  (BinaryTree.insert(13, 'd'));
  (BinaryTree.insert(17, 'a'));
  (BinaryTree.insert(22, 'f'));
  (BinaryTree.insert(25, 'r'));
  (BinaryTree.insert(28, 'y'));
  (BinaryTree.insert(33, 'd'));
  (BinaryTree.insert(37, 'a'));
  (BinaryTree.insert(32, 'f'));
  (BinaryTree.insert(45, '%'));
  (BinaryTree.insert(48, 'y'));

  // std::cout << std::string(1, ' ') << 1 << std::endl;

//  Node<int, char> finded = *(BinaryTree.find(BinaryTree.get_root(), 5));
//  Node<int, char> findd =
//      *(BinaryTree.iterrative_find(BinaryTree.get_root(), 5));
//
//  BinaryTree.in_order_tree_walk(BinaryTree.get_root());
//  BinaryTree.remove(BinaryTree.get_root(), 48);
//    BinaryTree.in_order_tree_walk(BinaryTree.get_root());

//  map<int, string> map1;
//  map1.insert(std::pair<int, string>{1, "fdf"});
  int s = 0;
  int b = 0;
}
