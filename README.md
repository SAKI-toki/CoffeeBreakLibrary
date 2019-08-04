# CoffeeBreakLibrary
メタプログラミングの共通部(addableなど)

## 環境
C++17以上でのみ使用可能

## 使用例
~~~
#include <coffee_break/operator.hpp>

template <typename T,
          coffee_break::outputabled<T> = nullptr>
void output(T x)
{
    std::cout << x;
}
~~~



