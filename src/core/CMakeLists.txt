add_library(core STATIC command_line.cpp 
	                    command_line.h
	                    functional.h
	                    murmur.cpp
	                    murmur.h
	                    pair.h
	                    platform.h
	                    types.h)

target_link_libraries(core PUBLIC spdlog::spdlog)

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
	error/callstack_windows.cpp
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

# log sources 
target_sources(core PRIVATE
	log/log.cpp
	log/log.h)

# thread sources
target_sources(core PRIVATE
	thread/atomic_int.cpp
	thread/atomic_int.h
	thread/condition_variable.cpp
	thread/condition_variable.h
	thread/mutex.cpp
	thread/mutex.h
	thread/scoped_mutex.h
	thread/semaphore.cpp
	thread/semaphore.h
	thread/thread.cpp
	thread/thread.h
	thread/types.h)






