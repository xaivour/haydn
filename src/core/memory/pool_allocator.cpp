/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#include "core/error/error.h"
#include "core/memory/pool_allocator.h"

namespace haydn
{
PoolAllocator::PoolAllocator(Allocator& backing, u32 num_blocks, u32 block_size, u32 block_align)
	: _backing(backing)
	, _start(NULL)
	, _freelist(NULL)
	, _block_size(block_size)
	, _block_align(block_align)
	, _num_allocations(0)
	, _allocated_size(0)
{
	HY_ASSERT(num_blocks > 0, "Unsupported number of blocks");
	HY_ASSERT(block_size > 0, "Unsupported block size");
	HY_ASSERT(block_align > 0, "Unsupported block alignment");

	u32 actual_block_size = block_size + block_align;
	u32 pool_size = num_blocks * actual_block_size;

	char* mem = (char*) backing.allocate(pool_size, block_align);

	// Initialize intrusive freelist
	char* cur = mem;
	for (u32 bb = 0; bb < num_blocks - 1; bb++)
	{
		uintptr_t* next = (uintptr_t*) cur;
		*next = (uintptr_t) cur + actual_block_size;
		cur += actual_block_size;
	}

	uintptr_t* end = (uintptr_t*) cur;
	*end = (uintptr_t) NULL;

	_start = mem;
	_freelist = mem;
}

PoolAllocator::~PoolAllocator()
{
	_backing.deallocate(_start);
}

void* PoolAllocator::allocate(u32 size, u32 align)
{
	HY_ASSERT(size == _block_size, "Size must match block size");
	HY_UNUSED(size);
	HY_ASSERT(align == _block_align, "Align must match block align");
	HY_UNUSED(align);
	HY_ASSERT(_freelist != NULL, "Out of memory");

	uintptr_t next_free = *((uintptr_t*) _freelist);
	void* user_ptr = _freelist;
	_freelist = (void*) next_free;

	_num_allocations++;
	_allocated_size += _block_size;

	return user_ptr;
}

void PoolAllocator::deallocate(void* data)
{
	if (!data)
		return;

	HY_ASSERT(_num_allocations > 0, "Did not allocate");

	uintptr_t* next = (uintptr_t*) data;
	*next = (uintptr_t) _freelist;

	_freelist = data;

	_num_allocations--;
	_allocated_size -= _block_size;
}

u32 PoolAllocator::total_allocated()
{
	return _allocated_size;
}

} // namespace haydn
