/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef KIRARA_TYPE_TRAITS_OPERATOR_COMPARE_HPP
#define KIRARA_TYPE_TRAITS_OPERATOR_COMPARE_HPP
#include <kirara/config.hpp>

#include <kirara/type_traits/operator/macro.hpp>

KIRARA_ARITHMETIC_OPERATABLE(equal_comparable, equal_comparabled, ==)
KIRARA_ARITHMETIC_OPERATABLE(not_equal_comparable, not_equal_comparabled, !=)
KIRARA_ARITHMETIC_OPERATABLE(small_comparable, small_comparabled, <)
KIRARA_ARITHMETIC_OPERATABLE(big_comparable, big_comparabled, >)
KIRARA_ARITHMETIC_OPERATABLE(small_or_equal_comparable, small_or_equal_comparabled, <=)
KIRARA_ARITHMETIC_OPERATABLE(big_or_equal_comparable, big_or_equal_comparabled, >=)

#endif // KIRARA_TYPE_TRAITS_OPERATOR_COMPARE_HPP