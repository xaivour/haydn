/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#include "core/error/error.h"
#include "core/memory/proxy_allocator.h"
#include "device/profiler.h"

namespace haydn
{
ProxyAllocator::ProxyAllocator(Allocator& allocator, const char* name)
	: _allocator(allocator)
	, _name(name)
{
	HY_ASSERT(name != NULL, "Name must be != NULL");
}

void* ProxyAllocator::allocate(u32 size, u32 align)
{
	void* p = _allocator.allocate(size, align);
	ALLOCATE_MEMORY(_name, _allocator.allocated_size(p));
	return p;
}

void ProxyAllocator::deallocate(void* data)
{
	DEALLOCATE_MEMORY(_name, (data == NULL) ? 0 :_allocator.allocated_size((const void*)data));
	_allocator.deallocate(data);
}

const char* ProxyAllocator::name() const
{
	return _name;
}

} // namespace haydn