/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_TYPE_TRAITS_OPERATOR_LOGICAL_HPP
#define COFFEE_BREAK_TYPE_TRAITS_OPERATOR_LOGICAL_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/operator/macro.hpp>

COFFEE_BREAK_ARITHMETIC_OPERATABLE(bit_and_logicable, bit_and_logicabled, &)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(bit_or_logicable, bit_or_logicabled, |)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(bit_xor_logicable, bit_xor_logicabled, ^)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(and_logicable, and_logicabled, &&)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(or_logicable, or_logicabled, ||)

COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_bit_and_logicable, compound_bit_and_logicabled, &=)
COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_bit_or_logicable, compound_bit_or_logicabled, |=)
COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_bit_xor_logicable, compound_bit_xor_logicabled, ^=)

#endif // COFFEE_BREAK_TYPE_TRAITS_OPERATOR_LOGICAL_HPP