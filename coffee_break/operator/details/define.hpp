/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_OPERATOR_DETAILS_DEFINE_HPP
#define COFFEE_BREAK_OPERATOR_DETAILS_DEFINE_HPP
#include <coffee_break/config.hpp>

#include <type_traits>
#include <coffee_break/common/enable_if_nullptr.hpp>

#define COFFEE_BREAK_SAME_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, REFERENCE)      \
                                                                                                \
    COFFEE_BREAK_NAMESPACE_BEGIN                                                                \
    namespace details                                                                           \
    {                                                                                           \
    template <typename T>                                                                       \
    class CLASS_NAME                                                                            \
    {                                                                                           \
        template <typename U>                                                                   \
        static constexpr STD_NSS::true_type check(                                              \
            decltype(STD_NSS::declval<U REFERENCE>() OPERATOR STD_NSS::declval<U>(), nullptr)); \
        template <typename>                                                                     \
        static constexpr STD_NSS::false_type check(...);                                        \
                                                                                                \
    public:                                                                                     \
        static constexpr bool value = decltype(check<T>(nullptr))::value;                       \
    };                                                                                          \
    template <typename T>                                                                       \
    inline constexpr bool CLASS_NAME##_v = COFFEE_BREAK_NSS::details::CLASS_NAME<T>::value;     \
    }                                                                                           \
    template <typename T>                                                                       \
    using CONCEPT_NAME =                                                                        \
        COFFEE_BREAK_NSS::enable_if_nullptr_t<COFFEE_BREAK_NSS::details::CLASS_NAME##_v<T>>;    \
    COFFEE_BREAK_NAMESPACE_END

#define COFFEE_BREAK_DIFFERENT_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, REFERENCE)   \
                                                                                                  \
    COFFEE_BREAK_NAMESPACE_BEGIN                                                                  \
    namespace details                                                                             \
    {                                                                                             \
    template <typename LT, typename RT>                                                           \
    class CLASS_NAME                                                                              \
    {                                                                                             \
        template <typename LU, typename RU>                                                       \
        static constexpr STD_NSS::true_type check(                                                \
            decltype(STD_NSS::declval<LU REFERENCE>() OPERATOR STD_NSS::declval<RU>(), nullptr)); \
        template <typename, typename>                                                             \
        static constexpr STD_NSS::false_type check(...);                                          \
                                                                                                  \
    public:                                                                                       \
        static constexpr bool value = decltype(check<LT, RT>(nullptr))::value;                    \
    };                                                                                            \
    template <typename LT, typename RT>                                                           \
    inline constexpr bool CLASS_NAME##_v = COFFEE_BREAK_NSS::details::CLASS_NAME<LT, RT>::value;  \
    }                                                                                             \
    template <typename LT, typename RT>                                                           \
    using CONCEPT_NAME =                                                                          \
        COFFEE_BREAK_NSS::enable_if_nullptr_t<COFFEE_BREAK_NSS::details::CLASS_NAME##_v<LT, RT>>; \
    COFFEE_BREAK_NAMESPACE_END

#define COFFEE_BREAK_SAME_ARITHMETIC_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR) \
    COFFEE_BREAK_SAME_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, )

#define COFFEE_BREAK_SAME_COMPOUND_ASSIGNMENT_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR) \
    COFFEE_BREAK_SAME_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, &)

#define COFFEE_BREAK_DIFFERENT_ARITHMETIC_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR) \
    COFFEE_BREAK_DIFFERENT_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, )

#define COFFEE_BREAK_DIFFERENT_COMPOUND_ASSIGNMENT_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR) \
    COFFEE_BREAK_DIFFERENT_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, &)

#define COFFEE_BREAK_ARITHMETIC_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR)                \
    COFFEE_BREAK_SAME_ARITHMETIC_OPERATABLE(same_##CLASS_NAME, same_##CONCEPT_NAME, OPERATOR) \
    COFFEE_BREAK_DIFFERENT_ARITHMETIC_OPERATABLE(different_##CLASS_NAME, different_##CONCEPT_NAME, OPERATOR)

#define COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR)                \
    COFFEE_BREAK_SAME_COMPOUND_ASSIGNMENT_OPERATABLE(same_##CLASS_NAME, same_##CONCEPT_NAME, OPERATOR) \
    COFFEE_BREAK_DIFFERENT_COMPOUND_ASSIGNMENT_OPERATABLE(different_##CLASS_NAME, different_##CONCEPT_NAME, OPERATOR)

#endif // COFFEE_BREAK_OPERATOR_DETAILS_DEFINE_HPP