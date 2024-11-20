#include <iostream>
#include <list>

int main(){
//    std::list<int> mylist = {10, 11, 12, 13};
//
//    std::list<int>::iterator it = mylist.begin();
//    ++it;
//    ++it;
//    ++it;
//    ++it;
//    ++it;
//    std::cout << *it << std::endl;

    std::list<int> mylist_2 = {3, 4, 5, 6};
    std::list<int>::iterator it = mylist_2.end();
    --it;
    --it;
    --it;
    --it;
    --it;
    --it;

    std::cout << *it << std::endl;
    return 0;
}

