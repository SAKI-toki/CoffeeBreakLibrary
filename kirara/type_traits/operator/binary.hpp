/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef KIRARA_TYPE_TRAITS_OPERATOR_BINARY_HPP
#define KIRARA_TYPE_TRAITS_OPERATOR_BINARY_HPP
#include <kirara/config.hpp>

#include <kirara/type_traits/operator/macro.hpp>

KIRARA_ARITHMETIC_OPERATABLE(addable, addabled, +)
KIRARA_ARITHMETIC_OPERATABLE(substractable, substractabled, -)
KIRARA_ARITHMETIC_OPERATABLE(multiplicationable, multiplicationabled, *)
KIRARA_ARITHMETIC_OPERATABLE(divisionable, divisionabled, /)
KIRARA_ARITHMETIC_OPERATABLE(modable, modabled, %)

KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_addable, compound_addabled, +=)
KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_substractable, compound_substractabled, -=)
KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_multiplicationable, compound_multiplicationabled, *=)
KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_divisionable, compound_divisionabled, /=)
KIRARA_COMPOUND_ASSIGNMENT_OPERATABLE(compound_modable, compound_modabled, %=)

#endif // KIRARA_TYPE_TRAITS_OPERATOR_BINARY_HPP