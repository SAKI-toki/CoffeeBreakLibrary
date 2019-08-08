/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_SIZE_HPP
#define COFFEE_BREAK_SIZE_HPP
#include <coffee_break/config.hpp>

#include <type_traits>
#include <coffee_break/common/enable_if_nullptr.hpp>

#define COFFEE_BREAK_SIZE_DEFINE(ADD_NAME, COMPARE_OPERATOR)                   \
  COFFEE_BREAK_NAMESPACE_BEGIN                                                 \
  namespace details                                                            \
  {                                                                            \
    template <decltype(sizeof(void *)) SizeValue, typename T>                  \
    class is##ADD_NAME##_size                                                  \
    {                                                                          \
      template <typename U>                                                    \
      static constexpr STD_NSS::true_type                                      \
      check(COFFEE_BREAK_NSS::enable_if_nullptr_t<                             \
            SizeValue COMPARE_OPERATOR sizeof(U)>);                            \
      template <typename>                                                      \
      static constexpr STD_NSS::false_type check(...);                         \
                                                                               \
    public:                                                                    \
      inline static constexpr bool value = decltype(check<T>(nullptr))::value; \
    };                                                                         \
    template <decltype(sizeof(void *)) SizeValue, typename T>                  \
    inline constexpr bool is##ADD_NAME##_size_v =                              \
        COFFEE_BREAK_NSS::details::is##ADD_NAME##_size<SizeValue, T>::value;   \
  }                                                                            \
  COFFEE_BREAK_NAMESPACE_END

COFFEE_BREAK_SIZE_DEFINE(, ==)
COFFEE_BREAK_SIZE_DEFINE(_least, <=)
COFFEE_BREAK_SIZE_DEFINE(_most, >=)

#define COFFEE_BREAK_SIZE_VALUE_DEFINE(SIZE_VALUE)                             \
  template <typename... Types>                                                 \
  using is_size##SIZE_VALUE =                                                  \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<            \
          COFFEE_BREAK_NSS::details::is_size<SIZE_VALUE / 8, Types>...>>;      \
  template <typename... Types>                                                 \
  using is_least_size##SIZE_VALUE = COFFEE_BREAK_NSS::enable_if_nullptr_t<     \
      STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_least_size<         \
          SIZE_VALUE / 8, Types>...>>;                                         \
  template <typename... Types>                                                 \
  using is_most_size##SIZE_VALUE =                                             \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<            \
          COFFEE_BREAK_NSS::details::is_most_size<SIZE_VALUE / 8, Types>...>>; \
  template <typename... Types>                                                 \
  using is_not_size##SIZE_VALUE =                                              \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<           \
          COFFEE_BREAK_NSS::details::is_size<SIZE_VALUE / 8, Types>...>>;      \
  template <typename... Types>                                                 \
  using is_not_least_size##SIZE_VALUE = COFFEE_BREAK_NSS::enable_if_nullptr_t< \
      !STD_NSS::conjunction_v<COFFEE_BREAK_NSS::details::is_least_size<        \
          SIZE_VALUE / 8, Types>...>>;                                         \
  template <typename... Types>                                                 \
  using is_not_most_size##SIZE_VALUE =                                         \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<           \
          COFFEE_BREAK_NSS::details::is_most_size<SIZE_VALUE / 8, Types>...>>;

COFFEE_BREAK_NAMESPACE_BEGIN

COFFEE_BREAK_SIZE_VALUE_DEFINE(8)   // 1
COFFEE_BREAK_SIZE_VALUE_DEFINE(16)  // 2
COFFEE_BREAK_SIZE_VALUE_DEFINE(24)  // 3
COFFEE_BREAK_SIZE_VALUE_DEFINE(32)  // 4
COFFEE_BREAK_SIZE_VALUE_DEFINE(40)  // 5
COFFEE_BREAK_SIZE_VALUE_DEFINE(48)  // 6
COFFEE_BREAK_SIZE_VALUE_DEFINE(56)  // 7
COFFEE_BREAK_SIZE_VALUE_DEFINE(64)  // 8
COFFEE_BREAK_SIZE_VALUE_DEFINE(72)  // 9
COFFEE_BREAK_SIZE_VALUE_DEFINE(80)  // 10
COFFEE_BREAK_SIZE_VALUE_DEFINE(88)  // 11
COFFEE_BREAK_SIZE_VALUE_DEFINE(96)  // 12
COFFEE_BREAK_SIZE_VALUE_DEFINE(104) // 13
COFFEE_BREAK_SIZE_VALUE_DEFINE(112) // 14
COFFEE_BREAK_SIZE_VALUE_DEFINE(120) // 15
COFFEE_BREAK_SIZE_VALUE_DEFINE(128) // 16

COFFEE_BREAK_NAMESPACE_END

#endif // COFFEE_BREAK_SIZE_HPP