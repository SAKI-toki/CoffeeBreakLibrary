/*=============================================================================
  Copyright (c) 2019 yu ishiyama
=============================================================================*/
#ifndef KIRARA_CONFIG_NAMESPACE_MACRO_HPP
#define KIRARA_CONFIG_NAMESPACE_MACRO_HPP

//NSS = NAMESPACE_SCOPE_SOLUTION

#define USE_NAMESPACE

#ifdef USE_NAMESPACE

#define KIRARA_NAMESPACE_NAME kirara
#define KIRARA_NSS ::KIRARA_NAMESPACE_NAME

#define KIRARA_NAMESPACE_BEGIN    \
  namespace KIRARA_NAMESPACE_NAME \
  {

#define KIRARA_NAMESPACE_END \
  }

#else
#define KIRARA_NAMESPACE_NAME
#define KIRARA_NSS
#define KIRARA_NAMESPACE_BEGIN
#define KIRARA_NAMESPACE_END
#endif // USE_NAMESPACE

#define STD_NSS ::std

#endif // KIRARA_CONFIG_NAMESPACE_MACRO_HPP