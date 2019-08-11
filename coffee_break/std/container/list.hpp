/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_CONTAINER_LIST_HPP
#define COFFEE_BREAK_STD_CONTAINER_LIST_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/common/enable_if_nullptr.hpp>
#include <type_traits>
#include <list>
#include <forward_list>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{

// list
template <typename>
struct is_list : STD_NSS::false_type
{
};
template <typename T, typename AllocType>
struct is_list<STD_NSS::list<T, AllocType>> : STD_NSS::true_type
{
};

template <typename T>
inline constexpr bool is_list_v =
    COFFEE_BREAK_NSS::details::is_list<T>::value;

// forward_list
template <typename>
struct is_forward_list : STD_NSS::false_type
{
};
template <typename T, typename AllocType>
struct is_forward_list<STD_NSS::forward_list<T, AllocType>>
    : STD_NSS::true_type
{
};

template <typename T>
inline constexpr bool is_forward_list_v =
    COFFEE_BREAK_NSS::details::is_forward_list<T>::value;

} // namespace details

// list
template <typename... Types>
using this_is_list = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_list<Types>...>>;
template <typename... Types>
using this_is_not_list = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_list<Types>...>>;

// forward_list
template <typename... Types>
using this_is_forward_list =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_forward_list<Types>...>>;
template <typename... Types>
using this_is_not_forward_list =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_forward_list<Types>...>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_CONTAINER_LIST_HPP