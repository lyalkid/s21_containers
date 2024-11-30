#include <gtest/gtest.h>

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

    for(size_t i = 0; i < stack_2_.size(); ++i){
        EXPECT_EQ(stack_2_.top(), stack_1_.top());
        stack_1_.pop();
        stack_2_.pop();
    }

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
    stack_.push(7);
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
    org_stack_2_.push(4);
    org_stack_2_.push(4);

    EXPECT_NE(stack_2_.size(), org_stack_2_.size());
}

TEST(Stack, Push){
    s21::stack<int> stack_;
    stack_.push(2);
    EXPECT_EQ(stack_.size(), 1);
    EXPECT_EQ(stack_.empty(), 0);
}
