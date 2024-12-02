#include <gtest/gtest.h>

#include "list.h"
#include <list>

TEST(List, EmptyConstructor){
    s21::list<int> list_;
    EXPECT_TRUE(list_.empty());
    EXPECT_EQ(list_.size(), 0);
}

TEST(List, MemberConstructor){
    s21::list<int> list_(3);
    EXPECT_FALSE(list_.empty());
    EXPECT_EQ(list_.size(), 3);

    for(s21::list<int>::iterator it = list_.begin(); it != list_.end(); ++it){
        EXPECT_EQ(*it, 0);
    }
}

TEST(Queue, InitList){
    s21::list<int> list_ = {1, 2, 3};
    EXPECT_FALSE(list_.empty());
    EXPECT_EQ(list_.size(), 3);
}

TEST(List, InitList){
    s21::list<int> list_ = {1,2,3};
    EXPECT_FALSE(list_.empty());
    EXPECT_EQ(list_.size(), 3);

    EXPECT_EQ(list_.front(), 1);
    list_.pop_front();
    EXPECT_EQ(list_.front(), 2);
    list_.pop_front();
    EXPECT_EQ(list_.front(), 3);
}


TEST(List, Front){
    s21::list<int> list_ = {1, 2 ,3};
    std::list<int> org_list_ = {1, 2, 3};

    EXPECT_EQ(list_.front(), org_list_.front());
    list_.pop_front();
    EXPECT_EQ(list_.front(), org_list_.front());
    list_.pop_front();
}

TEST(List, Back){
    s21::list<int> list_ = {1, 2 ,3};
    std::list<int> org_list_ = {1, 2, 3};

    EXPECT_EQ(list_.back(), org_list_.back());
    list_.pop_back();
    EXPECT_EQ(list_.back(), org_list_.back());
    list_.pop_back();
}

TEST(List, Begin){
    s21::list<int> list_;

    s21::list<int>::iterator it_empty = list_.begin();
    EXPECT_EQ(it_empty, list_.end());

    list_.push_back(10);
    list_.push_back(20);
    list_.push_back(30);

    s21::list<int>::iterator it = list_.begin();
    EXPECT_EQ(*it, 10);

    ++it;
    EXPECT_EQ(*it, 20);

    ++it;
    EXPECT_EQ(*it, 30);

    ++it;
    EXPECT_EQ(it, list_.end());
}

TEST(List, EndEmptyList){
    s21::list<int> list_;
    EXPECT_EQ(list_.begin(), list_.end());
}

TEST(List, EndNonEmptyList){
    s21::list<int> list_;

    list_.push_back(10);
    list_.push_back(20);
    list_.push_back(30);

    EXPECT_NE(list_.begin(), list_.end());

    s21::list<int>::iterator it = list_.begin();
    EXPECT_EQ(*it, 10);

    ++it;
    EXPECT_EQ(*it, 20);

    ++it;
    EXPECT_EQ(*it, 30);

    ++it;
    EXPECT_EQ(it, list_.end());
}

TEST(List, EndAfterErasingElements) {
    s21::list<int> test_list = {10, 20, 30};

    while (!test_list.empty()) {
        test_list.pop_back();
    }

    EXPECT_EQ(test_list.begin(), test_list.end());
}

TEST(List, Empty){
    s21::list<int> list_;
    std::list<int> org_list_;
    EXPECT_EQ(list_.empty(), org_list_.empty());

    s21::list<int> stack_1_;
    stack_1_.push_back(7);
    std::list<int> org_stack_1_;
    org_stack_1_.push_back(4);

    EXPECT_EQ(stack_1_.empty(), org_stack_1_.empty());
}

TEST(List, Size){
    s21::list<int> list_;
    std::list<int> org_list_;

    EXPECT_EQ(list_.size(), org_list_.size());

    s21::list<int> list_1_ = {1, 2, 3};
    std::list<int> org_list_1_ = {1, 2, 3};

    EXPECT_EQ(list_1_.size(), org_list_1_.size());
}

TEST(List, EraseFirst){
    s21::list<int> list_ = {10, 20, 30};
    s21::list<int>::iterator it = list_.begin();

    list_.erase(it);

    std::list<int> org_list_ = {10, 20, 30};
    auto org_it = org_list_.begin();

    org_list_.erase(org_it);

    it = list_.begin();
    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(List, Erase){
    s21::list<int> list_ = {10, 20, 30, 66};
    s21::list<int>::iterator it = list_.begin();
    ++it;
    ++it;

    list_.erase(it);

    std::list<int> org_list_ = {10, 20, 30, 66};
    auto org_it = org_list_.begin();
    ++org_it;
    ++org_it;

    org_list_.erase(org_it);

    it = list_.begin();
    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(List, PushBack){
    s21::list<int> list_;
    std::list<int> org_list_;

    list_.push_back(5);
    org_list_.push_back(5);

    EXPECT_EQ(list_.back(), org_list_.back());
    EXPECT_EQ(list_.size(), org_list_.size());

    list_.push_back(8);
    org_list_.push_back(8);

    EXPECT_EQ(list_.back(), org_list_.back());
    EXPECT_EQ(list_.size(), org_list_.size());

}

TEST(List, PopBack){
    s21::list<int> list_ = {3, 6, 9};
    std::list<int> org_list_ = {3, 6, 9};

    list_.pop_back();
    org_list_.pop_back();

    EXPECT_EQ(list_.back(), org_list_.back());
    EXPECT_EQ(list_.size(), org_list_.size());

    list_.pop_back();
    org_list_.pop_back();

    EXPECT_EQ(list_.back(), org_list_.back());
    EXPECT_EQ(list_.size(), org_list_.size());
}

TEST(List, PushFront){
    s21::list<int> list_;
    std::list<int> org_list_;

    list_.push_front(5);
    org_list_.push_front(5);

    EXPECT_EQ(list_.front(), org_list_.front());
    EXPECT_EQ(list_.size(), org_list_.size());

    list_.push_front(8);
    org_list_.push_front(8);

    EXPECT_EQ(list_.front(), org_list_.front());
    EXPECT_EQ(list_.size(), org_list_.size());
}

TEST(List, PopFront){
    s21::list<int> list_ = {3, 6, 9};
    std::list<int> org_list_ = {3, 6, 9};

    list_.pop_front();
    org_list_.pop_front();

    EXPECT_EQ(list_.front(), org_list_.front());
    EXPECT_EQ(list_.size(), org_list_.size());

    list_.pop_front();
    org_list_.pop_front();

    EXPECT_EQ(list_.back(), org_list_.back());
    EXPECT_EQ(list_.size(), org_list_.size());
}

TEST(List, Swap){
    s21::list<int> list_ = {3,5,7};
    s21::list<int> list_2_ = {6,8,10};

    list_.swap(list_2_);

    EXPECT_EQ(list_.front(), 6);
    EXPECT_EQ(list_2_.front(), 3);
    EXPECT_EQ(list_2_.size(), list_.size());

    list_.pop_front();
    list_2_.pop_front();

    EXPECT_EQ(list_.front(), 8);
    EXPECT_EQ(list_2_.front(), 5);
    EXPECT_EQ(list_2_.size(), list_.size());
}

TEST(List, Merge){
    s21::list<int> list_1_ = {1, 5, 8, 9};
    s21::list<int> list_2_ = {2, 3, 6, 7};

    list_1_.merge(list_2_);

    std::list<int> org_list_ = {1, 5, 8, 9};
    std::list<int> org_list_1_ = {2, 3, 6, 7};

    org_list_.merge(org_list_1_);

    s21::list<int>::iterator it = list_1_.begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }

}

TEST(List, MergeEmpty){
    s21::list<int> list_1_;
    s21::list<int> list_2_ = {2, 3, 6, 7};

    list_1_.merge(list_2_);
    EXPECT_EQ(list_2_.size(), 0);

    std::list<int> org_list_;
    std::list<int> org_list_1_ = {2, 3, 6, 7};;

    org_list_.merge(org_list_1_);

    s21::list<int>::iterator it = list_1_.begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }

}

TEST(List, MergeInEmpty){
    s21::list<int> list_1_ = {1, 5, 8, 9};
    s21::list<int> list_2_;

    list_1_.merge(list_2_);
    EXPECT_EQ(list_2_.size(), 0);

    std::list<int> org_list_ = {1, 5, 8, 9};
    std::list<int> org_list_1_;

    org_list_.merge(org_list_1_);

    s21::list<int>::iterator it = list_1_.begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }

}

TEST(List, SpliceEmptyList){
    s21::list<int> list_ = {1,2,3};;
    s21::list<int> list_1;

    s21::list<int>::iterator it = list_.begin();
    list_.splice(it, list_1);


    std::list<int> org_list_ = {1,2,3};
    std::list<int> org_list_1;

    auto org_it = org_list_.begin();
    org_list_.splice(org_it, org_list_1);

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(List, SpliceInEmptyList){
    s21::list<int> list_;
    s21::list<int> list_1 = {1,2,3};

    s21::list<int>::iterator it = list_.begin();
    list_.splice(it, list_1);


    std::list<int> org_list_;
    std::list<int> org_list_1 = {1,2,3};

    auto org_it = org_list_.begin();
    org_list_.splice(org_it, org_list_1);

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(List, Splice){
    s21::list<int> list_ = {32,45,10,11};
    s21::list<int> list_1 = {9,1,2};

    s21::list<int>::iterator it = list_.begin();
    ++it;
    ++it;
    list_.splice(it, list_1);


    std::list<int> org_list_ = {32,45,10,11};;
    std::list<int> org_list_1 = {9,1,2};

    auto org_it = org_list_.begin();
    ++org_it;
    ++org_it;
    org_list_.splice(org_it, org_list_1);

    it = list_.begin();
    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(List, Reverse){
    s21::list<int> list_ = {10, 20, 30, 55, 98};
    list_.reverse();

    std::list<int> org_list_ = {10, 20, 30, 55, 98};
    org_list_.reverse();

    s21::list<int>::iterator it = list_.begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
    ++it;
    }
}


