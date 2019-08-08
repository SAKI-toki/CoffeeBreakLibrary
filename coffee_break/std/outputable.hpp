/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_OUTPUTABLE_HPP
#define COFFEE_BREAK_STD_OUTPUTABLE_HPP
#include <coffee_break/config.hpp>

#include <type_traits>
#include <coffee_break/common/enable_if_nullptr.hpp>
#include <ostream>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{
  template <typename T>
  class outputable
  {
    template <typename U>
    static constexpr STD_NSS::true_type check(
        decltype(STD_NSS::declval<STD_NSS::ostream&>() << STD_NSS::declval<U>(),
                 nullptr));
    template <typename U>
    static constexpr STD_NSS::false_type check(...);

  public:
    static constexpr bool value = decltype(check<T>(nullptr))::value;
  };
  template <typename T>
  inline constexpr bool outputable_v =
      COFFEE_BREAK_NSS::details::outputable<T>::value;
} // namespace details
template <typename T>
using outputabled = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    COFFEE_BREAK_NSS::details::outputable_v<T>>;
template <typename T>
using not_outputabled = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !COFFEE_BREAK_NSS::details::outputable_v<T>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_OUTPUTABLE_HPP