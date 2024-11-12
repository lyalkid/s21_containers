

#include <array>
#include <iostream>


#define PRINT(Expression) \
  std::cout << "{" #Expression "}: " << (Expression) << \
    std::endl;


int main() {
  std::array<int, 3> arr = {1, 2, 3};
  std::array<int, 3> arr1(arr);

  std::array<double, 3> const DoubleArr = {1.1, 2.2, 3.0};
  std::array<double, 3> DoubleCopy(std::move(DoubleArr));

  int size_darr, size_copy;

  size_darr = DoubleArr.size();
  size_copy = DoubleCopy.size();

  PRINT(size_darr);
  PRINT(size_copy);


  PRINT(DoubleArr[1]);
  PRINT(DoubleCopy[1]);


  PRINT(arr[0]);
  PRINT(arr1[0]);
  return 0;
}