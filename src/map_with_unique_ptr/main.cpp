#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

#include "include/btree.h"
#include "include/s21_map.h"

using std::cout;
using std::endl;
using std::map;
using std::string;
// using namespace s21;

// int main() {
//   //  s21::binary_tree<int, string> binary_tree;
//   //
//   // auto iter =   binary_tree.insert(2, "fd");
//   //
//   //    s21::map<int, string> map;
//   // auto m_it = map.insert(2, "fd");
//   //
//   //
//   ////  iter = (binary_tree.insert(2, "fd"));
//   ////  iter = (binary_tree.insert(7, "a"));
//   ////  iter = (binary_tree.insert(2, "f"));
//   ////  iter = (binary_tree.insert(5, "r"));
//   ////  iter = (binary_tree.insert(8, "y"));
//   ////  iter = (binary_tree.insert(11, "d"));
//   ////  iter = (binary_tree.insert(12, "a"));
//   ////  iter = (binary_tree.insert(14, "f"));
//   ////  iter = (binary_tree.insert(12, "r"));
//   ////  iter = (binary_tree.insert(18, "y"));
//   ////  iter = (binary_tree.insert(13, "d"));
//   ////  iter = (binary_tree.insert(17, "a"));
//   ////  iter = (binary_tree.insert(22, "f"));
//   ////  iter = (binary_tree.insert(25, "r"));
//   ////  iter = (binary_tree.insert(28, "y"));
//   ////  iter = (binary_tree.insert(33, "d"));
//   ////  iter = (binary_tree.insert(37, "a"));
//   ////  iter = (binary_tree.insert(32, "f"));
//   ////  iter = (binary_tree.insert(45, "%"));
//   ////  iter = (binary_tree.insert(48, "y"));
//   //
//   //  // std::cout << std::string(1, " ") << 1 << std::endl;
//   //
//   //  //  Node<int, char> finded = *iter = (binary_tree.finditer =
//   //  (binary_tree.get_root(), 5));
//   //  //  Node<int, char> findd =
//   //  //      *iter = (binary_tree.iterrative_finditer =
//   (binary_tree.get_root(),
//   //  5));
//   //  //
//   //  //  binary_tree.in_order_tree_walkiter = (binary_tree.get_root());
//   //  //  binary_tree.removeiter = (binary_tree.get_root(), 48);
//   //  //    binary_tree.in_order_tree_walkiter = (binary_tree.get_root());
//   //
//   std::map<int, string> map1;
//   auto item = map1.insert({1, "fdf"});
//   item = map1.insert(std::pair<int, string>{2, "fd"});
//   //    auto item = map1.begin();
//   //    item++;
//   ////  it = map1.insert(std::pair<int, string>{2, "fd"});
//   ////  it = map1.insert(std::pair<int, string>{2, "f"});
//   ////
//   ////  it = map1.insert(std::pair<int, string>{4, "fd"});
//   ////  it = map1.insert(std::pair<int, string>{12, "fd"});
//   ////  it = map1.insert(std::pair<int, string>{22, "fd"});
//   ////  it = map1.insert(std::pair<int, string>{10, "fd"});
//   ////  it = map1.insert(std::pair<int, string>{3, "fd"});
//   ////    it = map1.insert(std::pair<int, string>{2, "fd"});
//
//   binary_tree<int, int> tree;
//   //    5, 10, 15, 20, 30, 35
//   bool flag = true;
//   binary_tree<int, int>::iterator it;
//   tree.insert(5, 1, flag);
//   tree.insert(2, 1, flag);
//   tree.insert(10, 1, flag);
//   tree.insert(15, 1, flag);
//   tree.insert(20, 1, flag);
//   tree.insert(30, 1, flag);
//   tree.insert(35, 1, flag);
//   (tree.insert(3, 'd', flag));
//   (tree.insert(7, 'a', flag));
//   (tree.insert(2, 'f', flag));
//   (tree.insert(5, 'r', flag));
//   (tree.insert(8, 'y', flag));
//   (tree.insert(11, 'd', flag));
//   (tree.insert(12, 'a', flag));
//   (tree.insert(14, 'f', flag));
//   (tree.insert(12, 'r', flag));
//   (tree.insert(18, 'y', flag));
//   (tree.insert(13, 'd', flag));
//   (tree.insert(17, 'a', flag));
//   (tree.insert(22, 'f', flag));
//   (tree.insert(25, 'r', flag));
//   (tree.insert(28, 'y', flag));
//   (tree.insert(33, 'd', flag));
//   (tree.insert(37, 'a', flag));
//   (tree.insert(32, 'f', flag));
//   (tree.insert(45, '%', flag));
//   (tree.insert(48, 'y', flag));
//
//   tree.in_order_tree_walk(tree.get_root());
//   shared_ptr<btree_node<int, int>> root = tree.get_root();
//
//   s21::map<int, char> map(1, 1);
//   auto irt = map.insert({1, 1});
//   map1.clear();
//   map.clear();
//   irt = map.insert(5, 1);
//   irt = map.insert(5, 3);
// }

int main() {
  s21::map<int, int> tree;
 auto res =  tree.insert(10, 100);
  res = tree.insert(20, 200);
  res = tree.insert(5, 1);
  res = tree.insert(2, 1);
  res = tree.insert(10, 1);
  res = tree.insert(15, 1);
  res = tree.insert(20, 1);
  res = tree.insert(30, 1);
  res = tree.insert(35, 1);
    auto op = tree[10] ;

    tree[10] = 11111111 ;
   op = tree[10] ;

    auto c = tree.at(30);
     c = tree.at(35);

  auto i = tree.begin();
  auto ed = tree.end();
  for (i = tree.begin(); i != tree.end(); i++) {
    std::cout << i->first << std::endl;
  }

  std::cout << "---------" << std::endl;

  for (i = tree.end()--; i != tree.begin(); i--) {
    std::cout << i->first << std::endl;
  }
  std::cout << i->first << std::endl;



    std::cout << "---------" << std::endl;
    std::cout << "---------" << std::endl;

  std::map<int, int> map;

  map.insert({10, 100});
  map.insert({20, 200});
  map.insert({5, 1});
  map.insert({2, 1});
  map.insert({10, 1});
  map.insert({15, 1});
  map.insert({20, 1});
  map.insert({30, 1});
  map.insert({35, 1});

//  map.at(15000);

  auto it = map.begin();
  auto end = map.end();

  for (it = map.begin(); it != map.end(); it++) {
    std::cout << it->first << std::endl;
  }

  std::cout << "---------" << std::endl;

  for (it = --map.end(); it != map.begin(); it--) {
    std::cout << it->first << std::endl;
  }


  auto r = map[1];
  map.at(1);
  // Для вывода последнего элемента
  std::cout << it->first << std::endl;
}
