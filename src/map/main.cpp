#include <iostream>
#include <map>

#include "binaryTree.h"
using std::map;
using std::string;
using namespace s21;

int main() {


  s21::BinaryTree<int, char> BinaryTree;
   Node<int, char> node = *(BinaryTree.insert(5, 's'));
  // (BinaryTree.insert(5));
  // (BinaryTree.insert(6));
  // (BinaryTree.insert(3));
  // (BinaryTree.insert(1));
  // (BinaryTree.insert(2));

  map<int, string> map1;
  map1.insert(std::pair<int, string>{1, "fdf"});
  int s = 0;
  int b = 0;
}
