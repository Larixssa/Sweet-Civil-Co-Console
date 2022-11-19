#include "ClientInfo.h"
#include "../scclib/Strutils.h"
#include "../scclib/Swtio.h"

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
		if (STRING_UTILS::strcmpr(client_info, "main") || STRING_UTILS::strcmpr(client_info, "console")) {
			Swtio::cput("\n" + ClientInfo::get_client_version() + "\n\n");
		} else if (STRING_UTILS::strcmpr(client_info, "release") || STRING_UTILS::strcmpr(client_info, "build")) {
			Swtio::cput("\n" + ClientInfo::get_client_release() + "\n\n");
		} else if (STRING_UTILS::strcmpr(client_info, "default")) {
			Swtio::cput("\n" + ClientInfo::get_client_info() + "\n\n");
		}
	}
}