/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_PI_HPP
#define COFFEE_BREAK_PI_HPP
#include <coffee_break/config.hpp>

#include <type_traits>
#include <coffee_break/common/enable_if_nullptr.hpp>

COFFEE_BREAK_NAMESPACE_BEGIN

template <typename T,
          COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::is_arithmetic_v<T>> = nullptr>
inline constexpr T pi = static_cast<T>(3.14159265358979323846);

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_PI_HPP