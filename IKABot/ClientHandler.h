#pragma once

#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <aws\lex\model\PostTextRequest.h>
#include <aws\lex\model\PostTextResult.h>
#include <aws\core\utils\Outcome.h>
#include <aws\lex\LexRuntimeServiceClient.h>
#include <aws\core\auth\AWSCredentialsProvider.h>
#include <aws\core\Aws.h>
#include "Constants.h"

class ClientHandler {
private:
	std::shared_ptr<Aws::LexRuntimeService::LexRuntimeServiceClient> client;
public:
	ClientHandler(Aws::Client::ClientConfiguration &config) {
		client = Aws::MakeShared<Aws::LexRuntimeService::LexRuntimeServiceClient>(BotConstants::ALLOCATION_TAG, Aws::Auth::AWSCredentials("AKIAIHG4QIOHTEEPHD6Q", "+p75+6NR+jiOlYh9Xi8KxXd3IDGw9ziQiZZ/Hrcz"), config);
	}
	Aws::LexRuntimeService::Model::PostTextOutcome getOutcome(Aws::LexRuntimeService::Model::PostTextRequest &request) {
		return client->PostText(request);
	}
};


#endif