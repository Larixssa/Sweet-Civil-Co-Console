#ifndef HTTPLINK_H
#define HTTPLINK_H

#include<string>

class HttpLink
{
public:
	static std::string DEFAULT_HTTPS_PROTOCOL;
	static std::string DEFAULT_HTTP_PROTOCOL;
	static std::string DEFAULT_WWW_PROTOCOL;
	static std::string https_init_link(std::string url);
	static std::string http_init_link(std::string url);
	static std::string www_init_link(std::string url);
	static std::string get_link(std::string parse_url, std::string protocol = "https");
	static void out_link(std::string link_url, std::string protocol = "https");
	static void open_link(std::string link);
};

#endif