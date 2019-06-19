/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#include "core/platform.h"
#include "core/thread/atomic_int.h"

#if HAYDN_PLATFORM_WINDOWS
	#include <windows.h>
#endif

namespace haydn
{
AtomicInt::AtomicInt(s32 val)
	: _val(val)
{
}

s32 AtomicInt::load()
{
#if HAYDN_PLATFORM_POSIX && HAYDN_COMPILER_GCC
	__sync_fetch_and_add(&_val, 0);
	return _val;
#elif HAYDN_PLATFORM_WINDOWS
	InterlockedExchangeAdd((LONG*)&_val, (s32)0);
	return _val;
#endif
}

void AtomicInt::store(s32 val)
{
#if HAYDN_PLATFORM_POSIX && HAYDN_COMPILER_GCC
	__sync_lock_test_and_set(&_val, val);
#elif HAYDN_PLATFORM_WINDOWS
	InterlockedExchange((LONG*)&_val, val);
#endif
}

} // namespace haydn
