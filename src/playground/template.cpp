#include <iostream>

#define PRINT(Expression) \
  std::cout << "{" #Expression "}: " << (Expression) << \
    std::endl;

template<typename Type>
Type max(Type a, Type b)
{
	return (a >= b ? a : b);
}

int main()
{
  // Использование шаблона "max<Type>(Type, Type)" с подстановкой "int"
	const int a = 3, b = 2, c = 1;
	const int abMax = max<int>(a, b);
	const int max1 = max<int>(abMax, c);

  // Использование того же шаблона max<Type>(Type, Type) с подстановкой "char"  
	const char aChar = 3, bChar = 2, cChar = 1;
	const char abMaxChar = max<char>(aChar, bChar);
	const char maxChar = max<char>(abMaxChar, cChar);  

  PRINT(max1);
  PRINT(abMax);
  PRINT(maxChar);
  PRINT(abMaxChar);
  
	return 0;
}