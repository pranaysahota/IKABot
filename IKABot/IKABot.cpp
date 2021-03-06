// IKABot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <aws\lex\LexRuntimeServiceClient.h>
#include <aws\lex\model\PostTextRequest.h>
#include <aws\lex\model\PostTextResult.h>
#include <string>
#include "ClientHandler.h"
#include "ConfigureService.h"
#include "RequestGenerator.h"

int main()
{
	Aws::SDKOptions options;
	Aws::InitAPI(options);

	Aws::LexRuntimeService::Model::PostTextOutcome outcome;
	Aws::LexRuntimeService::Model::PostTextResult result;
	Aws::LexRuntimeService::Model::PostTextRequest userRequest;

	ConfigureService configService;
	Aws::Client::ClientConfiguration config = configService.getConfiguration();
	ClientHandler clientHandler(config);
			
	std::cout << "**************WELCOME TO IKA BOT****************"<<std::endl;
	std::cout << "Enter your question below! \nOr type Bye to exit bot once finished.." << std::endl<<std::endl;

	while (true) {
		std::string input;
		std::getline(std::cin, input);
		if (input != "Bye") {
			RequestGenerator requestGenerator(input);
			userRequest = requestGenerator.getRequestObject();
			outcome = clientHandler.getOutcome(userRequest);
			result = outcome.GetResult();
			std::cout << result.GetMessage() << std::endl<<std::endl;
		}
		else {
			std::cout << "\nGoodbye!!";
			break;
		}
	}
	Aws::ShutdownAPI(options);
    return 0;
}

