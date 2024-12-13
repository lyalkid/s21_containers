#include <iostream>
#include <set>

#include "multiset.h"

int main() {
  std::multiset<int> std_a;
  s21::multiset<int> a;

  std_a.insert({5, 0});
  std_a.insert({3, 0});
  std_a.insert({7, 0});
  std_a.insert({1, 0});
  std_a.insert({8, 0});
  s21::set<char> my_set = {'x', 'b', 'z', 'y'};
  std::set<char> orig_set = {'x', 'b', 'z', 'y'};
  // std_a.begin();
  my_set.find('x');
  my_set.insert('p');
  // std::cout << a.empty() << "ksk"<< std::endl;
  //  a.insert(7);

  return 0;
}
