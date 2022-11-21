#ifndef PLATFORMVARS_H
#define PLATFORMVARS_H

#include<string>

class PLATFORM_VARS
{
public:
	static std::string CURRENT_PLATFORM;
	static bool __IS_WINDOWS__;
	static bool __IS_LINUX__;
	static bool __IS_DEFAULT__;
	// static bool __IS_MAC__;
};

#endif