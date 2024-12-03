#include <gtest/gtest.h>

#include "list.h"
#include <list>

TEST(ListFunctions, EmptyConstructor){
    s21::list<int> list_;
    EXPECT_TRUE(list_.empty());
    EXPECT_EQ(list_.size(), 0);
}

TEST(ListFunctions, MemberConstructor){
    s21::list<int> list_(3);
    EXPECT_FALSE(list_.empty());
    EXPECT_EQ(list_.size(), 3);

    for(s21::list<int>::iterator it = list_.begin(); it != list_.end(); ++it){
        EXPECT_EQ(*it, 0);
    }
}

TEST(ListFunctions, InitList){
    s21::list<int> list_ = {1,2,3};
    EXPECT_FALSE(list_.empty());
    EXPECT_EQ(list_.size(), 3);

    EXPECT_EQ(list_.front(), 1);
    list_.pop_front();
    EXPECT_EQ(list_.front(), 2);
    list_.pop_front();
    EXPECT_EQ(list_.front(), 3);
}

TEST(ListFunctions, CopyConstructor){
    s21::list<int> list_ = {1,2,3};
    s21::list<int> list_1_(list_);

    EXPECT_FALSE(list_1_.empty());
    EXPECT_EQ(list_1_.size(), 3);

    EXPECT_EQ(list_1_.front(), 1);
    list_1_.pop_front();
    EXPECT_EQ(list_1_.front(), 2);
    list_1_.pop_front();
    EXPECT_EQ(list_1_.front(), 3); 
}

TEST(ListFunctions, CopyAssigment){
    s21::list<int> list_1_ = {1,2,3};
    s21::list<int> list_2_;

    list_2_ = list_1_;

    EXPECT_EQ(list_1_.size(), list_2_.size());

    while (!list_1_.empty()){
        EXPECT_EQ(list_1_.front(), list_2_.front());
        list_1_.pop_front();
        list_2_.pop_front();
    }
}

TEST(ListFunctions, MoveAssigment){
    s21::list<int> list_1_ = {1,2,3};
    s21::list<int> list_2_;

    list_2_ = std::move(list_1_);

    EXPECT_EQ(list_2_.size(), 3);
    EXPECT_TRUE(list_1_.empty());

    EXPECT_EQ(list_2_.front(), 1);
    list_2_.pop_front();
    EXPECT_EQ(list_2_.front(), 2);
    list_2_.pop_front();
    EXPECT_EQ(list_2_.front(), 3);
}

TEST(ListFunctions, SelfAssigment){
    s21::list<int> list_1_ = {1,2,3};

    list_1_ = list_1_;

    EXPECT_EQ(list_1_.front(), 1);
    list_1_.pop_front();
    EXPECT_EQ(list_1_.front(), 2);
    list_1_.pop_front();
    EXPECT_EQ(list_1_.front(), 3);
}

TEST(ListEquality, EqualLists) {
    s21::list<int> list_1_ = {1, 2, 3};
    s21::list<int> list_2_ = {1, 2, 3};

    EXPECT_TRUE(list_1_ == list_2_);
}

TEST(ListEquality, DifferentSizes) {
    s21::list<int> list_1_ = {1, 2, 3};
    s21::list<int> list_2_ = {1, 2, 3, 4};

    EXPECT_FALSE(list_1_ == list_2_);
}

TEST(ListEquality, DifferentElements) {
    s21::list<int> list_1_ = {1, 2, 3};
    s21::list<int> list_2_ = {1, 2, 4};

    EXPECT_FALSE(list_1_ == list_2_);
}

TEST(ListEquality, EmptyLists) {
    s21::list<int> list_1_;
    s21::list<int> list_2_;

    EXPECT_TRUE(list_1_ == list_2_);
}

TEST(ListEquality, OneEmptyList) {
    s21::list<int> list_1_ = {1, 2, 3};
    s21::list<int> list_2_;

    EXPECT_FALSE(list_1_ == list_2_);
    EXPECT_FALSE(list_2_ == list_1_);
}

TEST(ListEquality, SelfComparison) {
    s21::list<int> list_1_ = {1, 2, 3};

    EXPECT_TRUE(list_1_ == list_1_);
}

TEST(ListInequality, EqualLists) {
    s21::list<int> list_1_ = {1, 2, 3};
    s21::list<int> list_2_ = {1, 2, 3};

    EXPECT_FALSE(list_1_ != list_2_);
}

TEST(ListInequality, DifferentSizes) {
    s21::list<int> list_1_ = {1, 2, 3};
    s21::list<int> list_2_ = {1, 2, 3, 4};

    EXPECT_TRUE(list_1_ != list_2_);
}

TEST(ListInequality, DifferentElements) {
    s21::list<int> list_1_ = {1, 2, 3};
    s21::list<int> list_2_ = {1, 2, 4};

    EXPECT_TRUE(list_1_ != list_2_);
}

TEST(ListInequality, EmptyLists) {
    s21::list<int> list_1_;
    s21::list<int> list_2_;

    EXPECT_FALSE(list_1_ != list_2_);
}

TEST(ListInequality, OneEmptyList) {
    s21::list<int> list_1_ = {1, 2, 3};
    s21::list<int> list_2_;

    EXPECT_TRUE(list_1_ != list_2_);
    EXPECT_TRUE(list_2_ != list_1_);
}

TEST(ListInequality, SelfComparison) {
    s21::list<int> list_1_ = {1, 2, 3};

    EXPECT_FALSE(list_1_ != list_1_);
}

TEST(ListInequality, ComplexCase) {
    s21::list<int> list_1_ = {10, 20, 30, 40, 50};
    s21::list<int> list_2_ = {10, 20, 30, 40, 50};

    EXPECT_FALSE(list_1_ != list_2_);

    list_2_.push_back(60);
    EXPECT_TRUE(list_1_ != list_2_);
}

TEST(ListElementAccess, Front){
    s21::list<int> list_ = {1, 2 ,3};
    std::list<int> org_list_ = {1, 2, 3};

    EXPECT_EQ(list_.front(), org_list_.front());
    list_.pop_front();
    org_list_.pop_front();
    EXPECT_EQ(list_.front(), org_list_.front());
    list_.pop_front();
    org_list_.pop_front();
}

TEST(ListElementAccess, Back){
    s21::list<int> list_ = {1, 2 ,3};
    std::list<int> org_list_ = {1, 2, 3};

    EXPECT_EQ(list_.back(), org_list_.back());
    list_.pop_back();
    org_list_.pop_back();
    EXPECT_EQ(list_.back(), org_list_.back());
    list_.pop_back();
    org_list_.pop_back();
}

TEST(ListIterators, Begin){
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

TEST(ListIterators, EndEmptyList){
    s21::list<int> list_;
    EXPECT_EQ(list_.begin(), list_.end());
}

TEST(ListIterators, EndNonEmptyList){
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

TEST(ListIterators, EndAfterErasingElements) {
    s21::list<int> test_list = {10, 20, 30};

    while (!test_list.empty()) {
        test_list.pop_back();
    }

    EXPECT_EQ(test_list.begin(), test_list.end());
}

TEST(ListCapacity, Empty){
    s21::list<int> list_;
    std::list<int> org_list_;
    EXPECT_EQ(list_.empty(), org_list_.empty());

    s21::list<int> stack_1_;
    stack_1_.push_back(7);
    std::list<int> org_stack_1_;
    org_stack_1_.push_back(4);

    EXPECT_EQ(stack_1_.empty(), org_stack_1_.empty());
}

TEST(ListCapacity, Size){
    s21::list<int> list_;
    std::list<int> org_list_;

    EXPECT_EQ(list_.size(), org_list_.size());

    s21::list<int> list_1_ = {1, 2, 3};
    std::list<int> org_list_1_ = {1, 2, 3};

    EXPECT_EQ(list_1_.size(), org_list_1_.size());
}

TEST(ListClear, ClearNonEmptyList) {
    s21::list<int> list = {1, 2, 3, 4, 5};

    EXPECT_EQ(list.size(), 5);  
    list.clear();               
    EXPECT_TRUE(list.empty());  
    EXPECT_EQ(list.size(), 0);  
}

TEST(ListClear, ClearEmptyList) {
    s21::list<int> list; 

    EXPECT_TRUE(list.empty());  
    EXPECT_NO_THROW(list.clear());  
    EXPECT_EQ(list.size(), 0);  
}

TEST(ListClear, ClearSingleElementList) {
    s21::list<int> list = {42}; 

    EXPECT_EQ(list.size(), 1);  
    EXPECT_FALSE(list.empty()); 
    list.clear();               
    EXPECT_TRUE(list.empty());  
    EXPECT_EQ(list.size(), 0);  
}

TEST(ListClear, ClearAndReuseList) {
    s21::list<int> list = {10, 20, 30};

    EXPECT_EQ(list.size(), 3); 
    list.clear();              
    EXPECT_TRUE(list.empty()); 
    EXPECT_EQ(list.size(), 0); 

    list.push_back(100);        
    EXPECT_FALSE(list.empty()); 
    EXPECT_EQ(list.size(), 1);  
    EXPECT_EQ(list.front(), 100); 
}

TEST(ListClear, ClearLargeList) {
    s21::list<int> list;

    for (int i = 0; i < 1000; ++i) {
        list.push_back(i);
    }
    EXPECT_EQ(list.size(), 1000); 

    list.clear();                 
    EXPECT_TRUE(list.empty());    
    EXPECT_EQ(list.size(), 0);    
}

TEST(ListClear, ClearTwice) {
    s21::list<int> list = {1, 2, 3};

    list.clear();               
    EXPECT_TRUE(list.empty());  
    EXPECT_EQ(list.size(), 0);  
    list.clear();               
    EXPECT_TRUE(list.empty());  
    EXPECT_EQ(list.size(), 0);  
}

TEST(ListInsert, InsertAtBegin) {
    s21::list<int> list_ = {10, 20, 30};
    auto it = list_.begin();

    list_.insert(it, 5);

    it = list_.begin();
    EXPECT_EQ(*it, 5); 
    ++it;
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
}

TEST(ListInsert, InsertInMiddle) {
    s21::list<int> list_ = {10, 20, 30};
    s21::list<int>::iterator it = list_.begin();
    ++it;

    list_.insert(it, 15);

    it = list_.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 15);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
}

TEST(ListInsert, InsertAtEnd) {
    s21::list<int> list_ = {10, 20, 30};
    auto it = list_.end();

    list_.insert(it, 35);

    it = list_.begin();
    EXPECT_EQ(*it, 10);  
    ++it;
    EXPECT_EQ(*it, 20);  
    ++it;
    EXPECT_EQ(*it, 30);  
    ++it;
    EXPECT_EQ(*it, 35);  
}

TEST(ListInsert, InsertIntoEmptyList) {
    s21::list<int> list_;
    auto it = list_.begin();

    list_.insert(it, 42);

    it = list_.begin();
    EXPECT_EQ(*it, 42);
    ++it;
    EXPECT_EQ(it, list_.end());
}

TEST(ListInsert, InsertMultipleTimes) {
    s21::list<int> list_ = {10, 20, 30};
    auto it = list_.begin();
    ++it; 

    list_.insert(it, 15);
    list_.insert(it, 17);

    it = list_.begin();
    EXPECT_EQ(*it, 10);  
    ++it;
    EXPECT_EQ(*it, 15);  
    ++it;
    EXPECT_EQ(*it, 17);  
    ++it;
    EXPECT_EQ(*it, 20);  
    ++it;
    EXPECT_EQ(*it, 30);  
}

TEST(ListInsert, InsertAndReturnIterator) {
    s21::list<int> list_ = {10, 20, 30};
    auto it = list_.begin();
    ++it;

    auto returned_it = list_.insert(it, 15);

    EXPECT_EQ(*returned_it, 15);
    --returned_it; 
    EXPECT_EQ(*returned_it, 10);
}

TEST(ListErase, EraseFirst){
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

TEST(ListErase, Erase){
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

TEST(ListErase, EraseAtEnd) {
    s21::list<int> list_ = {10, 20, 30, 40};
    s21::list<int>::iterator it = list_.begin();
    ++it;
    ++it;
    ++it;
    list_.erase(it);

    std::list<int> org_list_ = {10, 20, 30, 40};
    auto org_it = org_list_.begin();
    ++org_it;
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

TEST(ListMerge, Merge){
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

TEST(ListMerge, MergeEmpty){
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

TEST(ListMerge, MergeInEmpty){
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

TEST(ListSplice, SpliceEmptyList){
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

TEST(ListSplice, SpliceInEmptyList){
    s21::list<int> list_;
    s21::list<int> list_1 = {1,2,3};

    s21::list<int>::iterator it = list_.begin();
    list_.splice(it, list_1);

    EXPECT_TRUE(list_1.empty());
    EXPECT_EQ(list_.size(), 3);

    std::list<int> org_list_;
    std::list<int> org_list_1 = {1,2,3};

    auto org_it = org_list_.begin();
    org_list_.splice(org_it, org_list_1);

    it = list_.begin();
    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }

    EXPECT_TRUE(org_list_1.empty());
}

TEST(ListSplice, Splice){
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

TEST(ListUnique, Unique){
    s21::list<int> list_ = {3, 4, 6, 8, 8, 9, 4, 4, 9};
    list_.unique();

    std::list<int> org_list_ = {3, 4, 6, 8, 8, 9, 4, 4, 9};
    org_list_.unique();

    s21::list<int>::iterator it = list_.begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
    ++it;
    }
}

TEST(ListUnique, UniqueNoDubl){
    s21::list<int> list_ = {10, 20, 30, 55, 78};
    list_.unique();

    std::list<int> org_list_ = {10, 20, 30, 55, 78};
    org_list_.unique();

    s21::list<int>::iterator it = list_.begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
    ++it;
    }
}

TEST(List, Sort){
    s21::list<int> list_ = {8, 3, 9, 2, 5, 1, 1, 10};
    list_.unique();

    std::list<int> org_list_ = {8, 3, 9, 2, 5, 1, 1, 10};
    org_list_.unique();

    s21::list<int>::iterator it = list_.begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
    ++it;
    }
}
