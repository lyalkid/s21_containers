//
// Created by Siona Paella on 11/28/24.
//
#include "../include/btree.h"

#include <gtest/gtest.h>

#include "../include/s21_map.h"

using namespace s21;

TEST(test_class, basic_constructor) {
  btree<int, int> tree(3, 3);
  btree_node<int, int> expect(3, 3);
  btree_node<int, int> *actual = (tree.get_root()).get();
  EXPECT_EQ(expect, *actual);
}

TEST(test_class, find_nullptr) {
  btree<int, int> tree(3, 3);
  btree_node<int, int> expect(3, 3);
  btree_node<int, int> *actual = (tree.find(tree.get_root(), 2)).get();
  EXPECT_EQ(nullptr, actual);
}

TEST(test_class, successor) {
  btree<int, int> tree;
  //    5, 10, 15, 20, 30, 35
  bool flag = true;
  btree<int, int>::iterator it;
  tree.insert(5, 1, flag);
  tree.insert(2, 1, flag);
  tree.insert(10, 1, flag);
  tree.insert(15, 1, flag);
  tree.insert(20, 1, flag);
  tree.insert(30, 1, flag);
  tree.insert(35, 1, flag);
  tree.in_order_tree_walk(tree.get_root());
  shared_ptr<btree_node<int, int>> root = tree.get_root();
  EXPECT_EQ(tree.find(root, 15)->get_data().first, 15);
  EXPECT_EQ(tree.find(root, 20)->get_data().first, 20);
}
