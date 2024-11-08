#include <iostream>

#define PRINT(Expression) \
  std::cout << "{" #Expression "}: " << (Expression) << std::endl;

int main() {
  int arrayValue[]{1, 2, 3, 4};
  PRINT(arrayValue[1] + arrayValue[2]);
}