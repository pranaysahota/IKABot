#pragma once

#ifndef CONFIGURESERVICE_H
#define CONFIGURESERVICE_H

#include <aws\core\client\ClientConfiguration.h>
#include <aws/core/utils/ratelimiter/DefaultRateLimiter.h>
#include "Constants.h"

class ConfigureService {
private:
	Aws::Client::ClientConfiguration config;
public:
	ConfigureService() {
		std::shared_ptr<Aws::Utils::RateLimits::RateLimiterInterface> Limiter;
		Limiter = Aws::MakeShared<Aws::Utils::RateLimits::DefaultRateLimiter<>>(BotConstants::ALLOCATION_TAG, 200000);
		config.scheme = Aws::Http::Scheme::HTTPS;
		config.connectTimeoutMs = 30000;
		config.requestTimeoutMs = 30000;
		config.readRateLimiter = Limiter;
		config.writeRateLimiter = Limiter;
	}
	Aws::Client::ClientConfiguration getConfiguration() {
		return config;
	}
};

#endif