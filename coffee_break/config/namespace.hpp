/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef COFFEE_BREAK_CONFIG_NAMESPACE_HPP
#define COFFEE_BREAK_CONFIG_NAMESPACE_HPP

//NSS = NAMESPACE_SCOPE_SOLUTION

#ifdef COFFEE_BREAK_USE_NAMESPACE

#define COFFEE_BREAK_NAMESPACE_NAME coffee_break
#define COFFEE_BREAK_NSS ::COFFEE_BREAK_NAMESPACE_NAME

#define COFFEE_BREAK_NAMESPACE_BEGIN    \
  namespace COFFEE_BREAK_NAMESPACE_NAME \
  {

#define COFFEE_BREAK_NAMESPACE_END \
  }

#else
#define COFFEE_BREAK_NAMESPACE_NAME
#define COFFEE_BREAK_NSS
#define COFFEE_BREAK_NAMESPACE_BEGIN
#define COFFEE_BREAK_NAMESPACE_END
#endif // USE_NAMESPACE

#define STD_NSS ::std

#endif // COFFEE_BREAK_CONFIG_NAMESPACE_HPP