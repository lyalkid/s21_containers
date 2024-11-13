#include <gtest/gtest.h>

#include <vector>

#include "vector.h"

#define PRINT(Expression) \
  std::cout << "{" #Expression "}: " << (Expression) << std::endl;

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

TEST(Vector, MoveAssignment) {
  s21::vector<int> vector1;
  s21::vector<int> vector2;
  vector2 = std::move(vector1);
  EXPECT_TRUE(vector2.empty());
  EXPECT_EQ(vector2.size(), 0);

  std::vector<int> realVector1;
  std::vector<int> realVector2;
  realVector2 = std::move(realVector1);
  EXPECT_TRUE(realVector2.empty());
  EXPECT_EQ(realVector2.size(), 0);

  s21::vector<int> nonEmpty = {1, 2, 3};
  s21::vector<int> checkEmpty;
  checkEmpty = std::move(nonEmpty);
  EXPECT_EQ(checkEmpty.size(), 3);
  EXPECT_TRUE(nonEmpty.empty());

  std::vector<int> realNonEmpty = {1, 2, 3};
  std::vector<int> realCheckEmpty;
  realCheckEmpty = std::move(realNonEmpty);
  EXPECT_EQ(realCheckEmpty.size(), 3);
  EXPECT_TRUE(realNonEmpty.empty());

  s21::vector<int> vectorEmpty;
  s21::vector<int> vectorNonEmpty = {4, 5, 6};
  vectorNonEmpty = std::move(vectorEmpty);
  EXPECT_TRUE(vectorNonEmpty.empty());
  EXPECT_EQ(vectorNonEmpty.size(), 0);

  std::vector<int> realVectorEmpty;
  std::vector<int> realVectorNonEmpty = {4, 5, 6};
  realVectorNonEmpty = std::move(realVectorEmpty);
  EXPECT_TRUE(realVectorNonEmpty.empty());
  EXPECT_EQ(realVectorNonEmpty.size(), 0);

  s21::vector<int> vectorNonEmpty1 = {1, 2, 3};
  s21::vector<int> vectorNonEmpty2 = {4, 5, 6};
  vectorNonEmpty2 = std::move(vectorNonEmpty1);
  EXPECT_EQ(vectorNonEmpty2.size(), 3);
  EXPECT_TRUE(vectorNonEmpty1.empty());

  std::vector<int> realVectorNonEmpty1 = {1, 2, 3};
  std::vector<int> realVectorNonEmpty2 = {4, 5, 6};
  realVectorNonEmpty2 = std::move(realVectorNonEmpty1);
  EXPECT_EQ(realVectorNonEmpty2.size(), 3);
  EXPECT_TRUE(realVectorNonEmpty1.empty());
}

TEST(Vector, CopyAssignment) {
  s21::vector<int> vector1;
  s21::vector<int> vector2;
  vector2 = vector1;
  EXPECT_EQ(vector1.size(), 0);
  EXPECT_EQ(vector2.size(), 0);

  std::vector<int> realVector1;
  std::vector<int> realVector2;
  realVector2 = realVector1;
  EXPECT_EQ(realVector2.size(), 0);
  EXPECT_EQ(realVector2.size(), 0);

  s21::vector<int> nonEmpty = {1, 2, 3};
  s21::vector<int> checkEmpty;
  checkEmpty = nonEmpty;
  EXPECT_EQ(checkEmpty.size(), 3);
  EXPECT_EQ(nonEmpty.size(), 3);

  std::vector<int> realNonEmpty = {1, 2, 3};
  std::vector<int> realCheckEmpty;
  realCheckEmpty = realNonEmpty;
  EXPECT_EQ(realCheckEmpty.size(), 3);
  EXPECT_EQ(realNonEmpty.size(), 3);

  s21::vector<int> vectorEmpty;
  s21::vector<int> vectorNonEmpty = {4, 5, 6};
  vectorNonEmpty = vectorEmpty;
  EXPECT_EQ(vectorEmpty.size(), 0);
  EXPECT_EQ(vectorNonEmpty.size(), 0);

  std::vector<int> realVectorEmpty;
  std::vector<int> realVectorNonEmpty = {4, 5, 6};
  realVectorNonEmpty = realVectorEmpty;
  EXPECT_EQ(realVectorNonEmpty.size(), 0);
  EXPECT_EQ(realVectorEmpty.size(), 0);

  s21::vector<int> vectorNonEmpty1 = {1, 2, 3};
  s21::vector<int> vectorNonEmpty2 = {4, 5, 6};
  vectorNonEmpty2 = vectorNonEmpty1;
  EXPECT_EQ(vectorNonEmpty2.size(), 3);
  EXPECT_EQ(vectorNonEmpty1.size(), 3);

  std::vector<int> realVectorNonEmpty1 = {1, 2, 3};
  std::vector<int> realVectorNonEmpty2 = {4, 5, 6};
  realVectorNonEmpty2 = realVectorNonEmpty1;
  EXPECT_EQ(realVectorNonEmpty2.size(), 3);
  EXPECT_EQ(realVectorNonEmpty1.size(), 3);
}

TEST(Vector, At) {
  s21::vector<int> vector1 = {1, 2, 3};
  const s21::vector<int> vector2 = {44, 55, 66};

  std::vector<int> realVector1 = {1, 2, 3};
  const std::vector<int> realVector2 = {44, 55, 66};
  EXPECT_EQ(vector1.at(0), realVector1.at(0));
  EXPECT_EQ(vector2.at(0), realVector2.at(0));

  EXPECT_EQ(vector1.at(0), 1);
  EXPECT_EQ(vector1.at(1), 2);
  EXPECT_EQ(vector1.at(2), 3);

  EXPECT_EQ(vector2.at(0), 44);
  EXPECT_EQ(vector2.at(1), 55);
  EXPECT_EQ(vector2.at(2), 66);

  EXPECT_THROW(vector1.at(10), std::out_of_range);
  EXPECT_THROW(realVector1.at(10), std::out_of_range);
  EXPECT_THROW(vector2.at(10), std::out_of_range);
  EXPECT_THROW(realVector2.at(10), std::out_of_range);
}

TEST(Vector, IndexOperator) {
  s21::vector<int> vector1 = {1, 2, 3};
  const s21::vector<int> vector2 = {1, 2, 3};

  EXPECT_THROW(vector1[4], std::out_of_range);
  EXPECT_THROW(vector2[4], std::out_of_range);
  EXPECT_EQ(vector2[2], 3);
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
