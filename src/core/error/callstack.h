/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/strings/types.h"

namespace haydn
{
namespace error
{
	/// Fills @a ss with the current call stack.
	void callstack(StringStream& ss);

} // namespace error

} // namespace haydn
