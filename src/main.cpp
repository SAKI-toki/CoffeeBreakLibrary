#include <coffee_break/operator.hpp>
#include <coffee_break/pi.hpp>
#include <coffee_break/size.hpp>
#include <coffee_break/std.hpp>
#include <iostream>

template <typename T, coffee_break::same_addabled<T> = nullptr>
T f(T x) { return x + x; }

int main()
{
    int n;
    std::cin >> n;
    std::cout << f(n);
    return 0;
}