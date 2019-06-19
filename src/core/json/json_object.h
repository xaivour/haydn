/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/containers/hash_map.h"
#include "core/json/types.h"

namespace haydn
{
template<>
struct hash<FixedString>
{
	u32 operator()(const FixedString& val) const
	{
		return (u32)murmur32(val._data, val._length, 0);
	}
};

/// Functions to manipulate JsonObject.
///
/// @ingroup JSON
namespace json_object
{
	/// Returns the number of keys in the object @a jo.
	inline u32 size(const JsonObject& jo)
	{
		return hash_map::size(jo._map);
	}

	/// Returns whether the object @a jo has the @a key.
	inline bool has(const JsonObject& jo, const char* key)
	{
		return hash_map::has(jo._map, FixedString(key));
	}

	inline bool is_hole(const JsonObject& jo, const HashMap<FixedString, const char*>::Entry* entry)
	{
		return hash_map::is_hole(jo._map, entry);
	}

	/// Returns a pointer to the first item in the object @a jo.
	inline const HashMap<FixedString, const char*>::Entry* begin(const JsonObject& jo)
	{
		return hash_map::begin(jo._map);
	}

	/// Returns a pointer to the item following the last item in the object @a jo.
	inline const HashMap<FixedString, const char*>::Entry* end(const JsonObject& jo)
	{
		return hash_map::end(jo._map);
	}

} // namespace json_object

inline JsonObject::JsonObject(Allocator& a)
	: _map(a)
{
}

/// Returns the value of the @a key or NULL.
inline const char* JsonObject::operator[](const char* key) const
{
	return hash_map::get(_map, FixedString(key), (const char*)NULL);
}

/// Returns the value of the @a key or NULL.
inline const char* JsonObject::operator[](const FixedString& key) const
{
	return hash_map::get(_map, key, (const char*)NULL);
}

}
