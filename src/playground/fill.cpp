#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>
/*
template< class ForwardIt, class T = typename std::iterator_traits
                                         <ForwardIt>::value_type >
constexpr void fill( ForwardIt first, ForwardIt last,
                     const T& value );
*/

 //void
 
void println(const auto& seq)
{
    for (const auto& e : seq)
        std::cout << e << ' ';
    std::cout << '\n';
}
 
int main()
{
  std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8};
  println(v);

  // set all of the elements to 8
  std::fill(v.begin(), v.end(), 8);
  println(v);

  std::vector<std::complex<double>> nums{{1, 3}, {2, 2}, {4, 8}};
  println(nums);
  #ifdef __cpp_lib_algorithm_default_value_type
      std::fill(nums.begin(), nums.end(), {4, 2});
  #else
      std::fill(nums.begin(), nums.end(), std::complex<double>{4, 2});
  #endif
  println(nums);
}