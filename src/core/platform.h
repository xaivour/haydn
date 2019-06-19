/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

// Adapted from Branimir Karadžić's platform.h (https://github.com/bkaradzic/bx)

#pragma once

#define HAYDN_COMPILER_CLANG 0
#define HAYDN_COMPILER_GCC 0
#define HAYDN_COMPILER_MSVC 0

#define HAYDN_PLATFORM_ANDROID 0
#define HAYDN_PLATFORM_IOS 0
#define HAYDN_PLATFORM_LINUX 0
#define HAYDN_PLATFORM_OSX 0
#define HAYDN_PLATFORM_WINDOWS 0

#define HAYDN_CPU_ARM  0
#define HAYDN_CPU_JIT  0
#define HAYDN_CPU_MIPS 0
#define HAYDN_CPU_PPC  0
#define HAYDN_CPU_X86  0

#define HAYDN_ARCH_32BIT 0
#define HAYDN_ARCH_64BIT 0

#define HAYDN_CPU_ENDIAN_BIG 0
#define HAYDN_CPU_ENDIAN_LITTLE 0

// http://sourceforge.net/apps/mediawiki/predef/index.php?title=Compilers
#if defined(_MSC_VER)
	#undef HAYDN_COMPILER_MSVC
	#define HAYDN_COMPILER_MSVC 1
#elif defined(__clang__)
	// clang defines __GNUC__
	#undef HAYDN_COMPILER_CLANG
	#define HAYDN_COMPILER_CLANG 1
#elif defined(__GNUC__)
	#undef HAYDN_COMPILER_GCC
	#define HAYDN_COMPILER_GCC 1
#else
	#error "HAYDN_COMPILER_* is not defined!"
#endif

// http://sourceforge.net/apps/mediawiki/predef/index.php?title=Operating_Systems
#if defined(_WIN32) || defined(_WIN64)
	#undef HAYDN_PLATFORM_WINDOWS
// http://msdn.microsoft.com/en-us/library/6sehtctf.aspx
	#if !defined(WINVER) && !defined(_WIN32_WINNT)
// Windows 7 and above
		#define WINVER 0x0601
		#define _WIN32_WINNT 0x0601
	#endif // !defined(WINVER) && !defined(_WIN32_WINNT)
	#define HAYDN_PLATFORM_WINDOWS 1
#elif defined(__ANDROID__)
// Android compiler defines __linux__
	#undef HAYDN_PLATFORM_ANDROID
	#define HAYDN_PLATFORM_ANDROID 1
#elif defined(__linux__)
	#undef HAYDN_PLATFORM_LINUX
	#define HAYDN_PLATFORM_LINUX 1
#elif defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)
	#undef HAYDN_PLATFORM_IOS
	#define HAYDN_PLATFORM_IOS 1
#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
	#undef HAYDN_PLATFORM_OSX
	#define HAYDN_PLATFORM_OSX 1
#else
#	error "HAYDN_PLATFORM_* is not defined!"
#endif

#define HAYDN_PLATFORM_POSIX (HAYDN_PLATFORM_ANDROID \
						|| HAYDN_PLATFORM_IOS \
						|| HAYDN_PLATFORM_LINUX \
						|| HAYDN_PLATFORM_OSX)

// http://sourceforge.net/apps/mediawiki/predef/index.php?title=Architectures
#if defined(__arm__)
	#undef HAYDN_CPU_ARM
	#define HAYDN_CPU_ARM 1
	#define HAYDN_CACHE_LINE_SIZE 64
#elif defined(__MIPSEL__) || defined(__mips_isa_rev) // defined(mips)
	#undef HAYDN_CPU_MIPS
	#define HAYDN_CPU_MIPS 1
	#define HAYDN_CACHE_LINE_SIZE 64
#elif defined(_M_PPC) || defined(__powerpc__) || defined(__powerpc64__)
	#undef HAYDN_CPU_PPC
	#define HAYDN_CPU_PPC 1
	#define HAYDN_CACHE_LINE_SIZE 128
#elif defined(_M_IX86) || defined(_M_X64) || defined(__i386__) || defined(__x86_64__)
	#undef HAYDN_CPU_X86
	#define HAYDN_CPU_X86 1
	#define HAYDN_CACHE_LINE_SIZE 64
#else // PNaCl doesn't have CPU defined.
	#undef HAYDN_CPU_JIT
	#define HAYDN_CPU_JIT 1
	#define HAYDN_CACHE_LINE_SIZE 64
#endif //

#if defined(__x86_64__) || defined(_M_X64) || defined(__64BIT__) || defined(__powerpc64__) || defined(__ppc64__)
	#undef HAYDN_ARCH_64BIT
	#define HAYDN_ARCH_64BIT 64
#else
	#undef HAYDN_ARCH_32BIT
	#define HAYDN_ARCH_32BIT 32
#endif //

#if HAYDN_CPU_PPC
	#undef HAYDN_CPU_ENDIAN_BIG
	#define HAYDN_CPU_ENDIAN_BIG 1
#else
	#undef HAYDN_CPU_ENDIAN_LITTLE
	#define HAYDN_CPU_ENDIAN_LITTLE 1
#endif

#if HAYDN_COMPILER_GCC
	#define HAYDN_COMPILER_NAME "GCC"
#elif HAYDN_COMPILER_MSVC
	#define HAYDN_COMPILER_NAME "MSVC"
#endif

#if HAYDN_PLATFORM_ANDROID
	#define HAYDN_PLATFORM_NAME "android"
#elif HAYDN_PLATFORM_IOS
	#define HAYDN_PLATFORM_NAME "ios"
#elif HAYDN_PLATFORM_LINUX
	#define HAYDN_PLATFORM_NAME "linux"
#elif HAYDN_PLATFORM_OSX
	#define HAYDN_PLATFORM_NAME "osx"
#elif HAYDN_PLATFORM_WINDOWS
	#define HAYDN_PLATFORM_NAME "windows"
#endif // HAYDN_PLATFORM_

#if HAYDN_CPU_ARM
	#define HAYDN_CPU_NAME "ARM"
#elif HAYDN_CPU_MIPS
	#define HAYDN_CPU_NAME "MIPS"
#elif HAYDN_CPU_PPC
	#define HAYDN_CPU_NAME "PowerPC"
#elif HAYDN_CPU_JIT
	#define HAYDN_CPU_NAME "JIT-VM"
#elif HAYDN_CPU_X86
	#define HAYDN_CPU_NAME "x86"
#endif // HAYDN_CPU_

#if HAYDN_ARCH_32BIT
	#define HAYDN_ARCH_NAME "32-bit"
#elif HAYDN_ARCH_64BIT
	#define HAYDN_ARCH_NAME "64-bit"
#endif // HAYDN_ARCH_
