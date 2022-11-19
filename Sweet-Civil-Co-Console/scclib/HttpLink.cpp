#include "HttpLink.h"
#include "../sys_utils/Platform.h"
#include "../sys_utils/SysExec.h"
#include "../scclib/Swtio.h"
#include "../scclib/Strutils.h"

#include<string>

std::string HttpLink::DEFAULT_HTTPS_PROTOCOL = "https://";
std::string HttpLink::DEFAULT_HTTP_PROTOCOL = "http://";
std::string HttpLink::DEFAULT_WWW_PROTOCOL = "www.";

/// <summary>
/// <para>Initialize a link with the a protocol.</para>
/// <para>> HTTPS, HTTP, WWW.</para>
/// </summary>
std::string HttpLink::init_link(std::string url, std::string _protocol_)
{
	std::string furl;
	std::string fprot;
	if (!url.empty() && !_protocol_.empty())
	{
		if (STRING_UTILS::strcmpr(_protocol_, "https"))
			{ fprot = HttpLink::DEFAULT_HTTPS_PROTOCOL; }
		else if (STRING_UTILS::strcmpr(_protocol_, "http"))
			{ fprot = HttpLink::DEFAULT_HTTP_PROTOCOL; }
		else if (STRING_UTILS::strcmpr(_protocol_, "www"))
			{ fprot = HttpLink::DEFAULT_WWW_PROTOCOL; }
		furl = fprot + url;
	}
	return furl;
}

std::string HttpLink::get_link(std::string parse_url, std::string protocol) {
	std::string full_url;
	if (!parse_url.empty() && !protocol.empty()) {
		full_url = init_link(parse_url, protocol);
	}
	return full_url;
}

void HttpLink::out_link(std::string link_url, std::string protocol) {
	std::string purl = HttpLink::get_link(link_url, protocol);
	if (!link_url.empty() && !protocol.empty()) {
		Swtio::cput(purl);
	}
}

void HttpLink::open_link(std::string link) {
	std::string command_prefix;
	if (!link.empty()) {
		if (Platform::check_platform("Windows")) {
			if (!STRING_UTILS::starts_with(link, "https://")) {
				command_prefix = "start " + get_link(link);
			} else {
				command_prefix = "start " + link;
			}
		} else if (Platform::check_platform("Linux")) {
			if (!STRING_UTILS::starts_with(link, "https://")) {
				command_prefix = "xdg-open " + get_link(link);
			} else {
				command_prefix = "xdg-open " + link;
			}
		}
		System_Exec::exec_command(command_prefix);
	}
}