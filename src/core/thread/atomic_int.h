/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/types.h"

namespace haydn
{
/// Atomic integer.
///
/// @ingroup Thread
struct AtomicInt
{
	s32 _val;

	/// Initialization is not atomic.
	AtomicInt(s32 val);

	///
	s32 load();

	///
	void store(s32 val);
};

} // namespace haydn
