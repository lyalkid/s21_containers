#include <gtest/gtest.h>

#include <stack>

#include "../s21stack/stack.h"

TEST(Stack, EmptyConstructor) {
  s21::Stack<int> stack_;
  EXPECT_TRUE(stack_.Empty());
  EXPECT_EQ(stack_.Size(), 0);
}

TEST(Stack, InitList) {
  s21::Stack<int> stack_ = {1, 2, 3};
  EXPECT_FALSE(stack_.Empty());
  EXPECT_EQ(stack_.Size(), 3);

  EXPECT_EQ(stack_.Top(), 3);
  stack_.Pop();
  EXPECT_EQ(stack_.Top(), 2);
  stack_.Pop();
  EXPECT_EQ(stack_.Top(), 1);
}

TEST(Stack, CopyConstructor) {
  s21::Stack<int> stack_1_ = {1, 2, 3};
  s21::Stack<int> stack_2_(stack_1_);

  EXPECT_FALSE(stack_2_.Empty());
  EXPECT_EQ(stack_2_.Size(), 3);

  EXPECT_EQ(stack_2_.Top(), 3);
  stack_2_.Pop();
  EXPECT_EQ(stack_2_.Top(), 2);
  stack_2_.Pop();
  EXPECT_EQ(stack_2_.Top(), 1);
}

TEST(Stack, MoveConstructor) {
  s21::Stack<int> stack_ = {1, 4, 18};
  s21::Stack<int> stack_1_(std::move(stack_));

  EXPECT_EQ(stack_1_.Size(), 3);
  EXPECT_TRUE(stack_.Empty());

  EXPECT_EQ(stack_1_.Top(), 18);
  stack_1_.Pop();
  EXPECT_EQ(stack_1_.Top(), 4);
  stack_1_.Pop();
  EXPECT_EQ(stack_1_.Top(), 1);
}

TEST(Stack, CopyAssigment) {
  s21::Stack<int> stack_1_ = {1, 2, 3};
  s21::Stack<int> stack_2_;

  stack_2_ = stack_1_;

  EXPECT_EQ(stack_1_.Size(), stack_2_.Size());

  while (!stack_1_.Empty()) {
    EXPECT_EQ(stack_1_.Top(), stack_2_.Top());
    stack_1_.Pop();
    stack_2_.Pop();
  }
}

TEST(Stack, MoveAssigment) {
  s21::Stack<int> stack_1_ = {1, 2, 3};
  s21::Stack<int> stack_2_;

  stack_2_ = std::move(stack_1_);

  EXPECT_EQ(stack_2_.Size(), 3);
  EXPECT_TRUE(stack_1_.Empty());

  EXPECT_EQ(stack_2_.Top(), 3);
  stack_2_.Pop();
  EXPECT_EQ(stack_2_.Top(), 2);
  stack_2_.Pop();
  EXPECT_EQ(stack_2_.Top(), 1);
}

TEST(Stack, SelfAssigment) {
  s21::Stack<int> stack_1_ = {1, 2, 3};

  stack_1_ = stack_1_;

  EXPECT_EQ(stack_1_.Top(), 3);
  stack_1_.Pop();
  EXPECT_EQ(stack_1_.Top(), 2);
  stack_1_.Pop();
  EXPECT_EQ(stack_1_.Top(), 1);
}

TEST(StackElementAccess, Top) {
  s21::Stack<int> stack_;
  stack_.Push(4);
  stack_.Push(3);
  stack_.Push(7);

  std::stack<int> stack_org_;
  stack_org_.push(4);
  stack_org_.push(3);
  stack_org_.push(7);

  EXPECT_EQ(stack_.Top(), stack_org_.top());
  stack_.Pop();
  stack_org_.pop();
  EXPECT_EQ(stack_.Top(), stack_org_.top());
  stack_.Pop();
  stack_org_.pop();
  EXPECT_EQ(stack_.Top(), stack_org_.top());
}

TEST(StackCapacity, Empty) {
  s21::Stack<int> stack_;
  std::stack<int> org_stak_;
  EXPECT_EQ(stack_.Empty(), org_stak_.empty());

  s21::Stack<int> stack_1_;
  stack_1_.Push(7);
  std::stack<int> org_stack_1_;
  org_stack_1_.push(4);

  EXPECT_EQ(stack_1_.Empty(), org_stack_1_.empty());
}

TEST(StackCapacity, Size) {
  s21::Stack<int> stack_;
  std::stack<int> org_stak_;

  EXPECT_EQ(stack_.Size(), org_stak_.size());

  s21::Stack<int> stack_1_;
  stack_1_.Push(7);
  stack_1_.Push(5);
  stack_1_.Push(7);

  std::stack<int> org_stack_1_;
  org_stack_1_.push(4);
  org_stack_1_.push(4);
  org_stack_1_.push(4);

  EXPECT_EQ(stack_1_.Size(), org_stack_1_.size());

  s21::Stack<int> stack_2_;
  stack_2_.Push(7);
  stack_2_.Push(5);
  stack_2_.Push(7);
  stack_2_.Push(7);

  std::stack<int> org_stack_2_;
  org_stack_2_.push(4);
  org_stack_2_.push(9);
  org_stack_2_.push(4);

  EXPECT_NE(stack_2_.Size(), org_stack_2_.size());
}

TEST(StackModifiers, Push) {
  s21::Stack<int> stack_;
  stack_.Push(2);
  EXPECT_EQ(stack_.Size(), 1);
  EXPECT_EQ(stack_.Empty(), 0);
  EXPECT_EQ(stack_.Top(), 2);

  stack_.Push(3);
  stack_.Push(6);
  EXPECT_EQ(stack_.Size(), 3);
  EXPECT_EQ(stack_.Empty(), 0);
  EXPECT_EQ(stack_.Top(), 6);

  std::stack<int> org_stack_;
  org_stack_.push(2);
  org_stack_.push(3);
  org_stack_.push(6);

  EXPECT_EQ(stack_.Size(), org_stack_.size());
  for (size_t i = 0; i < stack_.Size(); ++i) {
    EXPECT_EQ(stack_.Top(), org_stack_.top());
    stack_.Pop();
    org_stack_.pop();
  }
}
TEST(StackModifiers, Pop) {
  s21::Stack<int> stack_ = {1, 3, 5};

  std::stack<int> org_stack_;
  org_stack_.push(1);
  org_stack_.push(3);
  org_stack_.push(5);

  stack_.Pop();
  org_stack_.pop();

  EXPECT_EQ(stack_.Size(), org_stack_.size());
  EXPECT_EQ(stack_.Top(), org_stack_.top());
}

TEST(StackModifiers, Swap) {
  s21::Stack<int> stack_ = {3, 5, 7};
  s21::Stack<int> stack_2_ = {6, 8, 10};

  stack_.Swap(stack_2_);

  EXPECT_EQ(stack_.Top(), 10);
  EXPECT_EQ(stack_2_.Top(), 7);
  EXPECT_EQ(stack_2_.Size(), stack_.Size());

  stack_.Pop();
  stack_2_.Pop();

  EXPECT_EQ(stack_.Top(), 8);
  EXPECT_EQ(stack_2_.Top(), 5);
  EXPECT_EQ(stack_2_.Size(), stack_.Size());
}

TEST(StackModifiers, InsertManyBack) {
  s21::Stack<int> stack_ = {1, 4, 8, 9};
  stack_.InsertManyBack(11, 18, 91);

  EXPECT_EQ(stack_.Top(), 91);
  stack_.Pop();
  EXPECT_EQ(stack_.Top(), 18);
  stack_.Pop();
  EXPECT_EQ(stack_.Top(), 11);
  stack_.Pop();
  EXPECT_EQ(stack_.Top(), 9);
  stack_.Pop();
  EXPECT_EQ(stack_.Top(), 8);
  stack_.Pop();
  EXPECT_EQ(stack_.Top(), 4);
  stack_.Pop();
  EXPECT_EQ(stack_.Top(), 1);
}
