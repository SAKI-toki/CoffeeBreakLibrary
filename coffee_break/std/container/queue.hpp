/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_CONTAINER_QUEUE_HPP
#define COFFEE_BREAK_STD_CONTAINER_QUEUE_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/common/enable_if_nullptr.hpp>
#include <type_traits>
#include <queue>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{

  // queue
  template <typename>
  struct is_queue : STD_NSS::false_type
  {
  };
  template <typename T, typename ContainerType>
  struct is_queue<std::queue<T, ContainerType>> : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_queue_v =
      COFFEE_BREAK_NSS::details::is_queue<T>::value;

  // priority_queue
  template <typename>
  struct is_priority_queue : STD_NSS::false_type
  {
  };
  template <typename T, typename ContainerType, typename CompareType>
  struct is_priority_queue<std::priority_queue<T, ContainerType, CompareType>>
      : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_priority_queue_v =
      COFFEE_BREAK_NSS::details::is_priority_queue<T>::value;

} // namespace details

// queue
template <typename... Types>
using this_is_queue = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_queue<Types>...>>;
template <typename... Types>
using this_is_not_queue = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_queue<Types>...>>;

// priority_queue
template <typename... Types>
using this_is_priority_queue =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_priority_queue<Types>...>>;
template <typename... Types>
using this_is_not_priority_queue =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_priority_queue<Types>...>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_CONTAINER_QUEUE_HPP