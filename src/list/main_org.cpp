 #include <iostream>
 #include <list>
#include <limits>

 int main(){

          std::list<int> org_list_;
          std::list<int> org_list_1 = {1,2,3};

          auto org_it = org_list_.begin();
          org_list_.splice(org_it, org_list_1);

     for(auto it = org_list_.begin(); it != org_list_.end(); ++it){
         std::cout << *it << " ";
     }
 }