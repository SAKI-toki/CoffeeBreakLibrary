/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_CONTAINER_ARRAY_HPP
#define COFFEE_BREAK_STD_CONTAINER_ARRAY_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/common/enable_if_nullptr.hpp>
#include <type_traits>
#include <array>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{
  template <typename>
  struct is_array : STD_NSS::false_type
  {
  };
  template <typename T, std::size_t Size>
  struct is_array<std::array<T, Size>> : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_array_v =
      COFFEE_BREAK_NSS::details::is_array<T>::value;

} // namespace details

template <typename... Types>
using this_is_array = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_array<Types>...>>;
template <typename... Types>
using this_is_not_array = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_array<Types>...>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_CONTAINER_ARRAY_HPP