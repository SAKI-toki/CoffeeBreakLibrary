/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef KIRARA_TYPE_TRAITS_OPERATOR_MACRO_HPP
#define KIRARA_TYPE_TRAITS_OPERATOR_MACRO_HPP
#include <kirara/config.hpp>

#include <type_traits>
#include <kirara/type_traits/enable_if_nullptr.hpp>

#define KIRARA_SAME_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, REFERENCE)            \
                                                                                                \
    KIRARA_NAMESPACE_BEGIN                                                                      \
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
    inline constexpr bool CLASS_NAME##_v = KIRARA_NSS::details::CLASS_NAME<T>::value;           \
    }                                                                                           \
    template <typename T>                                                                       \
    using CONCEPT_NAME =                                                                        \
        KIRARA_NSS::enable_if_nullptr_t<KIRARA_NSS::details::CLASS_NAME##_v<T>>;                \
    KIRARA_NAMESPACE_END

#define KIRARA_DIFFERENT_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, REFERENCE)         \
                                                                                                  \
    KIRARA_NAMESPACE_BEGIN                                                                        \
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
    inline constexpr bool CLASS_NAME##_v = KIRARA_NSS::details::CLASS_NAME<LT, RT>::value;        \
    }                                                                                             \
    template <typename LT, typename RT>                                                           \
    using CONCEPT_NAME =                                                                          \
        KIRARA_NSS::enable_if_nullptr_t<KIRARA_NSS::details::CLASS_NAME##_v<LT, RT>>;             \
    KIRARA_NAMESPACE_END

#define KIRARA_SAME_ARITHMETIC_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR) \
    KIRARA_SAME_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, )

#define KIRARA_SAME_COMPOUND_ASSIGNMENT_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR) \
    KIRARA_SAME_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, &)

#define KIRARA_DIFFERENT_ARITHMETIC_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR) \
    KIRARA_DIFFERENT_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, )

#define KIRARA_DIFFERENT_COMPOUND_ASSIGNMENT_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR) \
    KIRARA_DIFFERENT_BINARY_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR, &)

#define KIRARA_ARITHMETIC_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR)                \
    KIRARA_SAME_ARITHMETIC_OPERATABLE(same_##CLASS_NAME, same_##CONCEPT_NAME, OPERATOR) \
    KIRARA_DIFFERENT_ARITHMETIC_OPERATABLE(different_##CLASS_NAME, different_##CONCEPT_NAME, OPERATOR)

#define KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(CLASS_NAME, CONCEPT_NAME, OPERATOR)                \
    KIRARA_SAME_COMPOUND_ASSIGNMENT_OPERATABLE(same_##CLASS_NAME, same_##CONCEPT_NAME, OPERATOR) \
    KIRARA_DIFFERENT_COMPOUND_ASSIGNMENT_OPERATABLE(different_##CLASS_NAME, different_##CONCEPT_NAME, OPERATOR)

#endif // KIRARA_TYPE_TRAITS_OPERATOR_MACRO_HPP