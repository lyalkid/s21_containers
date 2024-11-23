 #include <iostream>
 #include <list>

 int main(){
     std::list<int> mylist_ = {4, 1, 2, 87, 3, 10};

     auto it = mylist_.begin();
     ++it;
     ++it;
     mylist_.erase(it);

     for(auto it = mylist_.begin(); it != mylist_.end(); ++it){
         std::cout << *it << " ";
     }
 }