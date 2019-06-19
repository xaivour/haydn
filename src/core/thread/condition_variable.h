/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/thread/types.h"

namespace haydn
{
/// Condition variable.
///
/// @ingroup Thread
struct ConditionVariable
{
	HY_ALIGN_DECL(16, u8 _data[64]);

	///
	ConditionVariable();

	///
	~ConditionVariable();

	///
	ConditionVariable(const ConditionVariable&) = delete;

	///
	ConditionVariable& operator=(const ConditionVariable&) = delete;

	///
	void wait(Mutex& mutex);

	///
	void signal();
};

} // namespace haydn
