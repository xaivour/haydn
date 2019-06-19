/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/platform.h"
#include <stdint.h>
#include <stddef.h>

#ifndef HAYDN_DEBUG
	#define HAYDN_DEBUG 0
#endif // HAYDN_DEBUG

#ifndef HAYDN_DEVELOPMENT
	#define HAYDN_DEVELOPMENT 0
#endif // HAYDN_DEVELOPMENT

/// @defgroup Core Core

namespace haydn
{
/// @addtogroup Core
/// @{
typedef int8_t   s8;
typedef uint8_t  u8;
typedef int16_t  s16;
typedef uint16_t u16;
typedef int32_t  s32;
typedef uint32_t u32;
typedef int64_t  s64;
typedef uint64_t u64;
typedef float    f32;
typedef double   f64;
/// @}

template <typename T>
inline void exchange(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
inline T min(const T& a, const T& b)
{
	return a < b ? a : b;
}

template <typename T>
inline T max(const T& a, const T& b)
{
	return a > b ? a : b;
}

template <typename T>
inline T clamp(T val, T mmin, T mmax)
{
	return min(max(mmin, val), mmax);
}

} // namespace haydn

#if defined(_MSC_VER)
	#define _ALLOW_KEYWORD_MACROS
#endif

#if !defined(alignof)
	#define alignof(x) __alignof(x)
#endif

#if !defined(__va_copy)
	#define __va_copy(dest, src) (dest = src)
#endif

#define countof(arr) (sizeof(arr)/sizeof(arr[0]))
#define container_of(ptr, type, member) ((char*)ptr - offsetof(type, member))

#define HY_STRINGIZE(value) HY_STRINGIZE_(value)
#define HY_STRINGIZE_(value) #value

#define HY_NOOP(...) do { (void)0; } while (0)
#define HY_UNUSED(x) do { (void)(x); } while (0)
#define HY_STATIC_ASSERT(condition, ...) static_assert(condition, "" # __VA_ARGS__)

#if defined(__GNUC__)
	#define HY_LIKELY(x) __builtin_expect((x), 1)
	#define HY_UNLIKELY(x) __builtin_expect((x), 0)
	#define HY_UNREACHABLE() __builtin_unreachable()
#else
	#define HY_LIKELY(x) (x)
	#define HY_UNLIKELY(x) (x)
	#define HY_UNREACHABLE()
#endif
#if defined(__GNUC__)
	#define HY_THREAD __thread
#elif defined(_MSC_VER)
	#define HY_THREAD __declspec(thread)
#else
	#error "Compiler not supported"
#endif

#if HAYDN_PLATFORM_LINUX
	#define HY_ALIGN_DECL(align, decl) decl __attribute__ ((aligned (align)))
#elif HAYDN_PLATFORM_WINDOWS
	#define HY_ALIGN_DECL(align_, decl) __declspec (align(align_)) decl
#endif
