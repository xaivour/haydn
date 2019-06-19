/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/types.h"

namespace haydn
{
/// Semaphore.
///
/// @ingroup Thread.
struct Semaphore
{
	HY_ALIGN_DECL(16, u8 _data[128]);

	///
	Semaphore();

	///
	~Semaphore();

	///
	Semaphore(const Semaphore&) = delete;

	///
	Semaphore& operator=(const Semaphore&) = delete;

	///
	void post(u32 count = 1);

	///
	void wait();
};

} // namespace haydn
