#include <iostream>
#include <map>

#include "binaryTree.h"
// #include "s21_map.h"

#include "test_map/example_map.h"

using std::cout;
using std::endl;
using std::map;
using std::string;
using namespace s21;

int main() {
  //  s21::BinaryTree<int, string> BinaryTree;
  //
  // auto iter =   BinaryTree.insert(2, "fd");
  //
  //    s21::map<int, string> map;
  // auto m_it = map.insert(2, "fd");
  //
  //
  ////  iter = (BinaryTree.insert(2, "fd"));
  ////  iter = (BinaryTree.insert(7, "a"));
  ////  iter = (BinaryTree.insert(2, "f"));
  ////  iter = (BinaryTree.insert(5, "r"));
  ////  iter = (BinaryTree.insert(8, "y"));
  ////  iter = (BinaryTree.insert(11, "d"));
  ////  iter = (BinaryTree.insert(12, "a"));
  ////  iter = (BinaryTree.insert(14, "f"));
  ////  iter = (BinaryTree.insert(12, "r"));
  ////  iter = (BinaryTree.insert(18, "y"));
  ////  iter = (BinaryTree.insert(13, "d"));
  ////  iter = (BinaryTree.insert(17, "a"));
  ////  iter = (BinaryTree.insert(22, "f"));
  ////  iter = (BinaryTree.insert(25, "r"));
  ////  iter = (BinaryTree.insert(28, "y"));
  ////  iter = (BinaryTree.insert(33, "d"));
  ////  iter = (BinaryTree.insert(37, "a"));
  ////  iter = (BinaryTree.insert(32, "f"));
  ////  iter = (BinaryTree.insert(45, "%"));
  ////  iter = (BinaryTree.insert(48, "y"));
  //
  //  // std::cout << std::string(1, " ") << 1 << std::endl;
  //
  //  //  Node<int, char> finded = *iter = (BinaryTree.finditer =
  //  (BinaryTree.get_root(), 5));
  //  //  Node<int, char> findd =
  //  //      *iter = (BinaryTree.iterrative_finditer = (BinaryTree.get_root(),
  //  5));
  //  //
  //  //  BinaryTree.in_order_tree_walkiter = (BinaryTree.get_root());
  //  //  BinaryTree.removeiter = (BinaryTree.get_root(), 48);
  //  //    BinaryTree.in_order_tree_walkiter = (BinaryTree.get_root());
  //
  //  std::map<int, string> map1;
  //    auto it = map1.insert({1, "fdf"});
  //    it = map1.insert(std::pair<int, string>{2, "fd"});
  //    auto item = map1.begin();
  //    item++;
  ////  it = map1.insert(std::pair<int, string>{2, "fd"});
  ////  it = map1.insert(std::pair<int, string>{2, "f"});
  ////
  ////  it = map1.insert(std::pair<int, string>{4, "fd"});
  ////  it = map1.insert(std::pair<int, string>{12, "fd"});
  ////  it = map1.insert(std::pair<int, string>{22, "fd"});
  ////  it = map1.insert(std::pair<int, string>{10, "fd"});
  ////  it = map1.insert(std::pair<int, string>{3, "fd"});
  ////    it = map1.insert(std::pair<int, string>{2, "fd"});

  int x = 0;
  int& y = x;
  int z = 7;
  int* px = &y;

  y = ++z;
  y = z++;
  int c = x;
  int& r = y;
}
