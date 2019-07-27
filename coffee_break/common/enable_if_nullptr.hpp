/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_COMMON_ENABLE_IF_NULLPTR_HPP
#define COFFEE_BREAK_COMMON_ENABLE_IF_NULLPTR_HPP
#include <coffee_break/config.hpp>

COFFEE_BREAK_NAMESPACE_BEGIN

template <bool>
struct enable_if_nullptr
{
};

template <>
struct enable_if_nullptr<true>
{
  using type = decltype(nullptr);
};

template <bool Cond>
using enable_if_nullptr_t = typename enable_if_nullptr<Cond>::type;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_COMMON_ENABLE_IF_NULLPTR_HPP