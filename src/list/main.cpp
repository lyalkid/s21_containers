#include <iostream>
#include <list>

//#include "list.h"

int main(){
    std::list<int> mylist_ = {1, 6, 10, 12};
    std::list<int> mylist_2 = {2, 4, 12, 38};

    mylist_2.merge(mylist_);

    for(std::list<int>::iterator it = mylist_.begin(); it != mylist_.end(); ++it){
        std::cout << *it << " ";
    }

    return 0;
}

