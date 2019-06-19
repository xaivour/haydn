/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#include "core/error/error.h"
#include "core/guid.h"
#include "core/platform.h"
#include <stdio.h> // sscanf

#if HAYDN_PLATFORM_POSIX
	#include <fcntl.h>
	#include <unistd.h>
	#include <errno.h>
#elif HAYDN_PLATFORM_WINDOWS
	#include <objbase.h>
#endif // HAYDN_PLATFORM_POSIX

namespace haydn
{
namespace guid
{
	Guid new_guid()
	{
		Guid guid;
#if HAYDN_PLATFORM_POSIX
		int fd = open("/dev/urandom", O_RDONLY);
		HY_ASSERT(fd != -1, "open: errno = %d", errno);
		ssize_t rb = read(fd, &guid, sizeof(guid));
		HY_ENSURE(rb == sizeof(guid));
		HY_UNUSED(rb);
		close(fd);
		guid.data3 = (guid.data3 & 0x4fffu) | 0x4000u;
		guid.data4 = (guid.data4 & 0x3fffffffffffffffu) | 0x8000000000000000u;
#elif HAYDN_PLATFORM_WINDOWS
		HRESULT hr = CoCreateGuid((GUID*)&guid);
		HY_ASSERT(hr == S_OK, "CoCreateGuid: error");
		HY_UNUSED(hr);
#endif // HAYDN_PLATFORM_POSIX
		return guid;
	}

	Guid parse(const char* str)
	{
		Guid guid;
		try_parse(guid, str);
		return guid;
	}

	bool try_parse(Guid& guid, const char* str)
	{
		HY_ENSURE(NULL != str);
		u32 a, b, c, d, e, f;
		int num = sscanf(str, "%8x-%4x-%4x-%4x-%4x%8x", &a, &b, &c, &d, &e, &f);
		guid.data1 = a;
		guid.data2 = (u16)(b & 0x0000ffffu);
		guid.data3 = (u16)(c & 0x0000ffffu);
		guid.data4 = (u64)(d & 0x0000ffffu) << 48 | (u64)(e & 0x0000ffffu) << 32 | (u64)f;
		return num == 6;
	}

	void to_string(char* buf, u32 len, const Guid& guid)
	{
		snprintf(buf, len, "%.8x-%.4x-%.4x-%.4x-%.4x%.8x"
			, guid.data1
			, guid.data2
			, guid.data3
			, (u16)((guid.data4 & 0xffff000000000000u) >> 48)
			, (u16)((guid.data4 & 0x0000ffff00000000u) >> 32)
			, (u32)((guid.data4 & 0x00000000ffffffffu) >>  0)
			);
	}

} // namespace guid

} // namespace haydn
