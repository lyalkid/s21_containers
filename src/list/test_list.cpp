#include <gtest/gtest.h>

#include "list.h"
#include <list>

TEST(ListFunctions, EmptyConstructor){
    s21::List<int> list_;
    EXPECT_TRUE(list_.Empty());
    EXPECT_EQ(list_.Size(), 0);
}

TEST(ListFunctions, MemberConstructor){
    s21::List<int> list_(3);
    EXPECT_FALSE(list_.Empty());
    EXPECT_EQ(list_.Size(), 3);

    for(s21::List<int>::Iterator it = list_.Begin(); it != list_.End(); ++it){
        EXPECT_EQ(*it, 0);
    }
}

TEST(ListFunctions, InitList){
    s21::List<int> list_ = {1,2,3};
    EXPECT_FALSE(list_.Empty());
    EXPECT_EQ(list_.Size(), 3);

    EXPECT_EQ(list_.Front(), 1);
    list_.PopFront();
    EXPECT_EQ(list_.Front(), 2);
    list_.PopFront();
    EXPECT_EQ(list_.Front(), 3);
}

TEST(ListFunctions, CopyConstructor){
    s21::List<int> list_ = {1,2,3};
    s21::List<int> list_1_(list_);

    EXPECT_FALSE(list_1_.Empty());
    EXPECT_EQ(list_1_.Size(), 3);

    EXPECT_EQ(list_1_.Front(), 1);
    list_1_.PopFront();
    EXPECT_EQ(list_1_.Front(), 2);
    list_1_.PopFront();
    EXPECT_EQ(list_1_.Front(), 3); 
}

TEST(ListFunctions, CopyAssigment){
    s21::List<int> list_1_ = {1,2,3};
    s21::List<int> list_2_;

    list_2_ = list_1_;

    EXPECT_EQ(list_1_.Size(), list_2_.Size());

    while (!list_1_.Empty()){
        EXPECT_EQ(list_1_.Front(), list_2_.Front());
        list_1_.PopFront();
        list_2_.PopFront();
    }
}

TEST(ListFunctions, MoveAssigment){
    s21::List<int> list_1_ = {1,2,3};
    s21::List<int> list_2_;

    list_2_ = std::move(list_1_);

    EXPECT_EQ(list_2_.Size(), 3);
    EXPECT_TRUE(list_1_.Empty());

    EXPECT_EQ(list_2_.Front(), 1);
    list_2_.PopFront();
    EXPECT_EQ(list_2_.Front(), 2);
    list_2_.PopFront();
    EXPECT_EQ(list_2_.Front(), 3);
}

TEST(ListFunctions, SelfAssigment){
    s21::List<int> list_1_ = {1,2,3};

    list_1_ = list_1_;

    EXPECT_EQ(list_1_.Front(), 1);
    list_1_.PopFront();
    EXPECT_EQ(list_1_.Front(), 2);
    list_1_.PopFront();
    EXPECT_EQ(list_1_.Front(), 3);
}

TEST(ListEquality, EqualLists) {
    s21::List<int> list_1_ = {1, 2, 3};
    s21::List<int> list_2_ = {1, 2, 3};

    EXPECT_TRUE(list_1_ == list_2_);
}

TEST(ListEquality, DifferentSizes) {
    s21::List<int> list_1_ = {1, 2, 3};
    s21::List<int> list_2_ = {1, 2, 3, 4};

    EXPECT_FALSE(list_1_ == list_2_);
}

TEST(ListEquality, DifferentElements) {
    s21::List<int> list_1_ = {1, 2, 3};
    s21::List<int> list_2_ = {1, 2, 4};

    EXPECT_FALSE(list_1_ == list_2_);
}

TEST(ListEquality, EmptyLists) {
    s21::List<int> list_1_;
    s21::List<int> list_2_;

    EXPECT_TRUE(list_1_ == list_2_);
}

TEST(ListEquality, OneEmptyList) {
    s21::List<int> list_1_ = {1, 2, 3};
    s21::List<int> list_2_;

    EXPECT_FALSE(list_1_ == list_2_);
    EXPECT_FALSE(list_2_ == list_1_);
}

TEST(ListEquality, SelfComparison) {
    s21::List<int> list_1_ = {1, 2, 3};

    EXPECT_TRUE(list_1_ == list_1_);
}

TEST(ListInequality, EqualLists) {
    s21::List<int> list_1_ = {1, 2, 3};
    s21::List<int> list_2_ = {1, 2, 3};

    EXPECT_FALSE(list_1_ != list_2_);
}

TEST(ListInequality, DifferentSizes) {
    s21::List<int> list_1_ = {1, 2, 3};
    s21::List<int> list_2_ = {1, 2, 3, 4};

    EXPECT_TRUE(list_1_ != list_2_);
}

TEST(ListInequality, DifferentElements) {
    s21::List<int> list_1_ = {1, 2, 3};
    s21::List<int> list_2_ = {1, 2, 4};

    EXPECT_TRUE(list_1_ != list_2_);
}

TEST(ListInequality, EmptyLists) {
    s21::List<int> list_1_;
    s21::List<int> list_2_;

    EXPECT_FALSE(list_1_ != list_2_);
}

TEST(ListInequality, OneEmptyList) {
    s21::List<int> list_1_ = {1, 2, 3};
    s21::List<int> list_2_;

    EXPECT_TRUE(list_1_ != list_2_);
    EXPECT_TRUE(list_2_ != list_1_);
}

TEST(ListInequality, SelfComparison) {
    s21::List<int> list_1_ = {1, 2, 3};

    EXPECT_FALSE(list_1_ != list_1_);
}

TEST(ListInequality, ComplexCase) {
    s21::List<int> list_1_ = {10, 20, 30, 40, 50};
    s21::List<int> list_2_ = {10, 20, 30, 40, 50};

    EXPECT_FALSE(list_1_ != list_2_);

    list_2_.PushBack(60);
    EXPECT_TRUE(list_1_ != list_2_);
}

TEST(ListElementAccess, Front){
    s21::List<int> list_ = {1, 2 ,3};
    std::list<int> org_list_ = {1, 2, 3};

    EXPECT_EQ(list_.Front(), org_list_.front());
    list_.PopFront();
    org_list_.pop_front();
    EXPECT_EQ(list_.Front(), org_list_.front());
    list_.PopFront();
    org_list_.pop_front();
}

TEST(ListElementAccess, Back){
    s21::List<int> list_ = {1, 2 ,3};
    std::list<int> org_list_ = {1, 2, 3};

    EXPECT_EQ(list_.Back(), org_list_.back());
    list_.PopBack();
    org_list_.pop_back();
    EXPECT_EQ(list_.Back(), org_list_.back());
    list_.PopBack();
    org_list_.pop_back();
}

TEST(ListIterators, Begin){
    s21::List<int> list_;
    s21::List<int>::Iterator it_empty = list_.Begin();
    EXPECT_EQ(it_empty, list_.End());

    list_.PushBack(10);
    list_.PushBack(20);
    list_.PushBack(30);

    s21::List<int>::Iterator it = list_.Begin();
    EXPECT_EQ(*it, 10);

    ++it;
    EXPECT_EQ(*it, 20);

    ++it;
    EXPECT_EQ(*it, 30);

    ++it;
    EXPECT_EQ(it, list_.End());
}

TEST(ListIterators, EndEmptyList){
    s21::List<int> list_;
    EXPECT_EQ(list_.Begin(), list_.End());
}

TEST(ListIterators, EndNonEmptyList){
    s21::List<int> list_;

    list_.PushBack(10);
    list_.PushBack(20);
    list_.PushBack(30);

    EXPECT_NE(list_.Begin(), list_.End());

    s21::List<int>::Iterator it = list_.Begin();
    EXPECT_EQ(*it, 10);

    ++it;
    EXPECT_EQ(*it, 20);

    ++it;
    EXPECT_EQ(*it, 30);

    ++it;
    EXPECT_EQ(it, list_.End());
}

TEST(ListIterators, EndAfterErasingElements) {
    s21::List<int> test_list = {10, 20, 30};

    while (!test_list.Empty()) {
        test_list.PopBack();
    }

    EXPECT_EQ(test_list.Begin(), test_list.End());
}

TEST(ListCapacity, Empty){
    s21::List<int> list_;
    std::list<int> org_list_;
    EXPECT_EQ(list_.Empty(), org_list_.empty());

    s21::List<int> stack_1_;
    stack_1_.PushBack(7);
    std::list<int> org_stack_1_;
    org_stack_1_.push_back(4);

    EXPECT_EQ(stack_1_.Empty(), org_stack_1_.empty());
}

TEST(ListCapacity, Size){
    s21::List<int> list_;
    std::list<int> org_list_;

    EXPECT_EQ(list_.Size(), org_list_.size());

    s21::List<int> list_1_ = {1, 2, 3};
    std::list<int> org_list_1_ = {1, 2, 3};

    EXPECT_EQ(list_1_.Size(), org_list_1_.size());
}

TEST(ListClear, ClearNonEmptyList) {
    s21::List<int> list = {1, 2, 3, 4, 5};

    EXPECT_EQ(list.Size(), 5);  
    list.Clear();
    EXPECT_TRUE(list.Empty());  
    EXPECT_EQ(list.Size(), 0);  
}

TEST(ListClear, ClearEmptyList) {
    s21::List<int> list;

    EXPECT_TRUE(list.Empty());  
    EXPECT_NO_THROW(list.Clear());
    EXPECT_EQ(list.Size(), 0);  
}

TEST(ListClear, ClearSingleElementList) {
    s21::List<int> list = {42};

    EXPECT_EQ(list.Size(), 1);  
    EXPECT_FALSE(list.Empty()); 
    list.Clear();
    EXPECT_TRUE(list.Empty());  
    EXPECT_EQ(list.Size(), 0);  
}

TEST(ListClear, ClearAndReuseList) {
    s21::List<int> list = {10, 20, 30};

    EXPECT_EQ(list.Size(), 3); 
    list.Clear();
    EXPECT_TRUE(list.Empty()); 
    EXPECT_EQ(list.Size(), 0); 

    list.PushBack(100);        
    EXPECT_FALSE(list.Empty()); 
    EXPECT_EQ(list.Size(), 1);  
    EXPECT_EQ(list.Front(), 100); 
}

TEST(ListClear, ClearLargeList) {
    s21::List<int> list;

    for (int i = 0; i < 1000; ++i) {
        list.PushBack(i);
    }
    EXPECT_EQ(list.Size(), 1000); 

    list.Clear();
    EXPECT_TRUE(list.Empty());    
    EXPECT_EQ(list.Size(), 0);    
}

TEST(ListClear, ClearTwice) {
    s21::List<int> list = {1, 2, 3};

    list.Clear();
    EXPECT_TRUE(list.Empty());  
    EXPECT_EQ(list.Size(), 0);  
    list.Clear();
    EXPECT_TRUE(list.Empty());  
    EXPECT_EQ(list.Size(), 0);  
}

TEST(ListInsert, InsertAtBegin) {
    s21::List<int> list_ = {10, 20, 30};
    auto it = list_.Begin();

    list_.Insert(it, 5);

    it = list_.Begin();
    EXPECT_EQ(*it, 5); 
    ++it;
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
}

TEST(ListInsert, InsertInMiddle) {
    s21::List<int> list_ = {10, 20, 30};
    s21::List<int>::Iterator it = list_.Begin();
    ++it;

    list_.Insert(it, 15);

    it = list_.Begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 15);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
}

TEST(ListInsert, InsertAtEnd) {
    s21::List<int> list_ = {10, 20, 30};
    auto it = list_.End();

    list_.Insert(it, 35);

    it = list_.Begin();
    EXPECT_EQ(*it, 10);  
    ++it;
    EXPECT_EQ(*it, 20);  
    ++it;
    EXPECT_EQ(*it, 30);  
    ++it;
    EXPECT_EQ(*it, 35);  
}

TEST(ListInsert, InsertIntoEmptyList) {
    s21::List<int> list_;
    auto it = list_.Begin();

    list_.Insert(it, 42);

    it = list_.Begin();
    EXPECT_EQ(*it, 42);
    ++it;
    EXPECT_EQ(it, list_.End());
}

TEST(ListInsert, InsertMultipleTimes) {
    s21::List<int> list_ = {10, 20, 30};
    auto it = list_.Begin();
    ++it; 

    list_.Insert(it, 15);
    list_.Insert(it, 17);

    it = list_.Begin();
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
    s21::List<int> list_ = {10, 20, 30};
    auto it = list_.Begin();
    ++it;

    auto returned_it = list_.Insert(it, 15);

    EXPECT_EQ(*returned_it, 15);
    --returned_it; 
    EXPECT_EQ(*returned_it, 10);
}

TEST(ListErase, EraseFirst){
    s21::List<int> list_ = {10, 20, 30};
    s21::List<int>::Iterator it = list_.Begin();

    list_.Erase(it);

    std::list<int> org_list_ = {10, 20, 30};
    auto org_it = org_list_.begin();

    org_list_.erase(org_it);

    it = list_.Begin();
    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(ListErase, Erase){
    s21::List<int> list_ = {10, 20, 30, 66};
    s21::List<int>::Iterator it = list_.Begin();
    ++it;
    ++it;

    list_.Erase(it);

    std::list<int> org_list_ = {10, 20, 30, 66};
    auto org_it = org_list_.begin();
    ++org_it;
    ++org_it;

    org_list_.erase(org_it);

    it = list_.Begin();
    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(ListErase, EraseAtEnd) {
    s21::List<int> list_ = {10, 20, 30, 40};
    s21::List<int>::Iterator it = list_.Begin();
    ++it;
    ++it;
    ++it;
    list_.Erase(it);

    std::list<int> org_list_ = {10, 20, 30, 40};
    auto org_it = org_list_.begin();
    ++org_it;
    ++org_it;
    ++org_it;
    org_list_.erase(org_it);

    it = list_.Begin();
    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(List, PushBack){
    s21::List<int> list_;
    std::list<int> org_list_;

    list_.PushBack(5);
    org_list_.push_back(5);

    EXPECT_EQ(list_.Back(), org_list_.back());
    EXPECT_EQ(list_.Size(), org_list_.size());

    list_.PushBack(8);
    org_list_.push_back(8);

    EXPECT_EQ(list_.Back(), org_list_.back());
    EXPECT_EQ(list_.Size(), org_list_.size());

}

TEST(List, PopBack){
    s21::List<int> list_ = {3, 6, 9};
    std::list<int> org_list_ = {3, 6, 9};

    list_.PopBack();
    org_list_.pop_back();

    EXPECT_EQ(list_.Back(), org_list_.back());
    EXPECT_EQ(list_.Size(), org_list_.size());

    list_.PopBack();
    org_list_.pop_back();

    EXPECT_EQ(list_.Back(), org_list_.back());
    EXPECT_EQ(list_.Size(), org_list_.size());
}

TEST(List, PopBackEmptyList){
    s21::List<int> list_;
    list_.PopBack();

    EXPECT_EQ(list_.Size(), 0);
}

TEST(List, PushFront){
    s21::List<int> list_;
    std::list<int> org_list_;

    list_.PushFront(5);
    org_list_.push_front(5);

    EXPECT_EQ(list_.Front(), org_list_.front());
    EXPECT_EQ(list_.Size(), org_list_.size());

    list_.PushFront(8);
    org_list_.push_front(8);

    EXPECT_EQ(list_.Front(), org_list_.front());
    EXPECT_EQ(list_.Size(), org_list_.size());
}

TEST(List, PopFront){
    s21::List<int> list_ = {3, 6, 9};
    std::list<int> org_list_ = {3, 6, 9};

    list_.PopFront();
    org_list_.pop_front();

    EXPECT_EQ(list_.Front(), org_list_.front());
    EXPECT_EQ(list_.Size(), org_list_.size());

    list_.PopFront();
    org_list_.pop_front();

    EXPECT_EQ(list_.Back(), org_list_.back());
    EXPECT_EQ(list_.Size(), org_list_.size());
}

TEST(List, PopFrontEmptyList){
    s21::List<int> list_;
    list_.PopFront();

    EXPECT_EQ(list_.Size(), 0);
}

TEST(List, Swap){
    s21::List<int> list_ = {3,5,7};
    s21::List<int> list_2_ = {6,8,10};

    list_.Swap(list_2_);

    EXPECT_EQ(list_.Front(), 6);
    EXPECT_EQ(list_2_.Front(), 3);
    EXPECT_EQ(list_2_.Size(), list_.Size());

    list_.PopFront();
    list_2_.PopFront();

    EXPECT_EQ(list_.Front(), 8);
    EXPECT_EQ(list_2_.Front(), 5);
    EXPECT_EQ(list_2_.Size(), list_.Size());
}

TEST(ListMerge, Merge){
    s21::List<int> list_1_ = {1, 5, 8, 9};
    s21::List<int> list_2_ = {2, 3, 6, 7};

    list_1_.Merge(list_2_);

    std::list<int> org_list_ = {1, 5, 8, 9};
    std::list<int> org_list_1_ = {2, 3, 6, 7};

    org_list_.merge(org_list_1_);

    s21::List<int>::Iterator it = list_1_.Begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }

}

TEST(ListMerge, MergeEmpty){
    s21::List<int> list_1_;
    s21::List<int> list_2_ = {2, 3, 6, 7};

    list_1_.Merge(list_2_);
    EXPECT_EQ(list_2_.Size(), 0);

    std::list<int> org_list_;
    std::list<int> org_list_1_ = {2, 3, 6, 7};;

    org_list_.merge(org_list_1_);

    s21::List<int>::Iterator it = list_1_.Begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }

}

TEST(ListMerge, MergeInEmpty){
    s21::List<int> list_1_ = {1, 5, 8, 9};
    s21::List<int> list_2_;

    list_1_.Merge(list_2_);
    EXPECT_EQ(list_2_.Size(), 0);

    std::list<int> org_list_ = {1, 5, 8, 9};
    std::list<int> org_list_1_;

    org_list_.merge(org_list_1_);

    s21::List<int>::Iterator it = list_1_.Begin();
    auto org_it = org_list_.begin();

    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }

}

TEST(ListSplice, SpliceEmptyList){
    s21::List<int> list_ = {1,2,3};;
    s21::List<int> list_1;

    s21::List<int>::Iterator it = list_.Begin();
    list_.Splice(it, list_1);


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
    s21::List<int> list_;
    s21::List<int> list_1 = {1,2,3};

    s21::List<int>::Iterator it = list_.Begin();
    list_.Splice(it, list_1);

    EXPECT_TRUE(list_1.Empty());
    EXPECT_EQ(list_.Size(), 3);

    std::list<int> org_list_;
    std::list<int> org_list_1 = {1,2,3};

    auto org_it = org_list_.begin();
    org_list_.splice(org_it, org_list_1);

    it = list_.Begin();
    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }

    EXPECT_TRUE(list_1.Empty());
}

TEST(ListSplice, Splice){
    s21::List<int> list_ = {32,45,10,11};
    s21::List<int> list_1 = {9,1,2};

    s21::List<int>::Iterator it = list_.Begin();
    ++it;
    ++it;
    list_.Splice(it, list_1);


    std::list<int> org_list_ = {32,45,10,11};;
    std::list<int> org_list_1 = {9,1,2};

    auto org_it = org_list_.begin();
    ++org_it;
    ++org_it;
    org_list_.splice(org_it, org_list_1);

    it = list_.Begin();
    for(org_it = org_list_.begin(); org_it != org_list_.end(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(ListSplice, SpliceInEnd){
    s21::List<int> list_ = {32,45,10,11};
    s21::List<int> list_1 = {9,1,2};

    s21::List<int>::Iterator it = list_.Begin();
    ++it;
    ++it;
    ++it;
    list_.Splice(it, list_1);


    std::list<int> org_list_ = {32,45,10,11};;
    std::list<int> org_list_1 = {9,1,2};

    auto org_it = org_list_.Begin();
    ++org_it;
    ++org_it;
    ++org_it;
    org_list_.splice(org_it, org_list_1);

    it = list_.Begin();
    for(org_it = org_list_.Begin(); org_it != org_list_.End(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(ListSplice, SpliceInBegin){
    s21::list<int> list_ = {32,45,10,11};
    s21::list<int> list_1 = {9,1,2};

    s21::list<int>::Iterator it = list_.Begin();
    list_.splice(it, list_1);


    std::list<int> org_list_ = {32,45,10,11};;
    std::list<int> org_list_1 = {9,1,2};

    auto org_it = org_list_.Begin();
    org_list_.splice(org_it, org_list_1);

    it = list_.Begin();
    for(org_it = org_list_.Begin(); org_it != org_list_.End(); ++org_it){
        EXPECT_EQ(*org_it, *it);
        ++it;
    }
}

TEST(List, Reverse){
    s21::list<int> list_ = {10, 20, 30, 55, 98};
    list_.reverse();

    std::list<int> org_list_ = {10, 20, 30, 55, 98};
    org_list_.reverse();

    s21::list<int>::Iterator it = list_.Begin();
    auto org_it = org_list_.Begin();

    for(org_it = org_list_.Begin(); org_it != org_list_.End(); ++org_it){
        EXPECT_EQ(*org_it, *it);
    ++it;
    }
}

TEST(ListUnique, Unique){
    s21::list<int> list_ = {3, 4, 6, 8, 8, 9, 4, 4, 9};
    list_.unique();

    std::list<int> org_list_ = {3, 4, 6, 8, 8, 9, 4, 4, 9};
    org_list_.unique();

    s21::list<int>::Iterator it = list_.Begin();
    auto org_it = org_list_.Begin();

    for(org_it = org_list_.Begin(); org_it != org_list_.End(); ++org_it){
        EXPECT_EQ(*org_it, *it);
    ++it;
    }
}

TEST(ListUnique, UniqueNoDubl){
    s21::list<int> list_ = {10, 20, 30, 55, 78};
    list_.unique();

    std::list<int> org_list_ = {10, 20, 30, 55, 78};
    org_list_.unique();

    s21::list<int>::Iterator it = list_.Begin();
    auto org_it = org_list_.Begin();

    for(org_it = org_list_.Begin(); org_it != org_list_.End(); ++org_it){
        EXPECT_EQ(*org_it, *it);
    ++it;
    }
}

TEST(List, Sort){
    s21::list<int> list_ = {8, 3, 9, 2, 5, 1, 1, 10};
    list_.unique();

    std::list<int> org_list_ = {8, 3, 9, 2, 5, 1, 1, 10};
    org_list_.unique();

    s21::list<int>::Iterator it = list_.Begin();
    auto org_it = org_list_.Begin();

    for(org_it = org_list_.Begin(); org_it != org_list_.End(); ++org_it){
        EXPECT_EQ(*org_it, *it);
    ++it;
    }
}
