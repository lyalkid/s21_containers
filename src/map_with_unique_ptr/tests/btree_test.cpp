//
// Created by Siona Paella on 11/28/24.
//
#include <gtest/gtest.h>

#include "../binaryTree.h"
#include "../s21_map.h"

using namespace s21;

TEST(test_class, basic_constructor) {
  binary_tree<int, int> tree(3, 3);
  btree_node<int, int> expect(3, 3);
  btree_node<int, int> *actual = (tree.get_root()).get();
  EXPECT_EQ(expect, *actual);
}

TEST(test_class, find_nullptr) {
  binary_tree<int, int> tree(3, 3);
  btree_node<int, int> expect(3, 3);
  btree_node<int, int> *actual = (tree.find(tree.get_root(), 2)).get();
  EXPECT_EQ(nullptr, actual);
}

TEST(test_class, successor) {
  binary_tree<int, int> tree;
  //    5, 10, 15, 20, 30, 35
  bool flag = true;
  binary_tree<int, int>::iterator it;
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

TEST(test_class, begin_end) {
  s21::map<int, int> tree;
  //    5, 10, 15, 20, 30, 35
  // bool flag = true;
  //    binary_tree<int, int>::iterator it;
  tree.insert(5, 1);
  tree.insert(2, 1);
  tree.insert(10, 1);
  tree.insert(15, 1);
  tree.insert(20, 1);
  tree.insert(30, 1);
  tree.insert(35, 1);

  for(s21::map<int, int> ::iterator it = tree.begin(); it != tree.end(); ++it){
      std::cout << it->first << " " << it->second << std::endl;
  }

//    for(s21::map<int, int> ::iterator it = (tree.end())-- ; it != tree.begin(); --it){
//        std::cout << it->first << " " << it->second << std::endl;
//    }
  auto begin = tree.begin();
 auto end = tree.end();
  //    tree.in_order_tree_walk(tree.get_root());
  ////    shared_ptr<btree_node<int, int>> root = tree.get_root();
  //    EXPECT_EQ(begin->first., );
  //    EXPECT_EQ(tree.find(root, 20)->get_data().first, 20);
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
