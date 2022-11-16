#include "Platform.h"

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