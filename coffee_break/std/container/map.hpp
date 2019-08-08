/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_STD_CONTAINER_MAP_HPP
#define COFFEE_BREAK_STD_CONTAINER_MAP_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/common/enable_if_nullptr.hpp>
#include <type_traits>
#include <map>
#include <unordered_map>

COFFEE_BREAK_NAMESPACE_BEGIN

namespace details
{

  // map
  template <typename>
  struct is_map : STD_NSS::false_type
  {
  };
  template <typename KeyType, typename ValueType, typename CompareType,
            typename AllocType>
  struct is_map<std::map<KeyType, ValueType, CompareType, AllocType>>
      : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_map_v = COFFEE_BREAK_NSS::details::is_map<T>::value;

  // multimap
  template <typename>
  struct is_multimap : STD_NSS::false_type
  {
  };
  template <typename KeyType, typename ValueType, typename CompareType,
            typename AllocType>
  struct is_multimap<std::multimap<KeyType, ValueType, CompareType, AllocType>>
      : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_multimap_v =
      COFFEE_BREAK_NSS::details::is_multimap<T>::value;

  // unordered_map
  template <typename>
  struct is_unordered_map : STD_NSS::false_type
  {
  };
  template <typename KeyType, typename ValueType, typename HashType,
            typename PredType, typename AllocType>
  struct is_unordered_map<
      std::unordered_map<KeyType, ValueType, HashType, PredType, AllocType>>
      : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_unordered_map_v =
      COFFEE_BREAK_NSS::details::is_unordered_map<T>::value;

  // unordered_multimap
  template <typename>
  struct is_unordered_multimap : STD_NSS::false_type
  {
  };
  template <typename KeyType, typename ValueType, typename HashType,
            typename PredType, typename AllocType>
  struct is_unordered_multimap<std::unordered_multimap<
      KeyType, ValueType, HashType, PredType, AllocType>> : STD_NSS::true_type
  {
  };

  template <typename T>
  inline constexpr bool is_unordered_multimap_v =
      COFFEE_BREAK_NSS::details::is_unordered_multimap<T>::value;

} // namespace details

// map
template <typename... Types>
using this_is_map = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_map<Types>...>>;
template <typename... Types>
using this_is_not_map = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_map<Types>...>>;

// multimap
template <typename... Types>
using this_is_multimap = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_multimap<Types>...>>;
template <typename... Types>
using this_is_not_multimap = COFFEE_BREAK_NSS::enable_if_nullptr_t<
    !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_multimap<Types>...>>;

// unordered_map
template <typename... Types>
using this_is_unordered_map =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_unordered_map<Types>...>>;
template <typename... Types>
using this_is_not_unordered_map =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_unordered_map<Types>...>>;

// unordered_multimap
template <typename... Types>
using this_is_unordered_multimap =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_unordered_multimap<Types>...>>;
template <typename... Types>
using this_is_not_unordered_multimap =
    COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<
        COFFEE_BREAK_NSS::details::is_unordered_multimap<Types>...>>;

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_STD_CONTAINER_MAP_HPP