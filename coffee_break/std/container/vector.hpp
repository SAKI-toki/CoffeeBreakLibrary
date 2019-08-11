/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_CONTAINER_VECTOR_HPP
#define COFFEE_BREAK_STD_CONTAINER_VECTOR_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/common/enable_if_nullptr.hpp>
#include <type_traits>
#include <vector>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{
template <typename>
struct is_vector : STD_NSS::false_type
{
};
template <typename T, typename AllocType>
struct is_vector<STD_NSS::vector<T, AllocType>> : STD_NSS::true_type
{
};

template <typename T>
inline constexpr bool is_vector_v =
    COFFEE_BREAK_NSS::details::is_vector<T>::value;

} // namespace details

template <typename... Types>
using this_is_vector = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_vector<Types>...>>;
template <typename... Types>
using this_is_not_vector = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_vector<Types>...>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_CONTAINER_VECTOR_HPP