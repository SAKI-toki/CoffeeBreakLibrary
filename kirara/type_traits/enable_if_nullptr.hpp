/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef KIRARA_TYPE_TRAITS_ENABLE_IF_NULLPTR_HPP
#define KIRARA_TYPE_TRAITS_ENABLE_IF_NULLPTR_HPP
#include <kirara/config.hpp>

KIRARA_NAMESPACE_BEGIN

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

KIRARA_NAMESPACE_END

#endif // KIRARA_TYPE_TRAITS_ENABLE_IF_NULLPTR_HPP