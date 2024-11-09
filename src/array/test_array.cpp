#include <gtest/gtest.h>
#include "array.h"

TEST(Array, EmptyArrayConstructor) {
  // s21::array<int, 0> zero; -невозможно при применении -pedantic(ISO)
  s21::array<int, 55555> middle;
  s21::array<int, 1000000> max;
  // EXPECT_EQ(zero.GetSize(), 0);
  EXPECT_EQ(middle.GetSize(), 55555);
  EXPECT_EQ(max.GetSize(), 1000000); //обычный array (у меня)может съесть 2094099 ячеек памяти 
  //- в зависимости от свободного пространства на диске
}

