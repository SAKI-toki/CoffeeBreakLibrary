/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_OPERATOR_DETAILS_DEFINE_HPP
#define COFFEE_BREAK_OPERATOR_DETAILS_DEFINE_HPP
#include <coffee_break/config.hpp>

#include <type_traits>
#include <coffee_break/common/enable_if_nullptr.hpp>

#define COFFEE_BREAK_SAME_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME,          \
                                            OPERATOR, REFERENCE)               \
                                                                               \
  COFFEE_BREAK_NAMESPACE_BEGIN                                                 \
  namespace details                                                            \
  {                                                                            \
    template <typename T>                                                      \
    class CLASS_NAME                                                           \
    {                                                                          \
      template <typename U>                                                    \
      static constexpr STD_NSS::true_type                                      \
      check(decltype(STD_NSS::declval<U REFERENCE>()                           \
                         OPERATOR STD_NSS::declval<U>(),                       \
                     nullptr));                                                \
      template <typename>                                                      \
      static constexpr STD_NSS::false_type check(...);                         \
                                                                               \
    public:                                                                    \
      inline static constexpr bool value = decltype(check<T>(nullptr))::value; \
    };                                                                         \
    template <typename T>                                                      \
    inline constexpr bool CLASS_NAME##_v =                                     \
        COFFEE_BREAK_NSS::details::CLASS_NAME<T>::value;                       \
  }                                                                            \
  template <typename... Types>                                                 \
  using CONCEPT_NAME =                                                         \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<            \
          COFFEE_BREAK_NSS::details::CLASS_NAME<Types>...>>;                   \
  template <typename... Types>                                                 \
  using not_##CONCEPT_NAME =                                                   \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<           \
          COFFEE_BREAK_NSS::details::CLASS_NAME<Types>...>>;                   \
  COFFEE_BREAK_NAMESPACE_END

#define COFFEE_BREAK_DIFFERENT_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME,   \
                                                 OPERATOR, REFERENCE)        \
                                                                             \
  COFFEE_BREAK_NAMESPACE_BEGIN                                               \
  namespace details                                                          \
  {                                                                          \
    template <typename LT, typename RT>                                      \
    class CLASS_NAME                                                         \
    {                                                                        \
      template <typename LU, typename RU>                                    \
      static constexpr STD_NSS::true_type                                    \
      check(decltype(STD_NSS::declval<LU REFERENCE>()                        \
                         OPERATOR STD_NSS::declval<RU>(),                    \
                     nullptr));                                              \
      template <typename, typename>                                          \
      inline static constexpr STD_NSS::false_type check(...);                \
                                                                             \
    public:                                                                  \
      static constexpr bool value = decltype(check<LT, RT>(nullptr))::value; \
    };                                                                       \
    template <typename LT, typename RT>                                      \
    inline constexpr bool CLASS_NAME##_v =                                   \
        COFFEE_BREAK_NSS::details::CLASS_NAME<LT, RT>::value;                \
  }                                                                          \
  template <typename LT, typename... RTypes>                                 \
  using CONCEPT_NAME =                                                       \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<          \
          COFFEE_BREAK_NSS::details::CLASS_NAME<LT, RTypes>...>>;            \
  template <typename LT, typename... RTypes>                                 \
  using not_##CONCEPT_NAME =                                                 \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<         \
          COFFEE_BREAK_NSS::details::CLASS_NAME<LT, RTypes>...>>;            \
  COFFEE_BREAK_NAMESPACE_END

#define COFFEE_BREAK_UNARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME,                \
                                      FORWARD_OPERATOR, BACK_OPERATOR)         \
                                                                               \
  COFFEE_BREAK_NAMESPACE_BEGIN                                                 \
  namespace details                                                            \
  {                                                                            \
    template <typename T>                                                      \
    class CLASS_NAME                                                           \
    {                                                                          \
      template <typename U>                                                    \
      static constexpr STD_NSS::true_type                                      \
      check(decltype(FORWARD_OPERATOR STD_NSS::declval<U &>() BACK_OPERATOR,   \
                     nullptr));                                                \
      template <typename>                                                      \
      static constexpr STD_NSS::false_type check(...);                         \
                                                                               \
    public:                                                                    \
      inline static constexpr bool value = decltype(check<T>(nullptr))::value; \
    };                                                                         \
    template <typename T>                                                      \
    inline constexpr bool CLASS_NAME##_v =                                     \
        COFFEE_BREAK_NSS::details::CLASS_NAME<T>::value;                       \
  }                                                                            \
  template <typename... Types>                                                 \
  using CONCEPT_NAME =                                                         \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<STD_NSS::conjunction_v<            \
          COFFEE_BREAK_NSS::details::CLASS_NAME<Types>...>>;                   \
  template <typename... Types>                                                 \
  using not_##CONCEPT_NAME =                                                   \
      COFFEE_BREAK_NSS::enable_if_nullptr_t<!STD_NSS::conjunction_v<           \
          COFFEE_BREAK_NSS::details::CLASS_NAME<Types>...>>;                   \
  COFFEE_BREAK_NAMESPACE_END

// same

#define COFFEE_BREAK_SAME_ARITHMETIC_OPERATABLE(CLASS_NAME, CONCEPT_NAME, \
                                                OPERATOR)                 \
  COFFEE_BREAK_SAME_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, )

#define COFFEE_BREAK_SAME_COMPOUND_ASSIGNMENT_OPERATABLE( \
    CLASS_NAME, CONCEPT_NAME, OPERATOR)                   \
  COFFEE_BREAK_SAME_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, &)

// different

#define COFFEE_BREAK_DIFFERENT_ARITHMETIC_OPERATABLE(CLASS_NAME, CONCEPT_NAME, \
                                                     OPERATOR)                 \
  COFFEE_BREAK_DIFFERENT_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, )

#define COFFEE_BREAK_DIFFERENT_COMPOUND_ASSIGNMENT_OPERATABLE(       \
    CLASS_NAME, CONCEPT_NAME, OPERATOR)                              \
  COFFEE_BREAK_DIFFERENT_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, \
                                           OPERATOR, &)

// arithmetic

#define COFFEE_BREAK_ARITHMETIC_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR) \
  COFFEE_BREAK_SAME_ARITHMETIC_OPERATABLE(same_##CLASS_NAME,                   \
                                          same_##CONCEPT_NAME, OPERATOR)       \
  COFFEE_BREAK_DIFFERENT_ARITHMETIC_OPERATABLE(                                \
      different_##CLASS_NAME, different_##CONCEPT_NAME, OPERATOR)

// compound

#define COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(CLASS_NAME, CONCEPT_NAME, \
                                                    OPERATOR)                 \
  COFFEE_BREAK_SAME_COMPOUND_ASSIGNMENT_OPERATABLE(                           \
      same_##CLASS_NAME, same_##CONCEPT_NAME, OPERATOR)                       \
  COFFEE_BREAK_DIFFERENT_COMPOUND_ASSIGNMENT_OPERATABLE(                      \
      different_##CLASS_NAME, different_##CONCEPT_NAME, OPERATOR)

// forward_unary

#define COFFEE_BREAK_FORWARD_UNARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, \
                                              FORWARD_OPERATOR)         \
  COFFEE_BREAK_UNARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, FORWARD_OPERATOR, )

// back_unary

#define COFFEE_BREAK_BACK_UNARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, \
                                           BACK_OPERATOR)            \
  COFFEE_BREAK_UNARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, , BACK_OPERATOR)

// unary

#define COFFEE_BREAK_FORWARD_AND_BACK_UNARY_OPERATABLE(CLASS_NAME,             \
                                                       CONCEPT_NAME, OPERATOR) \
  COFFEE_BREAK_FORWARD_UNARY_OPERATABLE(forward_##CLASS_NAME,                  \
                                        forward_##CONCEPT_NAME, OPERATOR)      \
  COFFEE_BREAK_BACK_UNARY_OPERATABLE(back_##CLASS_NAME, back_##CONCEPT_NAME,   \
                                     OPERATOR)

#endif // COFFEE_BREAK_OPERATOR_DETAILS_DEFINE_HPP