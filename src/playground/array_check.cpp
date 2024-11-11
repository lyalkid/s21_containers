

#include <array>
#include <iostream>


#define PRINT(Expression) \
  std::cout << "{" #Expression "}: " << (Expression) << \
    std::endl;


int main() {
  std::array<int, 3> arr = {1, 2, 3};
  std::array<int, 3> arr1(arr);

  PRINT(arr[0]);
  PRINT(arr1[0]);
  return 0;
}