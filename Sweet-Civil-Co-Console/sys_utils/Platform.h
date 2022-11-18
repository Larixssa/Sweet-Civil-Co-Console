#ifndef PLATFORM_H
#define PLATFORM_H

#include<string>

class Platform
{
public:
	static std::string get_platform();
	static bool check_platform(std::string current_platform);
};

#endif