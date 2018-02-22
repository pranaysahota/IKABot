// IKABot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <aws\core\Aws.h>
#include <aws\lex\LexRuntimeServiceClient.h>
#include <aws\lex\model\PostTextRequest.h>
#include <aws\lex\model\PostTextResult.h>
#include <aws\core\utils\Outcome.h>
#include <aws\core\client\ClientConfiguration.h>
#include <aws\core\auth\AWSCredentialsProvider.h>
#include <aws/core/utils/ratelimiter/DefaultRateLimiter.h>
#include <aws\lex-models\LexModelBuildingService_EXPORTS.h>
#include <iostream>

const static char* ALLOCATION_TAG = "LexRuntimeServiceClient";

int main()
{
	Aws::SDKOptions options;
	Aws::InitAPI(options);

	Aws::Client::ClientConfiguration config;
	Aws::LexRuntimeService::Model::PostTextRequest request;
	Aws::LexRuntimeService::Model::PostTextOutcome response;
	std::shared_ptr<Aws::Utils::RateLimits::RateLimiterInterface> Limiter;

	Limiter = Aws::MakeShared<Aws::Utils::RateLimits::DefaultRateLimiter<>>(ALLOCATION_TAG, 200000);

	config.scheme = Aws::Http::Scheme::HTTPS;
	config.connectTimeoutMs = 30000;
	config.requestTimeoutMs = 30000;
	config.readRateLimiter = Limiter;
	config.writeRateLimiter = Limiter;

	auto client = Aws::MakeShared<Aws::LexRuntimeService::LexRuntimeServiceClient>(ALLOCATION_TAG, Aws::Auth::AWSCredentials("AKIAIHG4QIOHTEEPHD6Q", "+p75+6NR+jiOlYh9Xi8KxXd3IDGw9ziQiZZ/Hrcz"), config);
	
	request.SetBotName("IKABot");
	request.SetBotAlias("IKABot");
	request.SetUserId("Test123");
	request.SetInputText("what is IKA");
	response = client->PostText(request);
	Aws::ShutdownAPI(options);
    return 0;
}

