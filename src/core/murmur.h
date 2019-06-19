/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once

#include "core/types.h"

namespace haydn
{
u32 murmur32(const void* key, u32 len, u32 seed);
u64 murmur64(const void* key, u32 len, u64 seed);

} // namespace haydn
