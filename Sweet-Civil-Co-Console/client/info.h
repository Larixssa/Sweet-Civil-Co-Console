#ifndef INFO_H
#define INFO_H

#include<string>

class ClientInfo
{
public:
	static std::string CLIENT_NAME;
	static std::string CLIENT_VERSION;
	static std::string CLIENT_BUILD;
	static std::string get_client_info();
	static std::string get_client_version();
	static std::string get_client_release();
	static void get_client_info_of(std::string client_info = "default");
};

#endif