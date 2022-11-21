#include "Strutils.h"

#include <string>

bool STRING_UTILS::starts_with(const std::string& str, const std::string& prefix)
{
	return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}

std::string STRING_UTILS::quote_string(std::string str)
{
	std::string fstr = "\"" + str + "\"";  return fstr;
}

bool STRING_UTILS::strcmpr(std::string sstr, std::string tstr)
{
	return sstr.compare(tstr) == 0;
}

bool STRING_UTILS::cmpr(std::string a, std::string b)
{
	return a.compare(b);
}

std::string STRING_UTILS::to_upper_string(std::string str)
{
	std::string new_str;
	for (int i = 0; i < str.length(); i++) { new_str[i] = toupper(str[i]); }
	return new_str;
}

std::string STRING_UTILS::to_lower_string(std::string str)
{
	std::string new_str;
	for (int i = 0; i < str.length(); i++) { new_str[i] = tolower(str[i]); }
	return new_str;
}