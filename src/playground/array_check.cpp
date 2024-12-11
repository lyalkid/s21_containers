

#include <array>
#include <iostream>


#define PRINT(Expression) \
  std::cout << "{" #Expression "}: " << (Expression) << \
    std::endl;


int main() {
  std::array<int, 5> arr = {1, 2, 3};
  std::array<int, 5> arr1(arr);

  std::array<double, 7> const DoubleArr = {1.1, 2.2, 3.0};
  std::array<double, 7> DoubleCopy(std::move(DoubleArr));

  int size_darr, size_copy;

  size_darr = DoubleArr.size();
  size_copy = DoubleCopy.size();

  size_t max_size_darr = DoubleArr.max_size();
  size_t max_size_copy = DoubleCopy.size();

  PRINT(size_darr);
  PRINT(size_copy);

  PRINT(max_size_darr);
  PRINT(max_size_copy);


  PRINT(DoubleArr[1]);
  PRINT(DoubleCopy[1]);


  PRINT(arr[0]);
  PRINT(arr1[0]);
  return 0;
}