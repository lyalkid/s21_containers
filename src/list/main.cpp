#include <iostream>
// #include <list>

#include "list.h"

int main() {
    s21::List<int> list_;
    s21::List<int> list_1 = {1,2,3};

    s21::List<int>::Iterator it = list_.Begin();
    list_.Splice(it, list_1);

  for (it = list_.Begin(); it != list_.End();
       ++it) {
    std::cout << *it << " ";
  }
}

