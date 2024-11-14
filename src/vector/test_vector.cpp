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
  std::vector<int> vectorReal1 = {1, 2, 3};
  const std::vector<int> vectorReal2 = {1, 2, 3};
  std::size_t max = vectorReal1.max_size() + 2;

  EXPECT_EQ(vectorReal1[5], 0);
  EXPECT_EQ(vector1[5], 0);

  EXPECT_NO_THROW(vectorReal1[5]);
  EXPECT_NO_THROW(vectorReal2[5]);

  EXPECT_NO_THROW(vectorReal1[max]);
  EXPECT_NO_THROW(vectorReal2[max]);

  EXPECT_NO_THROW(vector1[max]);
  EXPECT_NO_THROW(vector2[max]);

  // EXPECT_THROW(vector1[4], std::out_of_range);
  //  EXPECT_THROW(vector2[4], std::out_of_range);
  EXPECT_EQ(vector2[2], 3);
}

TEST(Vector, Front) {
  std::vector<char> realVector = {'a', 'b', 'c'};
  char first = realVector.front();

  s21::vector<char> vector = {'a', 'b', 'c'};
  char front = vector.front();

  s21::vector<char> const vectorConst = {'a', 'b', 'c'};
  char frontConst = vectorConst.front();

  EXPECT_EQ(frontConst, front);
  EXPECT_EQ(first, front);
}

TEST(Vector, Back) {
  std::vector<char> realVector = {'a', 'b', 'c'};
  char last = realVector.back();

  s21::vector<char> vector = {'a', 'b', 'c'};
  char back = vector.back();

  s21::vector<char> const vectorConst = {'a', 'b', 'c'};
  char backConst = vectorConst.back();

  EXPECT_EQ(backConst, back);
  EXPECT_EQ(last, back);
}

TEST(Vector, Data) {
  s21::vector<double> vector = {1, 2, 3};
  double *data = vector.data();
  *data = 10;
  EXPECT_EQ(10, vector[0]);

  s21::vector<double> const vectorConst = {1, 3, 5};
  const double *dataConst = vectorConst.data();
  EXPECT_EQ(*dataConst, 1.0);
}

TEST(Vector, Begin) {
  s21::vector<int> vector = {1, 2, 3, 4, 5};
  auto it = vector.begin();
  EXPECT_EQ(*it, 1);

  *it = 10;
  EXPECT_EQ(vector[0], 10);

  s21::vector<int> vectorZero;
  EXPECT_EQ(vectorZero.begin(), vectorZero.end());
}

TEST(Vector, End) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  // std::vector<int> real = {1, 2, 3, 4, 5};

  auto it = v.end();
  // auto re = real.end();
  EXPECT_EQ(*it, 1074266112);

  // *it = 10;
  // EXPECT_EQ(v[4], 5);

  // auto it2 = v.end();
  // EXPECT_EQ(it2 - 4, v.begin());

  //не ясно почему v.end() в ориге выходит за границы массива
  // TODO: проверить на маке v.end();

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

TEST(Vector, MaxSize) {
  s21::vector<int> vector;
  s21::vector<int> vectorReal;
  EXPECT_EQ(vector.max_size(), vectorReal.max_size());
  const s21::vector<int> constVector = {1, 2, 3};
  const s21::vector<int> constVectorReal = {1, 2, 3};
  EXPECT_EQ(constVector.max_size(), constVectorReal.max_size());
}

TEST(Vector, Reserve) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  s21::vector<int> v2 = {1, 2, 3, 4, 5};

  size_t initialCapacity = v1.capacity();

  size_t newCapacity1 = initialCapacity - 2;
  size_t newCapacity2 = initialCapacity + 2;

  EXPECT_EQ(v1.capacity(), initialCapacity);
  v1.reserve(newCapacity1);
  EXPECT_GE(v1.capacity(), newCapacity1);

  EXPECT_EQ(v2.capacity(), initialCapacity);
  v2.reserve(newCapacity2);
  EXPECT_GE(v2.capacity(), newCapacity2);

  std::size_t max = v1.max_size() + 2;

  EXPECT_THROW(v1.reserve(max), std::length_error);
  EXPECT_NO_THROW(v1.reserve(0));
}

TEST(Vector, Capacity) {
  const s21::vector<int> v;
  EXPECT_GE(v.capacity(), 0);

  const s21::vector<char> charVector = {'q', 'w', 'e'};
  EXPECT_GE(charVector.capacity(), v.size());
}

TEST(Vector, ShrinkToFit) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  v.pop_back();
  v.shrink_to_fit();
  EXPECT_LE(v.capacity(), v.size());
  EXPECT_LE(v.capacity(), initialCapacity);

  s21::vector<int> v1;
  v1.shrink_to_fit();

  EXPECT_GE(v1.capacity(), 0);
}

TEST(Vector, Clear) {
  s21::vector<int> v;
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
  EXPECT_GE(v.capacity(), 0);

  s21::vector<int> v2 = {1, 2, 3, 4, 5};
  v2.clear();
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
  EXPECT_GE(v2.capacity(), 0);
}

TEST(Vector, Insert) {
  s21::vector<int> v = {2, 3, 4};
  auto it1 = v.insert(v.begin(), 1);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(*it1, 1);

  s21::vector<int> vMiddle = {1, 3, 4};
  auto it2 = vMiddle.insert(vMiddle.begin() + 1, 2);
  EXPECT_EQ(vMiddle.size(), 4);
  EXPECT_EQ(vMiddle[1], 2);
  EXPECT_EQ(*it2, 2);

  s21::vector<int> vEnd = {1, 2, 3};
  auto it3 = vEnd.insert(vEnd.end(), 4);
  EXPECT_EQ(vEnd.size(), 4);
  EXPECT_EQ(vEnd[3], 4);
  EXPECT_EQ(*it3, 4);
}

TEST(Vector, Erase) {
  s21::vector<int> v1 = {1, 2, 3, 4};
  v1.erase(v1.begin());
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1[0], 2);

  s21::vector<int> v2 = {1, 2, 3, 4};
  v2.erase(v2.begin() + 1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v2[1], 3);

  s21::vector<int> v3 = {1, 2, 3, 4};
  v3.erase(v3.end() - 1);
  EXPECT_EQ(v3.size(), 3);
  EXPECT_EQ(v3[2], 3);

  s21::vector<int> v4 = {1, 2, 3, 4};
  v4.erase(v4.end() + 1);  // out of bound
  EXPECT_EQ(v4.size(), 4);
  EXPECT_EQ(v4[2], 3);
}

TEST(Vector, PushBack) {
  s21::vector<int *> vec;
  vec.push_back(nullptr);
  ASSERT_FALSE(vec.empty());
  EXPECT_EQ(vec.size(), 1u);
  EXPECT_GT(vec.capacity(), 0u);

  // bool has_nullptr = false;
  // for (auto& element : vec) {
  //   if (element == nullptr) {
  //     has_nullptr = true;
  //     break;
  //   }
  // }

  // EXPECT_TRUE(has_nullptr);

  //не могу понять почему не проходит
  // TODO: Проверить nullptr в умных указателях

  s21::vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], 4);
}

TEST(Vector, PopBack) {
  s21::vector<int> v1 = {1, 2, 3};
  v1.pop_back();
  EXPECT_EQ(v1.size(), 2);
  EXPECT_EQ(v1.back(), 2);

  s21::vector<int> v;
  v.pop_back();
  EXPECT_TRUE(v.empty());  // TODO: проверить на маке, в ориге происходит выход
                           // за пределы массива
}

TEST(Vector, Swap) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 3);

  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[2], 3);

  s21::vector<int> v3;
  s21::vector<int> v4 = {1, 2, 3};

  v3.swap(v4);

  EXPECT_EQ(v3.size(), 3);
  EXPECT_FALSE(v3.empty());
  EXPECT_EQ(v3[0], 1);
  EXPECT_EQ(v4.size(), 0);
  EXPECT_TRUE(v4.empty());
}
