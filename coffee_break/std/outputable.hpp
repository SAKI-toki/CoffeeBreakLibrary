/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_OUTPUTABLE_HPP
#define COFFEE_BREAK_STD_OUTPUTABLE_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/common/enable_if_nullptr.hpp>
#include <type_traits>
#include <ostream>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{
template <typename T>
class outputable
{
  template <typename U,
            COFFEE_BREAK_NSS::enable_if_nullptr_t<
                STD_NSS::is_same_v<STD_NSS::ostream &,
                                   decltype(STD_NSS::declval<STD_NSS::ostream &>() << STD_NSS::declval<U>())>> = nullptr>
  static constexpr STD_NSS::true_type check(decltype(nullptr));
  template <typename U>
  static constexpr STD_NSS::false_type check(...);

public:
  static constexpr bool value = decltype(check<T>(nullptr))::value;
};
template <typename T>
inline constexpr bool outputable_v =
    COFFEE_BREAK_NSS::details::outputable<T>::value;
} // namespace details

template <typename... Types>
using outputabled = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::outputable<Types>...>>;
template <typename... Types>
using not_outputabled = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::outputable<Types>...>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_OUTPUTABLE_HPP