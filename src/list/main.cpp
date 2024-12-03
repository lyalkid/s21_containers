#include <iostream>
// #include <list>

#include "list.h"

int main() {
    s21::list<int> list_;
    s21::list<int> list_1 = {1,2,3};

    s21::list<int>::iterator it = list_.begin();
    list_.splice(it, list_1);

  for (it = list_.begin(); it != list_.end();
       ++it) {
    std::cout << *it << " ";
  }
}

