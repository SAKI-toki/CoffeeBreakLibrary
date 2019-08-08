#include <coffee_break/operator.hpp>
#include <coffee_break/pi.hpp>
#include <coffee_break/size.hpp>
#include <coffee_break/std.hpp>

#include <iostream>

template <typename T, coffee_break::this_is_set<T> = nullptr>
void f(T)
{
  std::cout << "this is set" << std::endl;
}

template <typename T, coffee_break::this_is_not_set<T> = nullptr>
void f(T)
{
  std::cout << "this is not set" << std::endl;
}

int main()
{
  // abc
  int* p;
  f(10);
  f(std::set<int>{});
  return 0;
}