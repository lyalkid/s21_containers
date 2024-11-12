#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

//возвращает итаратор на след элемент после добавления в массиве 2
/*
template< class ForwardIt1, class ForwardIt2 >
ForwardIt2 swap_ranges( ForwardIt1 first1, ForwardIt1 last1,
                        ForwardIt2 first2 );*/

auto print = [](auto comment, auto const& seq)
{
  std::cout << comment;
  for (const auto& e : seq)
    std::cout << e << ' ';
  std::cout << '\n';
};

int main()
{
  std::vector<char> v{'a', 'b', 'c', 'd', 'e'};
  std::list<char> l{'1', '2', '3', '4', '5'};

  print("Before swap_ranges:\n" "v: ", v);
  print("l: ", l);

  auto result = std::swap_ranges(v.begin(), v.begin() + v.size(), l.begin());

  std::cout << "Result: " << static_cast<char>(*result)<< std::endl;
  print("After swap_ranges:\n" "v: ", v);
  print("l: ", l);
}