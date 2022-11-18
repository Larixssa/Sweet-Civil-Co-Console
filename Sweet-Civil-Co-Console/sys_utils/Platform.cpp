#include "Platform.h"
#include "../scclib/Strutils.h"

#include<string>

std::string Platform::get_platform()
{
	std::string os_str;
	#ifdef __linux__
	os_str = "Linux";
	#elif _WIN32
	os_str = "Windows";
	#else
	os_str = "Default";
	#endif
	return os_str;
}

bool Platform::check_platform(std::string current_platform)
{
	bool in_platform = (STRING_UTILS::strcmpr(Platform::get_platform(), current_platform) ? true : false); return in_platform;
}