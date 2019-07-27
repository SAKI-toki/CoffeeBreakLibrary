/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_TYPE_TRAITS_OPERATOR_COMPARE_HPP
#define COFFEE_BREAK_TYPE_TRAITS_OPERATOR_COMPARE_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/operator/macro.hpp>

COFFEE_BREAK_ARITHMETIC_OPERATABLE(equal_comparable, equal_comparabled, ==)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(not_equal_comparable, not_equal_comparabled, !=)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(small_comparable, small_comparabled, <)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(big_comparable, big_comparabled, >)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(small_or_equal_comparable, small_or_equal_comparabled, <=)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(big_or_equal_comparable, big_or_equal_comparabled, >=)

#endif // COFFEE_BREAK_TYPE_TRAITS_OPERATOR_COMPARE_HPP