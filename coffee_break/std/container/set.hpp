/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_CONTAINER_SET_HPP
#define COFFEE_BREAK_STD_CONTAINER_SET_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/common/enable_if_nullptr.hpp>
#include <type_traits>
#include <set>
#include <unordered_set>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{

  // set
  template <typename>
  struct is_set : STD_NSS::false_type
  {
  };
  template <typename KeyType, typename CompareType, typename AllocType>
  struct is_set<std::set<KeyType, CompareType, AllocType>> : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_set_v = COFFEE_BREAK_NSS::details::is_set<T>::value;

  // multiset
  template <typename>
  struct is_multiset : STD_NSS::false_type
  {
  };
  template <typename KeyType, typename CompareType, typename AllocType>
  struct is_multiset<std::multiset<KeyType, CompareType, AllocType>>
      : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_multiset_v =
      COFFEE_BREAK_NSS::details::is_multiset<T>::value;

  // unordered_set
  template <typename>
  struct is_unordered_set : STD_NSS::false_type
  {
  };
  template <typename KeyType, typename HashType, typename PredType,
            typename AllocType>
  struct is_unordered_set<
      std::unordered_set<KeyType, HashType, PredType, AllocType>>
      : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_unordered_set_v =
      COFFEE_BREAK_NSS::details::is_unordered_set<T>::value;

  // unordered_multiset
  template <typename>
  struct is_unordered_multiset : STD_NSS::false_type
  {
  };
  template <typename KeyType, typename HashType, typename PredType,
            typename AllocType>
  struct is_unordered_multiset<
      std::unordered_multiset<KeyType, HashType, PredType, AllocType>>
      : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_unordered_multiset_v =
      COFFEE_BREAK_NSS::details::is_unordered_multiset<T>::value;

} // namespace details

// set
template <typename... Types>
using this_is_set = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_set<Types>...>>;
template <typename... Types>
using this_is_not_set = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_set<Types>...>>;

// multiset
template <typename... Types>
using this_is_multiset = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_multiset<Types>...>>;
template <typename... Types>
using this_is_not_multiset = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_multiset<Types>...>>;

// unordered_set
template <typename... Types>
using this_is_unordered_set =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_unordered_set<Types>...>>;
template <typename... Types>
using this_is_not_unordered_set =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_unordered_set<Types>...>>;

// unordered_multiset
template <typename... Types>
using this_is_unordered_multiset =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_unordered_multiset<Types>...>>;
template <typename... Types>
using this_is_not_unordered_multiset =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_unordered_multiset<Types>...>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_CONTAINER_SET_HPP