/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef KIRARA_TYPE_TRAITS_OPERATOR_OUTPUTABLE_HPP
#define KIRARA_TYPE_TRAITS_OPERATOR_OUTPUTABLE_HPP
#include <kirara/config.hpp>

#include <type_traits>
#include <kirara/type_traits/enable_if_nullptr.hpp>
#include <iostream>

KIRARA_NAMESPACE_BEGIN

namespace details
{
template <typename T>
class outputable
{
  template <typename U>
  static constexpr STD_NSS::true_type check(
      decltype(STD_NSS::declval<STD_NSS::ostream &>() << STD_NSS::declval<U>(), nullptr));
  template <typename U>
  static constexpr STD_NSS::false_type check(...);

public:
  static constexpr bool value = decltype(check<T>(nullptr))::value;
};
template <typename T>
inline constexpr bool outputable_v = KIRARA_NSS::details::outputable<T>::value;
} // namespace details
template <typename T>
using outputabled = KIRARA_NSS::enable_if_nullptr_t<KIRARA_NSS::details::outputable_v<T>>;

KIRARA_NAMESPACE_END

#endif // KIRARA_TYPE_TRAITS_OPERATOR_OUTPUTABLE_HPP