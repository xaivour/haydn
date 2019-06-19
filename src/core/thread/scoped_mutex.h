/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/thread/mutex.h"

namespace haydn
{
/// Automatically locks a mutex when created and unlocks when destroyed.
///
/// @ingroup Thread
struct ScopedMutex
{
	Mutex& _mutex;

	/// Locks the mutex @a m.
	ScopedMutex(Mutex& m)
		: _mutex(m)
	{
		_mutex.lock();
	}

	/// Unlocks the mutex passed to ScopedMutex::ScopedMutex()
	~ScopedMutex()
	{
		_mutex.unlock();
	}

	///
	ScopedMutex(const ScopedMutex&) = delete;

	///
	ScopedMutex& operator=(const ScopedMutex&) = delete;
};

} // namespace haydn
