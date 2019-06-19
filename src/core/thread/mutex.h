/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/types.h"

namespace haydn
{
/// Mutex.
///
/// @ingroup Thread
struct Mutex
{
	HY_ALIGN_DECL(16, u8 _data[64]);

	///
	Mutex();

	///
	~Mutex();

	///
	Mutex(const Mutex&) = delete;

	///
	Mutex& operator=(const Mutex&) = delete;

	/// Locks the mutex.
	void lock();

	/// Unlocks the mutex.
	void unlock();

	/// Returns the native mutex handle.
	void* native_handle();
};

} // namespace haydn
