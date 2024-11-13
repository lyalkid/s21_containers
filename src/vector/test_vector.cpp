#include <gtest/gtest.h>

#include <vector>

#include "vector.h"

TEST(Vector, EmptyConstuctor) {
  s21::vector<int> vector;
  EXPECT_TRUE(vector.empty());
  EXPECT_EQ(vector.size(), 0);

  s21::vector<char> vectorChar;
  EXPECT_TRUE(vectorChar.empty());
  EXPECT_EQ(vectorChar.size(), 0);
}

TEST(Vector, MemberConstructor) {
  s21::vector<int> vector(3);
  EXPECT_FALSE(vector.empty());
  EXPECT_EQ(vector.size(), 3);
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(vector[i], 0);
  }
  s21::vector<char> vectorChar(3);
  EXPECT_FALSE(vectorChar.empty());
  EXPECT_EQ(vectorChar.size(), 3);
}

TEST(Vector, InitList) {
  s21::vector<int> zero = {};
  EXPECT_TRUE(zero.empty());
  EXPECT_EQ(zero.size(), 0);

  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[4], 5);
}

TEST(Vector, CopyConstructor) {
  s21::vector<int> v1;
  s21::vector<int> v2(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);

  s21::vector<int> v3 = {1, 2, 3};
  s21::vector<int> v4(v3);
  EXPECT_EQ(v4.size(), v3.size());
  for (size_t i = 0; i < v3.size(); ++i) {
    EXPECT_EQ(v4[i], v3[i]);
  }
}

TEST(Vector, MoveConstructor) {
  s21::vector<int> v1;
  s21::vector<int> v2(std::move(v1));
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
  s21::vector<int> v3 = {1, 2, 3};
  s21::vector<int> v4(std::move(v3));
  EXPECT_EQ(v4.size(), 3);
  EXPECT_FALSE(v3.empty());
}

TEST(Vector, Begin) {
  s21::vector<int> vector = {1, 2, 3, 4, 5};
  int *it = vector.begin();
  EXPECT_EQ(*it, 1);

  *it = 10;
  EXPECT_EQ(vector[0], 10);

  s21::vector<int> vectorZero;
  EXPECT_EQ(vectorZero.begin(), vectorZero.end());
}

TEST(Vector, End) {
  s21::vector<int> v = {1, 2, 3, 4, 5};

  int *it = v.end();
  EXPECT_EQ(*it, 5);

  *it = 10;
  EXPECT_EQ(v[4], 10);

  auto it2 = v.end();
  EXPECT_EQ(it2 - 4, v.begin());

  s21::vector<char> zero;
  EXPECT_EQ(zero.end(), zero.begin());

  auto it3 = v.begin();
  EXPECT_NE(it3, v.end());
}

TEST(Vector, Empty) {
  const s21::vector<int> v;
  EXPECT_TRUE(v.empty());

  const s21::vector<int> initVec = {1, 2, 3};
  EXPECT_FALSE(initVec.empty());

  s21::vector<int> nonConst;
  EXPECT_TRUE(nonConst.empty());
}

TEST(Vector, Size) {
  s21::vector<int> v;
  EXPECT_EQ(v.size(), 0);
  const s21::vector<int> constVector = {1, 2, 3};
  EXPECT_EQ(constVector.size(), 3);
}
