/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef KIRARA_TYPE_TRAITS_OPERATOR_LOGICAL_HPP
#define KIRARA_TYPE_TRAITS_OPERATOR_LOGICAL_HPP
#include <kirara/config.hpp>

#include <kirara/type_traits/operator/macro.hpp>

KIRARA_ARITHMETIC_OPERATABLE(bit_and_logicable, bit_and_logicabled, &)
KIRARA_ARITHMETIC_OPERATABLE(bit_or_logicable, bit_or_logicabled, |)
KIRARA_ARITHMETIC_OPERATABLE(bit_xor_logicable, bit_xor_logicabled, ^)
KIRARA_ARITHMETIC_OPERATABLE(and_logicable, and_logicabled, &&)
KIRARA_ARITHMETIC_OPERATABLE(or_logicable, or_logicabled, ||)

KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_bit_and_logicable, compound_bit_and_logicabled, &=)
KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_bit_or_logicable, compound_bit_or_logicabled, |=)
KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_bit_xor_logicable, compound_bit_xor_logicabled, ^=)

#endif // KIRARA_TYPE_TRAITS_OPERATOR_LOGICAL_HPP