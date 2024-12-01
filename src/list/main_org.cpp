 #include <iostream>
 #include <list>
#include <limits>

 int main(){
     std::list<int> mylist_ ;
     std::list<int> mylist_2 = {11, 8, 63, 1};

     auto it = mylist_.begin();
     ++it;
     ++it;

     mylist_.splice(it, mylist_2);

     for(auto it = mylist_.begin(); it != mylist_.end(); ++it){
         std::cout << *it << " ";
     }
 }