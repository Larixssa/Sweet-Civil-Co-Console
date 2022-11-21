#ifndef STRUTILS_H
#define STRUTILS_H

#include<string>

class STRING_UTILS
{
public:
	static bool starts_with(const std::string& str, const std::string& prefix);
	static bool strcmpr(std::string sstr, std::string tstr);
	static bool cmpr(std::string a, std::string b);
	static std::string quote_string(std::string str);
	static std::string to_upper_string(std::string str);
	static std::string to_lower_string(std::string str);
};

#endif
