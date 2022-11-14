#include "Flag.h"

#include<string>
#include<iostream>

bool Flag::check_flag(std::string base_str, std::string f_flag)
{
	bool __parse_flag__ = false;
	std::size_t localnpos = std::string::npos;
	std::size_t found_flag = base_str.find(f_flag);
	if (!f_flag.empty() && !base_str.empty()) { __parse_flag__ = (found_flag != localnpos); }
	return __parse_flag__;
}