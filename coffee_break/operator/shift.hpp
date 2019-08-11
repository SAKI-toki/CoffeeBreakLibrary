/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_TYPE_TRAITS_OPERATOR_SHIFT_HPP
#define COFFEE_BREAK_TYPE_TRAITS_OPERATOR_SHIFT_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/operator/details/define.hpp>

COFFEE_BREAK_ARITHMETIC_OPERATABLE(right_shiftable, right_shiftabled, >>)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(left_shiftable, left_shiftabled, <<)

COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_right_shiftable, compound_right_shiftabled, >>=)
COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_left_shiftable, compound_left_shiftabled, <<=)

#endif // COFFEE_BREAK_TYPE_TRAITS_OPERATOR_SHIFT_HPP