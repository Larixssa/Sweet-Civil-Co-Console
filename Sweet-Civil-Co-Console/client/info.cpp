#include "info.h"

#include<iostream>

std::string ClientInfo::CLIENT_NAME = "Sweet Civil Corporation. [Console]";
std::string ClientInfo::CLIENT_VERSION = "0.0.1";
std::string ClientInfo::CLIENT_BUILD = "PUBLIC BUILD (0.213.1)";

std::string ClientInfo::get_client_info()
{
	std::string full_string = "Name: " + ClientInfo::CLIENT_NAME +
		"\nConsole Version: " + ClientInfo::CLIENT_VERSION +
		"\nRelease Build: " + ClientInfo::CLIENT_BUILD;
	return full_string;
}

std::string ClientInfo::get_client_version()
{
	return "Console Version: " + ClientInfo::CLIENT_VERSION;
}

std::string ClientInfo::get_client_release()
{
	return "Release Build: " + ClientInfo::CLIENT_BUILD;
}

void ClientInfo::get_client_info_of(std::string client_info)
{
	if (!client_info.empty())
	{
		if (client_info.compare("main") == 0 || client_info.compare("console") == 0) {
			std::cout << "\n" << ClientInfo::get_client_version() << "\n\n";
		} else if (client_info.compare("release") == 0 || client_info.compare("build") == 0) {
			std::cout << "\n" << ClientInfo::get_client_release() << "\n\n";
		} else if (client_info.compare("default") == 0) {
			std::cout << "\n" << ClientInfo::get_client_info() << "\n\n";
		}
	}
}