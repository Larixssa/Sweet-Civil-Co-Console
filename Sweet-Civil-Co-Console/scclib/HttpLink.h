#ifndef HTTPLINK_H
#define HTTPLINK_H

#include<string>

class HttpLink
{
public:
	static std::string DEFAULT_HTTPS_PROTOCOL;
	static std::string DEFAULT_HTTP_PROTOCOL;
	static std::string DEFAULT_WWW_PROTOCOL;
	static std::string init_link(std::string url, std::string _protocol_);
	static std::string get_link(std::string parse_url, std::string protocol = "https");
	static void out_link(std::string link_url, std::string protocol = "https");
	static void open_link(std::string link);
};

#endif