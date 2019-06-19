/*
 * Copyright (c) 2019 Rajat and individual contributors.
 * License: https://github.com/rayl/haydn/blob/master/LICENSE
 */

#pragma once 

#include <spdlog/spdlog.h>

namespace hyden {
	namespace log_internals {
			std::shared_ptr<spdlog::logger> internal_logger;
			std::shared_ptr<spdlog::logger> client_logger;
  	        
  	        void init();
	}
}

#define HY_ERROR(...) ::hyden::log_internals::client_logger->error(__VA_ARGS__);
#define HY_WARN(...) ::hyden::log_internals::client_logger->warn(__VA_ARGS__);
#define HY_TRACE(...) ::hyden::log_internals::client_logger->trace(__VA_ARGS__);
#define HY_DEBUG(...) ::hyden::log_internals::client_logger->debug(__VA_ARGS__);
#define HY_INFO(...) ::hyden::log_internals::client_logger->info(__VA_ARGS__);
#define HY_CRITICAL(...) ::hyden::log_internals::client_logger->critical(__VA_ARGS__);

#define HY_INTERNAL_ERROR(...) ::hyden::log_internals::internal_logger->error(__VA_ARGS__);
#define HY_INTERNAL_WARN(...) ::hyden::log_internals::internal_logger->warn(__VA_ARGS__);
#define HY_INTERNAL_TRACE(...) ::hyden::log_internals::internal_logger->trace(__VA_ARGS__);
#define HY_INTERNAL_DEBUG(...) ::hyden::log_internals::internal_logger->debug(__VA_ARGS__);
#define HY_INTERNAL_INFO(...) ::hyden::log_internals::internal_logger->info(__VA_ARGS__);
#define HY_INTERNAL_CRITICAL(...) ::hyden::log_internals::internal_logger->critical(__VA_ARGS__);
