/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_CONTAINER_DEQUE_HPP
#define COFFEE_BREAK_STD_CONTAINER_DEQUE_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/common/enable_if_nullptr.hpp>
#include <type_traits>
#include <deque>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{
template <typename>
struct is_deque : STD_NSS::false_type
{
};
template <typename T, typename AllocType>
struct is_deque<std::deque<T, AllocType>> : STD_NSS::true_type
{
};

template <typename T>
inline constexpr bool is_deque_v = COFFEE_BREAK_NSS::details::is_deque<T>::value;

} // namespace details

template <typename... Types>
using this_is_deque = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_deque<Types>...>>;
template <typename... Types>
using this_is_not_deque = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_deque<Types>...>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_CONTAINER_DEQUE_HPP