#include <gtest/gtest.h>

#include <queue>

#include "../s21queue/queue.h"

TEST(Queue, EmptyConsructor) {
  s21::queue<int> queue_;
  EXPECT_TRUE(queue_.empty());
  EXPECT_EQ(queue_.size(), 0);
}

TEST(Queue, InitList) {
  s21::queue<int> queue_ = {1, 2, 3};
  EXPECT_FALSE(queue_.empty());
  EXPECT_EQ(queue_.size(), 3);
}

TEST(Queue, CopyConstructor) {
  s21::queue<int> queue_1_ = {1, 2, 3};
  s21::queue<int> queue_2_(queue_1_);

  EXPECT_FALSE(queue_2_.empty());
  EXPECT_EQ(queue_2_.size(), 3);

  EXPECT_EQ(queue_2_.front(), 1);
  queue_2_.pop();
  EXPECT_EQ(queue_2_.front(), 2);
  queue_2_.pop();
  EXPECT_EQ(queue_2_.front(), 3);
}

TEST(Queue, CopyAssigment) {
  s21::queue<int> queue_1_ = {1, 2, 3};
  s21::queue<int> queue_2_;

  queue_2_ = queue_1_;

  EXPECT_EQ(queue_1_.size(), queue_2_.size());

  while (!queue_1_.empty()) {
    EXPECT_EQ(queue_1_.front(), queue_2_.front());
    queue_1_.pop();
    queue_2_.pop();
  }
}

TEST(Queue, MoveAssigment) {
  s21::queue<int> queue_1_ = {1, 2, 3};
  s21::queue<int> queue_2_;

  queue_2_ = std::move(queue_1_);

  EXPECT_EQ(queue_2_.size(), 3);
  EXPECT_TRUE(queue_1_.empty());

  EXPECT_EQ(queue_2_.front(), 1);
  queue_2_.pop();
  EXPECT_EQ(queue_2_.front(), 2);
  queue_2_.pop();
  EXPECT_EQ(queue_2_.front(), 3);
}

TEST(Queue, SelfAssigment) {
  s21::queue<int> queue_1_ = {1, 2, 3};

  queue_1_ = queue_1_;

  EXPECT_EQ(queue_1_.front(), 1);
  queue_1_.pop();
  EXPECT_EQ(queue_1_.front(), 2);
  queue_1_.pop();
  EXPECT_EQ(queue_1_.front(), 3);
}

TEST(QueueElementAccess, Front) {
  s21::queue<int> queue_ = {1, 2, 3};
  std::queue<int> org_queue;
  org_queue.push(1);
  org_queue.push(2);
  org_queue.push(3);

  EXPECT_EQ(queue_.front(), org_queue.front());
}

TEST(QueueElementAccess, Back) {
  s21::queue<int> queue_ = {1, 2, 3};
  std::queue<int> org_queue;
  org_queue.push(1);
  org_queue.push(2);
  org_queue.push(3);

  EXPECT_EQ(queue_.back(), org_queue.back());
}

TEST(QueueCapacity, Empty) {
  s21::queue<int> queue_;
  std::queue<int> org_queue_;
  EXPECT_EQ(queue_.empty(), org_queue_.empty());

  s21::queue<int> stack_1_;
  stack_1_.push(7);
  std::queue<int> org_stack_1_;
  org_stack_1_.push(4);

  EXPECT_EQ(stack_1_.empty(), org_stack_1_.empty());
}

TEST(QueueCapacity, Size) {
  s21::queue<int> queue_;
  std::queue<int> org_queue_;

  EXPECT_EQ(queue_.size(), org_queue_.size());

  s21::queue<int> queue_1_;
  queue_1_.push(7);
  queue_1_.push(5);
  queue_1_.push(7);

  std::queue<int> org_queue_1_;
  org_queue_1_.push(4);
  org_queue_1_.push(4);
  org_queue_1_.push(4);

  EXPECT_EQ(queue_1_.size(), org_queue_1_.size());
}

TEST(QueueModifiers, Push) {
  s21::queue<int> queue_;
  queue_.push(2);
  EXPECT_EQ(queue_.size(), 1);
  EXPECT_EQ(queue_.empty(), 0);
  EXPECT_EQ(queue_.front(), 2);

  queue_.push(3);
  queue_.push(6);
  EXPECT_EQ(queue_.size(), 3);
  EXPECT_EQ(queue_.empty(), 0);
  EXPECT_EQ(queue_.front(), 2);
  EXPECT_EQ(queue_.back(), 6);

  std::queue<int> org_queue_;
  org_queue_.push(2);
  org_queue_.push(3);
  org_queue_.push(6);

  EXPECT_EQ(queue_.size(), org_queue_.size());
  for (size_t i = 0; i < queue_.size(); ++i) {
    EXPECT_EQ(queue_.front(), org_queue_.front());
    queue_.pop();
    org_queue_.pop();
  }
}

TEST(QueueModifiers, Pop) {
  s21::queue<int> queue = {1, 3, 5};

  std::queue<int> org_queue_;
  org_queue_.push(1);
  org_queue_.push(3);
  org_queue_.push(5);

  queue.pop();
  org_queue_.pop();

  EXPECT_EQ(queue.size(), org_queue_.size());
  EXPECT_EQ(queue.front(), org_queue_.front());
}

TEST(QueueModifiers, Swap) {
  s21::queue<int> queue_ = {3, 5, 7};
  s21::queue<int> queue_2_ = {6, 8, 10};

  queue_.swap(queue_2_);

  EXPECT_EQ(queue_.front(), 6);
  EXPECT_EQ(queue_2_.front(), 3);
  EXPECT_EQ(queue_2_.size(), queue_.size());

  queue_.pop();
  queue_2_.pop();

  EXPECT_EQ(queue_.front(), 8);
  EXPECT_EQ(queue_2_.front(), 5);
  EXPECT_EQ(queue_2_.size(), queue_.size());
}