/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_OPERATOR_UNARY_HPP
#define COFFEE_BREAK_OPERATOR_UNARY_HPP
#include <coffee_break/config.hpp>

#include <coffee_break/operator/details/define.hpp>

COFFEE_BREAK_FORWARD_UNARY_OPERATABLE(plus_unary_operatable, plus_unary_operatabled, +)
COFFEE_BREAK_FORWARD_UNARY_OPERATABLE(minus_unary_operatable, minus_unary_operatabled, -)
COFFEE_BREAK_FORWARD_UNARY_OPERATABLE(logical_negation_operatable, logical_negation_operatabled, !)
COFFEE_BREAK_FORWARD_UNARY_OPERATABLE(bit_logical_negation_operatable, bit_logical_negation_operatabled, ~)

COFFEE_BREAK_FORWARD_AND_BACK_UNARY_OPERATABLE(incrementable, incrementabled, ++)
COFFEE_BREAK_FORWARD_AND_BACK_UNARY_OPERATABLE(decrementable, decrementabled, --)

#endif // COFFEE_BREAK_OPERATOR_UNARY_HPP