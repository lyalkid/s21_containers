#include <gtest/gtest.h>

#include <queue>

#include "../s21queue/queue.h"

TEST(Queue, EmptyConsructor) {
  s21::Queue<int> queue_;
  EXPECT_TRUE(queue_.Empty());
  EXPECT_EQ(queue_.Size(), 0);
}

TEST(Queue, InitList) {
  s21::Queue<int> queue_ = {1, 2, 3};
  EXPECT_FALSE(queue_.Empty());
  EXPECT_EQ(queue_.Size(), 3);
}

TEST(Queue, CopyConstructor) {
  s21::Queue<int> queue_1_ = {1, 2, 3};
  s21::Queue<int> queue_2_(queue_1_);

  EXPECT_FALSE(queue_2_.Empty());
  EXPECT_EQ(queue_2_.Size(), 3);

  EXPECT_EQ(queue_2_.Front(), 1);
  queue_2_.Pop();
  EXPECT_EQ(queue_2_.Front(), 2);
  queue_2_.Pop();
  EXPECT_EQ(queue_2_.Front(), 3);
}

TEST(Queue, MoveConstructor) {
  s21::Queue<int> queue_1_ = {1, 4, 18};
  s21::Queue<int> queue_2_(std::move(queue_1_));

  EXPECT_EQ(queue_2_.Size(), 3);

  EXPECT_EQ(queue_2_.Front(), 1);
  queue_2_.Pop();
  EXPECT_EQ(queue_2_.Front(), 4);
  queue_2_.Pop();
  EXPECT_EQ(queue_2_.Front(), 18);
}

TEST(Queue, CopyAssigment) {
  s21::Queue<int> queue_1_ = {1, 2, 3};
  s21::Queue<int> queue_2_;

  queue_2_ = queue_1_;

  EXPECT_EQ(queue_1_.Size(), queue_2_.Size());

  while (!queue_1_.Empty()) {
    EXPECT_EQ(queue_1_.Front(), queue_2_.Front());
    queue_1_.Pop();
    queue_2_.Pop();
  }
}

TEST(Queue, MoveAssigment) {
  s21::Queue<int> queue_1_ = {1, 2, 3};
  s21::Queue<int> queue_2_;

  queue_2_ = std::move(queue_1_);

  EXPECT_EQ(queue_2_.Size(), 3);
  EXPECT_TRUE(queue_1_.Empty());

  EXPECT_EQ(queue_2_.Front(), 1);
  queue_2_.Pop();
  EXPECT_EQ(queue_2_.Front(), 2);
  queue_2_.Pop();
  EXPECT_EQ(queue_2_.Front(), 3);
}

TEST(Queue, SelfAssigment) {
  s21::Queue<int> queue_1_ = {1, 2, 3};

  queue_1_ = queue_1_;

  EXPECT_EQ(queue_1_.Front(), 1);
  queue_1_.Pop();
  EXPECT_EQ(queue_1_.Front(), 2);
  queue_1_.Pop();
  EXPECT_EQ(queue_1_.Front(), 3);
}

TEST(QueueElementAccess, Front) {
  s21::Queue<int> queue_ = {1, 2, 3};
  std::queue<int> org_queue;
  org_queue.push(1);
  org_queue.push(2);
  org_queue.push(3);

  EXPECT_EQ(queue_.Front(), org_queue.front());
}

TEST(QueueElementAccess, Back) {
  s21::Queue<int> queue_ = {1, 2, 3};
  std::queue<int> org_queue;
  org_queue.push(1);
  org_queue.push(2);
  org_queue.push(3);

  EXPECT_EQ(queue_.Back(), org_queue.back());
}

TEST(QueueCapacity, Empty) {
  s21::Queue<int> queue_;
  std::queue<int> org_queue_;
  EXPECT_EQ(queue_.Empty(), org_queue_.empty());

  s21::Queue<int> stack_1_;
  stack_1_.Push(7);
  std::queue<int> org_stack_1_;
  org_stack_1_.push(4);

  EXPECT_EQ(stack_1_.Empty(), org_stack_1_.empty());
}

TEST(QueueCapacity, Size) {
  s21::Queue<int> queue_;
  std::queue<int> org_queue_;

  EXPECT_EQ(queue_.Size(), org_queue_.size());

  s21::Queue<int> queue_1_;
  queue_1_.Push(7);
  queue_1_.Push(5);
  queue_1_.Push(7);

  std::queue<int> org_queue_1_;
  org_queue_1_.push(4);
  org_queue_1_.push(4);
  org_queue_1_.push(4);

  EXPECT_EQ(queue_1_.Size(), org_queue_1_.size());
}

TEST(QueueModifiers, Push) {
  s21::Queue<int> queue_;
  queue_.Push(2);
  EXPECT_EQ(queue_.Size(), 1);
  EXPECT_EQ(queue_.Empty(), 0);
  EXPECT_EQ(queue_.Front(), 2);

  queue_.Push(3);
  queue_.Push(6);
  EXPECT_EQ(queue_.Size(), 3);
  EXPECT_EQ(queue_.Empty(), 0);
  EXPECT_EQ(queue_.Front(), 2);
  EXPECT_EQ(queue_.Back(), 6);

  std::queue<int> org_queue_;
  org_queue_.push(2);
  org_queue_.push(3);
  org_queue_.push(6);

  EXPECT_EQ(queue_.Size(), org_queue_.size());
  for (size_t i = 0; i < queue_.Size(); ++i) {
    EXPECT_EQ(queue_.Front(), org_queue_.front());
    queue_.Pop();
    org_queue_.pop();
  }
}

TEST(QueueModifiers, Pop) {
  s21::Queue<int> queue = {1, 3, 5};

  std::queue<int> org_queue_;
  org_queue_.push(1);
  org_queue_.push(3);
  org_queue_.push(5);

  queue.Pop();
  org_queue_.pop();

  EXPECT_EQ(queue.Size(), org_queue_.size());
  EXPECT_EQ(queue.Front(), org_queue_.front());
}

TEST(QueueModifiers, Swap) {
  s21::Queue<int> queue_ = {3, 5, 7};
  s21::Queue<int> queue_2_ = {6, 8, 10};

  queue_.Swap(queue_2_);

  EXPECT_EQ(queue_.Front(), 6);
  EXPECT_EQ(queue_2_.Front(), 3);
  EXPECT_EQ(queue_2_.Size(), queue_.Size());

  queue_.Pop();
  queue_2_.Pop();

  EXPECT_EQ(queue_.Front(), 8);
  EXPECT_EQ(queue_2_.Front(), 5);
  EXPECT_EQ(queue_2_.Size(), queue_.Size());
}

TEST(QueueModifiers, InsertManyBack) {
  s21::Queue<int> queue_ = {1, 4, 8, 9};
  queue_.InsertManyBack(11, 18, 91);

  EXPECT_EQ(queue_.Front(), 1);
  queue_.Pop();
  EXPECT_EQ(queue_.Front(), 4);
  queue_.Pop();
  EXPECT_EQ(queue_.Front(), 8);
  queue_.Pop();
  EXPECT_EQ(queue_.Front(), 9);
  queue_.Pop();
  EXPECT_EQ(queue_.Front(), 11);
  queue_.Pop();
  EXPECT_EQ(queue_.Front(), 18);
  queue_.Pop();
  EXPECT_EQ(queue_.Front(), 91);
}
