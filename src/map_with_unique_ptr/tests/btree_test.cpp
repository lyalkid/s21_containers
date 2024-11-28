//
// Created by Siona Paella on 11/28/24.
//
#include <gtest/gtest.h>

#include "../binaryTree.h"
#include "../s21_map.h"

using namespace s21;

TEST(test_class, basic_constructor) {
  BinaryTree<int, int> tree(3, 3);
  TreeNode<int, int> expect(3, 3);
  TreeNode<int, int> *actual = (tree.get_root()).get();
  EXPECT_EQ(expect, *actual);
}

TEST(test_class, find_nullptr) {
  BinaryTree<int, int> tree(3, 3);
  TreeNode<int, int> expect(3, 3);
  TreeNode<int, int> *actual = (tree.find(tree.get_root(), 2)).get();
  EXPECT_EQ(nullptr, actual);
}

TEST(test_class, successor) {
  BinaryTree<int, int> tree;
  //    5, 10, 15, 20, 30, 35
  bool flag = true;
  BinaryTree<int, int>::iterator it;
  tree.insert(5, 1, flag, it);
  tree.insert(2, 1, flag, it);
  tree.insert(10, 1, flag, it);
  tree.insert(15, 1, flag, it);
  tree.insert(20, 1, flag, it);
  tree.insert(30, 1, flag, it);
  tree.insert(35, 1, flag, it);
  tree.in_order_tree_walk(tree.get_root());
  shared_ptr<TreeNode<int, int>> root = tree.get_root();
  EXPECT_EQ(tree.find(root, 15)->get_data().first, 15);
  EXPECT_EQ(tree.find(root, 20)->get_data().first, 20);
}

TEST(test_class, insert_map) {
  map<int, char> map;
  auto it = map.insert({1, 1});
  it = map.insert(5, 1);
  it = map.insert(5, 3);
  EXPECT_TRUE(it.second == false);
}

TEST(test_class, contains) {
  map<int, char> map;
  auto it = map.insert({1, 1});
  it = map.insert(5, 1);
  EXPECT_TRUE(map.contains(5));
  EXPECT_FALSE(map.contains(2));
  map.clear();
  EXPECT_FALSE(map.contains(5));
}
