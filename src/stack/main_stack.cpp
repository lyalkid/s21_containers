//#include "stack.h"
#include <iostream>
#include <stack>


int main(){

    std::stack<int> mystack_;
    mystack_.push(5);
    std::cout << mystack_.top();


    return 0;
}

