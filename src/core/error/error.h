/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/types.h"

/// @defgroup Error Error
/// @ingroup Core
namespace haydn
{
/// Error management.
///
/// @ingroup Error
namespace error
{
	/// Aborts the program execution logging an error message and the stacktrace if
	/// the platform supports it.
	void abort(const char* format, ...);

} // namespace error

} // namespace haydn

#if HAYDN_DEBUG
	#define HY_ASSERT(condition, msg, ...)                   \
		do                                                   \
		{                                                    \
			if (HY_UNLIKELY(!(condition)))                   \
			{                                                \
				haydn::error::abort("Assertion failed: %s\n" \
					"    In: %s:%d\n"                        \
					"    " msg "\n"                          \
					, # condition                            \
					, __FILE__                               \
					, __LINE__                               \
					, ## __VA_ARGS__                         \
					);                                       \
				HY_UNREACHABLE();                            \
			}                                                \
		} while (0)
#else
	#define HY_ASSERT(...) HY_NOOP()
#endif // HAYDN_DEBUG

#define HY_FATAL(msg, ...) HY_ASSERT(false, msg, ## __VA_ARGS__)
#define HY_ENSURE(condition) HY_ASSERT(condition, "")
