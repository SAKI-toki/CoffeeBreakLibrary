/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_OPERATOR_BINARY_HPP
#define COFFEE_BREAK_OPERATOR_BINARY_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/operator/details/define.hpp>

COFFEE_BREAK_ARITHMETIC_OPERATABLE(addable, addabled, +)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(substractable, substractabled, -)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(multiplicationable, multiplicationabled, *)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(divisionable, divisionabled, /)
COFFEE_BREAK_ARITHMETIC_OPERATABLE(modable, modabled, %)

COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_addable, compound_addabled, +=)
COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_substractable, compound_substractabled, -=)
COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_multiplicationable, compound_multiplicationabled, *=)
COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_divisionable, compound_divisionabled, /=)
COFFEE_BREAK_COMPOUND_ASSIGNMENT_OPERATABLE(compound_modable, compound_modabled, %=)

#endif // COFFEE_BREAK_OPERATOR_BINARY_HPP