#include <gtest/gtest.h>

#include "array.h"

TEST(Array, EmptyArrayConstructor) {
  // s21::array<int, 0> zero; -невозможно при применении -pedantic(ISO)
  s21::array<int, 55555> middle;
  s21::array<int, 1000000> max;
  // EXPECT_EQ(zero.size(), 0);
  EXPECT_EQ(middle.size(), 55555);
  EXPECT_EQ(max.size(),
            1000000);  //обычный array (у меня)может съесть 2094099 ячеек памяти
  //- в зависимости от свободного пространства на диске
}

TEST(Array, InitListConstructor) {
  s21::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(arr.size(), 10);
  for (size_t i = 0; i < arr.size(); i++) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }
  // TODO:static_cast - what is it?
  // TODO: сделать проверки с разными типами
}
