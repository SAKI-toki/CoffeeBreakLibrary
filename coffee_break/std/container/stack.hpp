/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_CONTAINER_STACK_HPP
#define COFFEE_BREAK_STD_CONTAINER_STACK_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/common/enable_if_nullptr.hpp>
#include <type_traits>
#include <stack>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{
  template <typename>
  struct is_stack : STD_NSS::false_type
  {
  };
  template <typename T, typename ContainerType>
  struct is_stack<std::stack<T, ContainerType>> : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_stack_v = COFFEE_BREAK_NSS::details::is_stack<T>::value;

} // namespace details

template <typename... Types>
using this_is_stack = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_stack<Types>...>>;
template <typename... Types>
using this_is_not_stack = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_stack<Types>...>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_CONTAINER_STACK_HPP