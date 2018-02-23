#pragma once
#pragma comment(lib, "rpcrt4.lib")
#ifndef REQUESTGENERATOR_H
#define REQUESTGENERATOR_H

#include <aws\lex\model\PostTextRequest.h>
#include <string>
#include "Constants.h"
#include <sstream>


class RequestGenerator {
private:
	Aws::LexRuntimeService::Model::PostTextRequest request;
public:
	RequestGenerator(std::string userUtterance) {
		request.SetBotName(BotConstants::BOT_NAME);
		request.SetBotAlias(BotConstants::BOT_ALIAS);
		int random_id = rand() % 1000000 + 2000000;
		std::ostringstream str1;
		str1 << random_id;
		request.SetUserId(str1.str());
		request.SetInputText(userUtterance);
	}

	Aws::LexRuntimeService::Model::PostTextRequest getRequestObject() {
		return request;
	}
};

#endif