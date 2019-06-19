/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#include "core/error/error.h"
#include "core/murmur.h"
#include "core/strings/string.h"
#include "core/strings/string_id.h"
#include <inttypes.h> // PRIx64

namespace haydn
{
StringId32::StringId32(const char* str)
{
	hash(str, strlen32(str));
}

StringId32::StringId32(const char* str, u32 len)
{
	hash(str, len);
}

void StringId32::hash(const char* str, u32 len)
{
	HY_ENSURE(NULL != str);
	_id = murmur32(str, len, 0);
}

void StringId32::parse(const char* str)
{
	HY_ENSURE(NULL != str);
	int num = sscanf(str, "%8x", &_id);
	HY_ENSURE(num == 1);
	HY_UNUSED(num);
}

void StringId32::to_string(char* buf, u32 len) const
{
	snprintf(buf, len, "%.8x", _id);
}

StringId64::StringId64(const char* str)
{
	hash(str, strlen32(str));
}

StringId64::StringId64(const char* str, u32 len)
{
	hash(str, len);
}

void StringId64::hash(const char* str, u32 len)
{
	HY_ENSURE(NULL != str);
	_id = murmur64(str, len, 0);
}

void StringId64::parse(const char* str)
{
	u32 id[2];
	HY_ENSURE(NULL != str);
	int num = sscanf(str, "%8x%8x", &id[0], &id[1]);
	_id =  u64(id[0]) << 32;
	_id |= u64(id[1]) <<  0;
	HY_ENSURE(num == 2);
	HY_UNUSED(num);
}

void StringId64::to_string(char* buf, u32 len) const
{
	snprintf(buf, len, "%.16" PRIx64, _id);
}

} // namespace haydn
