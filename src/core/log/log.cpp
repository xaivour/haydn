/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#include "log.h"
#include "core/platform.h"
#include <spdlog/sinks/android_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace haydn
{
	namespace log_internals
	{
        std::shared_ptr<spdlog::logger> internal_logger;
		std::shared_ptr<spdlog::logger> client_logger;

		void init()
		{
			spdlog::set_pattern("%^ [%T] %n: %v%$");
			#if HAYDN_PLATFORM_ANDROID
				internal_logger = spdlog::android_logger_mt("HYDEN");
				client_logger = spdlog::android_logger_mt("CLIENT");
			#endif

			internal_logger = spdlog::stderr_color_mt("HYDEN");
			client_logger = spdlog::stderr_color_mt("CLIENT");
		}
	}
}

