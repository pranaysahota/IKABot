// IKABot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <aws\core\Aws.h>

int main()
{
	Aws::SDKOptions options;
	Aws::InitAPI(options);
	std::cout << "Hello!" << std::endl;
	Aws::ShutdownAPI(options);
    return 0;
}

