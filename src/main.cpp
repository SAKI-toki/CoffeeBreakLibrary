#include <coffee_break/operator.hpp>
#include <coffee_break/pi.hpp>
#include <coffee_break/size.hpp>
#include <coffee_break/std.hpp>
#include <iostream>

int main()
{
    [[maybe_unused]] coffee_break::this_is_array<std::array<int, 2>, std::array<double, 0>> n = nullptr;
    return 0;
}