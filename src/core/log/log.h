/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once 

#include <spdlog/spdlog.h>

namespace haydn {
	namespace log_internals {
			extern std::shared_ptr<spdlog::logger> internal_logger;
			extern std::shared_ptr<spdlog::logger> client_logger;
  	        
  	        void init();
	}
}

#define HY_ERROR(...) ::haydn::log_internals::client_logger->error(__VA_ARGS__);
#define HY_WARN(...) ::haydn::log_internals::client_logger->warn(__VA_ARGS__);
#define HY_TRACE(...) ::haydn::log_internals::client_logger->trace(__VA_ARGS__);
#define HY_DEBUG(...) ::haydn::log_internals::client_logger->debug(__VA_ARGS__);
#define HY_INFO(...) ::haydn::log_internals::client_logger->info(__VA_ARGS__);
#define HY_CRITICAL(...) ::haydn::log_internals::client_logger->critical(__VA_ARGS__);

#define HY_INTERNAL_ERROR(...) ::haydn::log_internals::internal_logger->error(__VA_ARGS__);
#define HY_INTERNAL_WARN(...) ::haydn::log_internals::internal_logger->warn(__VA_ARGS__);
#define HY_INTERNAL_TRACE(...) ::haydn::log_internals::internal_logger->trace(__VA_ARGS__);
#define HY_INTERNAL_DEBUG(...) ::haydn::log_internals::internal_logger->debug(__VA_ARGS__);
#define HY_INTERNAL_INFO(...) ::haydn::log_internals::internal_logger->info(__VA_ARGS__);
#define HY_INTERNAL_CRITICAL(...) ::haydn::log_internals::internal_logger->critical(__VA_ARGS__);
