

#include <array>
#include <iostream>


#define PRINT(Expression) \
  std::cout << "{" #Expression "}: " << (Expression) << \
    std::endl;


int main() {
  std::array<int, 2094099> arr;
  PRINT(arr[0]);
  return 0;
}