/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#include "core/guid.h"
#include "core/strings/dynamic_string.h"

namespace haydn
{
void DynamicString::from_guid(const Guid& guid)
{
	array::resize(_data, 37);
	guid::to_string(array::begin(_data), 37, guid);
	array::pop_back(_data);
}

void DynamicString::from_string_id(const StringId32& id)
{
	array::resize(_data, 9);
	id.to_string(array::begin(_data), 9);
	array::pop_back(_data);
}

void DynamicString::from_string_id(const StringId64& id)
{
	array::resize(_data, 17);
	id.to_string(array::begin(_data), 17);
	array::pop_back(_data);
}

} // namespace haydn
