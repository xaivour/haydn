/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#include "core/error/error.h"
#include "core/platform.h"
#include "core/thread/mutex.h"

#if HAYDN_PLATFORM_POSIX
	#include <pthread.h>
#elif HAYDN_PLATFORM_WINDOWS
	#include <windows.h>
#endif

namespace haydn
{
struct Private
{
#if HAYDN_PLATFORM_POSIX
	pthread_mutex_t mutex;
#elif HAYDN_PLATFORM_WINDOWS
	CRITICAL_SECTION cs;
#endif
};

Mutex::Mutex()
{
	HY_STATIC_ASSERT(sizeof(_data) >= sizeof(Private));
	Private* priv = (Private*)_data;

#if HAYDN_PLATFORM_POSIX
	pthread_mutexattr_t attr;
	int err = pthread_mutexattr_init(&attr);
	HY_ASSERT(err == 0, "pthread_mutexattr_init: errno = %d", err);
	err = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
	HY_ASSERT(err == 0, "pthread_mutexattr_settype: errno = %d", err);
	err = pthread_mutex_init(&priv->mutex, &attr);
	HY_ASSERT(err == 0, "pthread_mutex_init: errno = %d", err);
	err = pthread_mutexattr_destroy(&attr);
	HY_ASSERT(err == 0, "pthread_mutexattr_destroy: errno = %d", err);
	HY_UNUSED(err);
#elif HAYDN_PLATFORM_WINDOWS
	InitializeCriticalSection(&priv->cs);
#endif
}

Mutex::~Mutex()
{
	Private* priv = (Private*)_data;

#if HAYDN_PLATFORM_POSIX
	int err = pthread_mutex_destroy(&priv->mutex);
	HY_ASSERT(err == 0, "pthread_mutex_destroy: errno = %d", err);
	HY_UNUSED(err);
#elif HAYDN_PLATFORM_WINDOWS
	DeleteCriticalSection(&priv->cs);
#endif
}

void Mutex::lock()
{
	Private* priv = (Private*)_data;

#if HAYDN_PLATFORM_POSIX
	int err = pthread_mutex_lock(&priv->mutex);
	HY_ASSERT(err == 0, "pthread_mutex_lock: errno = %d", err);
	HY_UNUSED(err);
#elif HAYDN_PLATFORM_WINDOWS
	EnterCriticalSection(&priv->cs);
#endif
}

void Mutex::unlock()
{
	Private* priv = (Private*)_data;

#if HAYDN_PLATFORM_POSIX
	int err = pthread_mutex_unlock(&priv->mutex);
	HY_ASSERT(err == 0, "pthread_mutex_unlock: errno = %d", err);
	HY_UNUSED(err);
#elif HAYDN_PLATFORM_WINDOWS
	LeaveCriticalSection(&priv->cs);
#endif
}

void* Mutex::native_handle()
{
	Private* priv = (Private*)_data;

#if HAYDN_PLATFORM_POSIX
	return &priv->mutex;
#elif HAYDN_PLATFORM_WINDOWS
	return &priv->cs;
#endif
}

} // namespace haydn
