#include "multiset.h"
#include <set>
#include <iostream>



int main(){
    std::multiset<int> std_a;
  s21::multiset<int> a;

  std_a.insert({5, 0});
  std_a.insert({3, 0});
  std_a.insert({7, 0});
  std_a.insert({1, 0});
  std_a.insert({8, 0});
    return 0;
}