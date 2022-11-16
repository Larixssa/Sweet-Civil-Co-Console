#include "HttpLink.h"
#include "../sys_utils/Platform.h"
#include "../sys_utils/SysExec.h"
#include "../scclib/Swtio.h"

#include<string>

std::string HttpLink::DEFAULT_HTTPS_PROTOCOL = "https://";
std::string HttpLink::DEFAULT_HTTP_PROTOCOL = "http://";
std::string HttpLink::DEFAULT_WWW_PROTOCOL = "www.";

/// <summary>
/// Initialize a link with the HTTPS protocol.
/// </summary>
std::string HttpLink::https_init_link(std::string url) {
	std::string fhttpsurl;
	if (!url.empty()) { fhttpsurl = HttpLink::DEFAULT_HTTPS_PROTOCOL + url; }
	return fhttpsurl;
}

/// <summary>
/// Initialize a link with the HTTP protocol.
/// </summary>
std::string HttpLink::http_init_link(std::string url) {
	std::string fhttpurl;
	if (!url.empty()) { fhttpurl = HttpLink::DEFAULT_HTTP_PROTOCOL + url; }
	return fhttpurl;
}

/// <summary>
/// Initialize a link with the WWW prefix.
/// </summary>
std::string HttpLink::www_init_link(std::string url) {
	std::string fwwwurl;
	if (!url.empty()) { fwwwurl = HttpLink::DEFAULT_WWW_PROTOCOL + url; }
	return fwwwurl;
}

std::string HttpLink::get_link(std::string parse_url, std::string protocol) {
	std::string full_url;
	if (protocol.compare("https")) { full_url = https_init_link(parse_url); }
	else if (protocol.compare("http")) { full_url = http_init_link(parse_url); }
	else if (protocol.compare("www")) { full_url = www_init_link(parse_url); }
	return full_url;
}

void HttpLink::out_link(std::string link_url, std::string protocol) {
	std::string purl = HttpLink::get_link(link_url, protocol);
	if (!link_url.empty() && !protocol.empty()) {
		Swtio::cput(purl);
	}
}

void HttpLink::open_link(std::string link) {
	if (!link.empty()) {
		if (Platform::get_platform() == "Windows") {
			System_Exec::exec_command("start " + link);
		} else if (Platform::get_platform() == "Linux") {
			System_Exec::exec_command("xdg-open " + link);
		}
	}
}