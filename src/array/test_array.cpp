#include <gtest/gtest.h>

#include <array>

#include "array.h"

#define PRINT(Expression) \
  std::cout << "{" #Expression "}: " << (Expression) << std::endl;

TEST(Array, EmptyArrayConstructor) {
  // s21::array<int, 0> zero; -невозможно при применении -pedantic(ISO)
  s21::array<int, 55555> middle;
  s21::array<int, 1900000> max;
  // EXPECT_EQ(zero.size(), 0);
  EXPECT_EQ(middle.size(), 55555);
  EXPECT_EQ(max.size(),
            1900000);  // max 2090000
}

TEST(Array, InitListConstructor) {
  s21::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::array<char, 5> const chr = {'a', 'b', 'c', 'd', 'e'};
  s21::array<double, 3> doubleArr = {1.0, 2.0, 3.0};
  s21::array<std::string, 2> strArr = {"Hello", "World"};

  EXPECT_EQ(arr.size(), 10);
  EXPECT_EQ(chr.size(), 5);
  EXPECT_EQ(doubleArr.size(), 3);
  EXPECT_EQ(strArr.size(), 2);

  for (size_t i = 0; i < arr.size(); i++) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }
  EXPECT_EQ(chr[1], 'b');
  // const
  const s21::array<int, 10>& constArr = arr;
  for (size_t i = 0; i < constArr.size(); i++) {
    EXPECT_EQ(constArr[i], static_cast<int>(i) + 1);
  }
  const s21::array<double, 3>& constDoubleArr = doubleArr;
  for (size_t i = 0; i < constDoubleArr.size(); i++) {
    EXPECT_EQ(constDoubleArr[i], static_cast<double>(i) + 1.0);
  }
  const s21::array<std::string, 2>& constStrArr = strArr;
  EXPECT_EQ(constStrArr[0], "Hello");
  EXPECT_EQ(constStrArr[1], "World");
  const s21::array<char, 5>& constCharArr = chr;
  EXPECT_EQ(constCharArr[2], 'c');
}

TEST(Array, CopyConstructor) {
  s21::array<int, 5> intArr = {1, 2, 3, 4, 5};
  s21::array<int, 5> intCopyArr(intArr);
  EXPECT_EQ(intCopyArr.size(), 5);
  for (size_t i = 0; i < intArr.size(); i++) {
    EXPECT_EQ(intCopyArr[i], intArr[i]);
  }

  s21::array<char, 5> charArr = {'a', 'b', 'c', 'd', 'e'};
  s21::array<char, 5> charCopyArr(charArr);
  EXPECT_EQ(charCopyArr.size(), 5);
  for (size_t i = 0; i < charArr.size(); i++) {
    EXPECT_EQ(charCopyArr[i], charArr[i]);
  }

  s21::array<double, 5> doubleArr = {1.0, 2.0, 3.0, 4.0, 5.0};
  s21::array<double, 5> doubleCopyArr(doubleArr);
  EXPECT_EQ(doubleCopyArr.size(), 5);
  for (size_t i = 0; i < doubleArr.size(); i++) {
    EXPECT_EQ(doubleCopyArr[i], doubleArr[i]);
  }

  s21::array<std::string, 3> strArr = {"Hello", "World", "C++"};
  s21::array<std::string, 3> strCopyArr(strArr);
  EXPECT_EQ(strCopyArr.size(), 3);
  for (size_t i = 0; i < strArr.size(); i++) {
    EXPECT_EQ(strCopyArr[i], strArr[i]);
  }
}

TEST(Array, MoveConstructor) {
  s21::array<int, 5> intArr = {1, 2, 3, 4, 5};
  s21::array<int, 5> intMoved(std::move(intArr));
  EXPECT_EQ(intMoved.size(), 5);
  for (size_t i = 0; i < intArr.size(); i++) {
    EXPECT_EQ(intMoved[i], static_cast<int>(i) + 1);
  }

  s21::array<char, 5> charArr = {'a', 'b', 'c', 'd', 'e'};
  s21::array<char, 5> charMoved(std::move(charArr));
  EXPECT_EQ(charMoved.size(), 5);
  EXPECT_EQ(charMoved[0], 'a');

  s21::array<double, 5> doubleArr = {1.0, 2.0, 3.0, 4.0, 5.0};
  s21::array<double, 5> doubleMoved(std::move(doubleArr));
  EXPECT_EQ(doubleMoved.size(), 5);
  for (size_t i = 0; i < doubleArr.size(); i++) {
    EXPECT_NEAR(doubleMoved[i], static_cast<double>(i) + 1.0, 0.000001);
  }

  s21::array<std::string, 3> strArr = {"Hello", "World", "C++"};
  s21::array<std::string, 3> strMoved(std::move(strArr));
  EXPECT_EQ(strMoved.size(), 3);
  EXPECT_EQ(strMoved[0], "Hello");

  // s21::array<int, 0> emptyArr;
  // s21::array<int, 0> emptyMoved(std::move(emptyArr));
  // EXPECT_EQ(emptyMoved.size(), 0);

  s21::array<char, 5> sameCharArr = {'a', 'a', 'a', 'a', 'a'};
  s21::array<char, 5> sameCharMoved(std::move(sameCharArr));
  EXPECT_EQ(sameCharMoved.size(), 5);
}

TEST(Array, IsMoveEmpty) {
  std::array<int, 3> classicArr = {1, 2, 3};
  std::array<int, 3> classicMove(std::move(classicArr));

  s21::array<int, 3> s21Arr = {1, 2, 3};
  s21::array<int, 3> s21Move(std::move(s21Arr));

  EXPECT_EQ(classicArr[0], s21Arr[0]);
  EXPECT_EQ(classicMove[0], s21Move[0]);
  EXPECT_EQ(classicArr.size(), s21Arr.size());
  EXPECT_EQ(classicMove.size(), s21Move.size());
}

TEST(Array, Begin) {
  int ptrArr[] = {1, 2, 3};
  s21::array<int, 3> arr = {1, 2, 3};
  s21::array<int, 3> octArr = {010, 020, 030};
  s21::array<char, 3> chrArr = {'a', 'b', 'c'};
  s21::array<unsigned, 3> hexArr = {0x1, 0x2, 0x3};
  s21::array<double, 3> doubleArr = {1.0, 2.0, 3.0};
  s21::array<std::string, 2> strArr = {"Hey,", " you!"};

  int(*ptr)[3] = &ptrArr;
  int* ptrElement = *ptr + 2;
  EXPECT_EQ(*ptrElement, 3);
  int* num = arr.begin();
  EXPECT_EQ(*num, 1);
  EXPECT_EQ(octArr[0], 8);
  char* chr = chrArr.begin();
  EXPECT_EQ(*chr, 'a');
  unsigned* hexNum = hexArr.begin();
  EXPECT_EQ(*hexNum, 0x1);
  double* dbl = doubleArr.begin();
  EXPECT_EQ(*dbl, 1.0);
  std::string* str = strArr.begin();
  EXPECT_EQ(*str, "Hey,");

  *num = 10;
  EXPECT_EQ(arr[0], 10);
  *chr = 'q';
  EXPECT_EQ(chrArr[0], 'q');
  *dbl = 101.01;
  EXPECT_EQ(doubleArr[0], 101.01);
  *str = "F";
  EXPECT_EQ(strArr[0], "F");
}

TEST(Array, End) {
  int ptrArr[] = {1, 2, 3};
  s21::array<int, 3> arr = {1, 2, 3};
  s21::array<int, 3> octArr = {010, 020, 030};
  s21::array<char, 3> chrArr = {'a', 'b', 'c'};
  s21::array<unsigned, 3> hexArr = {0x1, 0x2, 0x3};  // Исправлено от unsigned
  s21::array<double, 3> doubleArr = {1.0, 2.0, 3.0};
  s21::array<std::string, 2> strArr = {"Hey,", " you!"};

  int(*ptr)[3] = &ptrArr;
  int* ptrElement = *ptr + 2;
  EXPECT_EQ(*ptrElement, 3);

  int* num = arr.begin();
  EXPECT_EQ(*num, 1);

  int* endNum = arr.end();
  EXPECT_EQ(endNum, num + arr.size());

  EXPECT_EQ(octArr[0], 8);  // Октальный 010 равен десятичному 8
  int* endOct = octArr.end();
  EXPECT_EQ(endOct, octArr.begin() + octArr.size());

  char* chr = chrArr.begin();
  EXPECT_EQ(*chr, 'a');
  char* endChr = chrArr.end();
  EXPECT_EQ(endChr, chrArr.begin() + chrArr.size());

  unsigned* hexNum = hexArr.begin();
  EXPECT_EQ(*hexNum, 0x1);
  unsigned* endHex = hexArr.end();
  EXPECT_EQ(endHex, hexNum + hexArr.size());

  double* dbl = doubleArr.begin();
  EXPECT_EQ(*dbl, 1.0);
  double* endDbl = doubleArr.end();
  EXPECT_EQ(endDbl, dbl + doubleArr.size());

  std::string* str = strArr.begin();
  EXPECT_EQ(*str, "Hey,");
  std::string* endStr = strArr.end();
  EXPECT_EQ(endStr, strArr.begin() + strArr.size());
}

TEST(Array, Empty) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  s21::array<int, 5> const arr1 =
      {};  // в ориге важны ячейки а не содержимое -__-
  // s21::array<int, 0> zero;
  EXPECT_FALSE(arr.empty());
  EXPECT_FALSE(arr1.empty());
  // EXPECT_TRUE(zero.empty());
}

TEST(Array, Size) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.size(), 5);
  // s21::array<int, 0> arr;
  // EXPECT_TRUE(arr.empty());
}

TEST(Array, MaxSize) {
  s21::array<int, 5> arr;
  s21::array<int, 5> const constArr;

  EXPECT_EQ(arr.max_size(), 5);
  EXPECT_EQ(constArr.max_size(), 5);
}

TEST(Array, AssignmentOperator) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};
  s21::array<int, 5> arr3 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr4 = {6, 7, 8, 9, 10};

  arr1 = arr2;

  for (size_t i = 0; i < arr1.size(); i++) {
    EXPECT_EQ(arr1[i], arr2[i]);
  }

  arr3 = std::move(arr4);

  for (size_t i = 0; i < arr1.size(); i++) {
    EXPECT_EQ(arr3[i], arr4[i]);
  }
}

TEST(Array, At) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  const s21::array<int, 5> constArr = {1, 2, 3, 4, 5};
  arr.at(0) = 9;
  EXPECT_EQ(arr.at(0), 9);
  EXPECT_EQ(arr.at(2), 3);
  EXPECT_EQ(constArr.at(2), 3);
  EXPECT_EQ(constArr.at(0), 1);
  EXPECT_EQ(constArr.at(4), 5);
}

TEST(Array, Data) {
  s21::array<int, 3> arr = {1, 2, 3};
  std::array<int, 3> classicArr = {1, 2, 3};
  const s21::array<int, 3> constArr = {1, 2, 3};
  const std::array<int, 3> constClassicArr = {1, 2, 3};

  int* num = arr.data();
  int* classicNum = classicArr.data();
  const int* constNum = constArr.data();
  const int* constClassicNum = constClassicArr.data();
  // change value with iterator
  s21::array<int, 3> arrChange = {1, 2, 3};
  int* numChange = arrChange.data();
  *numChange = 10;
  EXPECT_EQ(arrChange[0], 10);

  EXPECT_EQ(*num, *classicNum);
  EXPECT_EQ(*constNum, *constClassicNum);
}

TEST(Array, Front) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  const s21::array<int, 5> constArr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.front(), 1);
  EXPECT_EQ(constArr.front(), 1);
}

TEST(Array, Back) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  const s21::array<int, 5> constArray = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.back(), 5);
  EXPECT_EQ(constArray.back(), 5);
}

TEST(Array, Swap) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};

  arr1.swap(arr2);

  for (size_t i = 0; i < arr1.size(); i++) {
    EXPECT_EQ(arr1[i], static_cast<int>(i) + 6);
  }

  for (size_t i = 0; i < arr2.size(); i++) {
    EXPECT_EQ(arr2[i], static_cast<int>(i) + 1);
  }
}

TEST(Array, Fill) {
  s21::array<int, 5> arr;
  arr.fill(10);

  for (size_t i = 0; i < arr.size(); i++) {
    EXPECT_EQ(arr[i], 10);
  }
}

TEST(Array, Throw) {
  // operator[]
  s21::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_THROW(arr[10], std::out_of_range);
  const s21::array<int, 10>& constArr = arr;
  EXPECT_THROW(constArr[10], std::out_of_range);
  // at()
  const s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  EXPECT_THROW(arr1.at(10), std::out_of_range);
  EXPECT_THROW(arr1.at(11), std::out_of_range);

  s21::array<int, 5> s21Arr = {1, 2, 3, 4, 5};
  EXPECT_THROW(s21Arr.at(10), std::out_of_range);
  EXPECT_THROW(s21Arr.at(11), std::out_of_range);
  // check original
  std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
  EXPECT_THROW(arr2.at(10), std::out_of_range);
}