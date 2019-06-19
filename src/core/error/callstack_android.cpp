/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#include "core/platform.h"

#if HAYDN_PLATFORM_ANDROID

#include "core/strings/string_stream.h"

namespace haydn
{
namespace error
{
	void callstack(StringStream& ss)
	{
		ss << "Not supported";
	}

} // namespace error

} // namespace haydn

#endif // HAYDN_PLATFORM_ANDROID
