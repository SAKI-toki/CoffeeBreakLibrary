/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef KIRARA_TYPE_TRAITS_OPERATOR_SHIFT_HPP
#define KIRARA_TYPE_TRAITS_OPERATOR_SHIFT_HPP
#include <kirara/config.hpp>

#include <kirara/type_traits/operator/macro.hpp>

KIRARA_ARITHMETIC_OPERATABLE(right_shiftable, right_shiftabled, >>)
KIRARA_ARITHMETIC_OPERATABLE(left_shiftable, left_shiftabled, <<)

KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_right_shiftable, compound_right_shiftabled, >>=)
KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_left_shiftable, compound_left_shiftabled, <<=)

#endif // KIRARA_TYPE_TRAITS_OPERATOR_SHIFT_HPP