#include <coffee_break/operator.hpp>
#include <coffee_break/pi.hpp>
#include <coffee_break/size.hpp>
#include <coffee_break/std.hpp>

#include <iostream>

template <typename... Types,
          COFFEE_BREAK_NSS::outputabled<Types...> = nullptr>
void output(Types... args)
{
  (std::cout << ... << args) << std::endl;
}

struct X
{
};

std::ostream &operator<<(std::ostream &os, X)
{
  os << 123;
  return os;
}

int main()
{
  output(1, 'a', "defq", 1.3, 1.1f, X{});
  return 0;
}