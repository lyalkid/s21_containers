//
// Created by Siona Paella on 11/28/24.
//
#include <gtest/gtest.h>

#include "../s21btree/btree.h"
#include "../s21map/map.h"

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
  btree_node<int, int> *actual = (tree.find_helper(tree.get_root(), 2)).get();
  EXPECT_EQ(nullptr, actual);
}

TEST(test_class, successor) {
  btree<int, int> tree;
  //    5, 10, 15, 20, 30, 35

  btree<int, int>::iterator it;
  tree.insert(5, 1);
  tree.insert(2, 1);
  tree.insert(10, 1);
  tree.insert(15, 1);
  tree.insert(20, 1);
  tree.insert(30, 1);
  tree.insert(35, 1);
  shared_ptr<btree_node<int, int>> root = tree.get_root();
  EXPECT_EQ(tree.tree_successor(root)->get_data().first, 10);
  EXPECT_EQ(tree.tree_successor(tree.find_helper(tree.get_root(), 20))
                ->get_data()
                .first,
            30);
}

TEST(test_class, remove_leaf) {
  btree<int, int> tree;
  tree.insert(10, 10);
  tree.insert(5, 5);    // Левый потомок
  tree.insert(15, 15);  // Правый потомок
  auto root = tree.get_root();
  size_t old_size = tree.size();
  //
  tree.remove(5);
  EXPECT_NE(old_size, tree.size());
  EXPECT_EQ(tree.find_helper(tree.get_root(), 5), nullptr);
  EXPECT_NE(tree.find_helper(tree.get_root(), 10), nullptr);
  EXPECT_NE(tree.find_helper(tree.get_root(), 15), nullptr);
}
TEST(test_class, remove_node_with_one_child) {
  btree<int, int> tree;
  tree.insert(10, 10);
  tree.insert(5, 5);  // Левый потомок
  tree.insert(3, 3);  // Дочерний узел 5
  auto root = tree.get_root();
  size_t old_size = tree.size();

  tree.remove(5);  // Удаляем узел с одним дочерним элементом
  EXPECT_NE(old_size, tree.size());
  EXPECT_EQ(tree.find_helper(tree.get_root(), 5),
            nullptr);  // Узел должен отсутствовать
  EXPECT_NE(tree.find_helper(tree.get_root(), 3),
            nullptr);  // Потомок должен быть перенесён
  EXPECT_NE(tree.find_helper(tree.get_root(), 10),
            nullptr);  // Корень должен остаться
}
TEST(test_class, remove_node_with_two_children) {
  btree<int, int> tree;
  tree.insert(10, 10);
  tree.insert(5, 5);    // Левый потомок
  tree.insert(15, 15);  // Правый потомок
  tree.insert(3, 3);    // Левый потомок 5
  tree.insert(7, 7);    // Правый потомок 5
  auto root = tree.get_root();

  tree.remove(5);  // Удаляем узел с двумя дочерними элементами

  EXPECT_EQ(tree.find_helper(tree.get_root(), 5),
            nullptr);  // Узел должен отсутствовать
  EXPECT_NE(tree.find_helper(tree.get_root(), 3),
            nullptr);  // Левый потомок 5 должен остаться
  EXPECT_NE(tree.find_helper(tree.get_root(), 7),
            nullptr);  // Правый потомок 5 должен остаться
  EXPECT_NE(tree.find_helper(tree.get_root(), 10),
            nullptr);  // Корень должен остаться
  EXPECT_NE(tree.find_helper(tree.get_root(), 15),
            nullptr);  // Правый потомок корня должен остаться
}
TEST(test_class, remove_root) {
  btree<int, int> tree;
  tree.insert(10, 10);  // Корень
  tree.insert(5, 5);    // Левый потомок
  tree.insert(15, 15);  // Правый потомок
  auto root = tree.get_root();

  tree.remove(10);  // Удаляем корень

  ASSERT_EQ(tree.find_helper(tree.get_root(), 10),
            nullptr);  // Корень должен отсутствовать
  ASSERT_NE(tree.find_helper(tree.get_root(), 5),
            nullptr);  // Левый потомок должен остаться
  ASSERT_NE(tree.find_helper(tree.get_root(), 15),
            nullptr);  // Правый потомок должен остаться
}

TEST(test_class, remove_from_single_element_tree) {
  btree<int, int> tree;
  tree.insert(10, 10);  // Единственный элемент

  size_t old_size = tree.size();

  tree.remove(10);  // Удаляем единственный элемент

  EXPECT_EQ(tree.find_helper(tree.get_root(), 10),
            nullptr);  // Дерево должно быть пустым
  EXPECT_EQ(old_size, 1);
  EXPECT_EQ(tree.size(), 0);  // Размер дерева должен быть 0
}

TEST(test_class, clear_tree) {
  btree<int, int> tree;
  tree.insert(10, 100);
  tree.insert(20, 200);
  tree.insert(5, 50);

  tree.clear();
  ASSERT_EQ(tree.size(), 0);
  ASSERT_EQ(tree.empty(), true);
}

TEST(test_class, swap) {
  btree<int, int> tree;
  tree.insert(112, 100);
  tree.insert(20, 200);
  tree.insert(555, 50);

  btree<int, int> tree2;
  tree2.insert(10, 10);
  tree2.insert(5, 5);    // Левый потомок
  tree2.insert(15, 15);  // Правый потомок
  tree2.insert(3, 3);    // Левый потомок 5
  tree2.insert(7, 7);    // Правый потомок 5

  ASSERT_EQ(tree.size(), 3);
  ASSERT_EQ(tree2.size(), 5);
  ASSERT_NE(tree.find_helper(tree.get_root(), 555), nullptr);
  ASSERT_EQ(tree2.find_helper(tree2.get_root(), 555), nullptr);

  tree.swap(tree2);
  ASSERT_EQ(tree.size(), 5);
  ASSERT_EQ(tree2.size(), 3);
  ASSERT_EQ(tree.find_helper(tree.get_root(), 555), nullptr);
  ASSERT_NE(tree2.find_helper(tree2.get_root(), 555), nullptr);
}

TEST(test_class, iterator) {
  btree<int, int> tree;
  tree.insert(10, 100);
  tree.insert(20, 200);
  tree.insert(5, 1);
  tree.insert(2, 1);
  tree.insert(10, 1);
  tree.insert(15, 1);
  tree.insert(20, 1);
  tree.insert(30, 1);
  tree.insert(35, 1);

  auto it = tree.begin();
  auto end = tree.end();
  for (it = tree.begin(); it != tree.end(); it++) {
    std::cout << it->first << std::endl;
  }
  for (it = tree.end()--; it != tree.begin(); it--) {
    std::cout << it->first << std::endl;
  }

  //  ASSERT_EQ((it)->first, 5);
  //  it++;
  //    ASSERT_EQ((it)->first, 10);
  //    it++;
  //    ASSERT_EQ((it)->first, 20);
  //    it++;
  ////    ASSERT_EQ((it)->first, 0);
}

//  ASSERT_EQ(tree.size(), 0);
//  ASSERT_EQ(tree.empty(), true);
