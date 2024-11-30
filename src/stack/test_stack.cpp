#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include "stack.h"

TEST(Stack, EmptyConstructor){
    s21::stack<int> stack_;
    EXPECT_TRUE(stack_.empty());
    EXPECT_EQ(stack_.size(), 0);
}

TEST(Stack, InitList){
    s21::stack<int> stack_ = {1, 2, 3};
    EXPECT_FALSE(stack_.empty());
    EXPECT_EQ(stack_.size(), 3);
    EXPECT_EQ(stack_.top(), 3);
}

TEST(Stack, CopyConstructor){
    s21::stack<int> stack_1_ = {1, 2, 3};
    s21::stack<int> stack_2_(stack_1_);

    EXPECT_FALSE(stack_2_.empty());
    EXPECT_EQ(stack_2_.size(), 3);
}

TEST(Stack, CopyAssigment){
    s21::stack<int> stack_1_ = {1,2,3};
    s21::stack<int> stack_2_;

    stack_2_= stack_1_;

    EXPECT_EQ(stack_1_.size(), stack_2_.size());

    while (!stack_1_.empty()){
        EXPECT_EQ(stack_1_.top(), stack_2_.top());
        stack_1_.pop();
        stack_2_.pop();
    }
}

TEST(Stack, MoveAssigment){
    s21::stack<int> stack_1_ = {1,2,3};
    s21::stack<int> stack_2_;

    stack_2_ = std::move(stack_1_);

    EXPECT_EQ(stack_2_.size(), 3);
    EXPECT_TRUE(stack_1_.empty());

    EXPECT_EQ(stack_2_.top(), 3);
    stack_2_.pop();
    EXPECT_EQ(stack_2_.top(), 2);
    stack_2_.pop();
    EXPECT_EQ(stack_2_.top(), 1);
}

TEST(Stack, SelfAssigment){
    s21::stack<int> stack_1_ = {1,2,3};

    stack_1_ = stack_1_;

    EXPECT_EQ(stack_1_.top(), 3);
    stack_1_.pop();
    EXPECT_EQ(stack_1_.top(), 2);
    stack_1_.pop();
    EXPECT_EQ(stack_1_.top(), 1);
}

TEST(Stack, Top){
    s21::stack<int> stack_;
    stack_.push(4);
    stack_.push(3);
    stack_.push(7);

    std::stack<int> stack_org_;
    stack_org_.push(4);
    stack_org_.push(3);
    stack_org_.push(7);

    EXPECT_EQ(stack_.top(), stack_org_.top());
}

TEST(Stack, Empty){
    s21::stack<int> stack_;
    std::stack<int> org_stak_;
    EXPECT_EQ(stack_.empty(), org_stak_.empty());

    s21::stack<int> stack_1_;
    stack_1_.push(7);
    std::stack<int> org_stack_1_;
    org_stack_1_.push(4);

    EXPECT_EQ(stack_1_.empty(), org_stack_1_.empty());

}

TEST(Stack, Size) {
    s21::stack<int> stack_;
    std::stack<int> org_stak_;

    EXPECT_EQ(stack_.size(), org_stak_.size());

    s21::stack<int> stack_1_;
    stack_1_.push(7);
    stack_1_.push(5);
    stack_1_.push(7);

    std::stack<int> org_stack_1_;
    org_stack_1_.push(4);
    org_stack_1_.push(4);
    org_stack_1_.push(4);

    EXPECT_EQ(stack_1_.size(), org_stack_1_.size());

    s21::stack<int> stack_2_;
    stack_2_.push(7);
    stack_2_.push(5);
    stack_2_.push(7);
    stack_2_.push(7);

    std::stack<int> org_stack_2_;
    org_stack_2_.push(4);
    org_stack_2_.push(9);
    org_stack_2_.push(4);

    EXPECT_NE(stack_2_.size(), org_stack_2_.size());
}

TEST(Stack, Push){
    s21::stack<int> stack_;
    stack_.push(2);
    EXPECT_EQ(stack_.size(), 1);
    EXPECT_EQ(stack_.empty(), 0);
    EXPECT_EQ(stack_.top(), 2);

    stack_.push(3);
    stack_.push(6);
    EXPECT_EQ(stack_.size(), 3);
    EXPECT_EQ(stack_.empty(), 0);
    EXPECT_EQ(stack_.top(), 6);

    std::stack<int> org_stack_;
    org_stack_.push(2);
    org_stack_.push(3);
    org_stack_.push(6);

    EXPECT_EQ(stack_.size(), org_stack_.size());
    for(size_t i = 0; i < stack_.size(); ++i){
        EXPECT_EQ(stack_.top(), org_stack_.top());
        stack_.pop();
        org_stack_.pop();
    }

}
TEST(Stack, Pop){
    s21::stack<int> stack_ = {1,3,5};

    std::stack<int> org_stack_;
    org_stack_.push(1);
    org_stack_.push(3);
    org_stack_.push(5);

    stack_.pop();
    org_stack_.pop();

    EXPECT_EQ(stack_.size(), org_stack_.size());
    EXPECT_EQ(stack_.top(), org_stack_.top());
}

TEST(Stack, Swap){
    s21::stack<int> stack_ = {3,5,7};
    s21::stack<int> stack_2_ = {6,8,10};

    stack_.swap(stack_2_);

    EXPECT_EQ(stack_.top(), 10);
    EXPECT_EQ(stack_2_.top(), 7);
    EXPECT_EQ(stack_2_.size(), stack_.size());

    stack_.pop();
    stack_2_.pop();

    EXPECT_EQ(stack_.top(), 8);
    EXPECT_EQ(stack_2_.top(), 5);
    EXPECT_EQ(stack_2_.size(), stack_.size());
}


