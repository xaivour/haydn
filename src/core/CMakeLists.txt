add_library(core STATIC command_line.cpp 
	                    command_line.h
	                    functional.h
	                    murmur.cpp
	                    murmur.h
	                    pair.h
	                    platform.h
	                    types.h)

target_link_libraries(core PRIVATE spdlog::spdlog)

# container sources 
target_sources(core PRIVATE
	containers/array.h
	containers/event_stream.h
	containers/hash_map.h
	containers/hash_set.h
	containers/queue.h
	containers/types.h
	containers/vector.h)

# error sources
target_sources(core PRIVATE
	error/callstack.h
	error/callstack_android.cpp
	error/callstack_linux.cpp
	error/error.cpp
	error/error.h)

# json sources
target_sources(core PRIVATE
	json/json.cpp
	json/json.h
	json/json_object.h
	json/sjson.cpp
	json/sjson.h
	json/types.h)

# memory sources
target_sources(core PRIVATE
	memory/allocator.h
	memory/linear_allocator.cpp
	memory/linear_allocator.h
	memory/memory.cpp
	memory/memory.h
	memory/pool_allocator.cpp
	memory/pool_allocator.h
	memory/proxy_allocator.cpp
	memory/proxy_allocator.h
	memory/stack_allocator.cpp
	memory/stack_allocator.h
	memory/temp_allocator.h
	memory/types.h)

# network sources
target_sources(core PRIVATE
	network/ip_address.h
	network/socket.cpp
	network/socket.h
	network/types.h)

# string sources
target_sources(core PRIVATE
	strings/dynamic_string.cpp
	strings/dynamic_string.h
	strings/fixed_string.h
	strings/string.h
	strings/string_id.cpp
	strings/string_id.h
	strings/string_stream.h
	strings/types.h 
	strings/utf8.cpp 
	strings/utf8.h)






