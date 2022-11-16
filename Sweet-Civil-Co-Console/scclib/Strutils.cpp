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

std::string STRING_UTILS::itostr(int n) { return std::to_string(n); }
std::string STRING_UTILS::ftostr(float n) { return std::to_string(n); }
std::string STRING_UTILS::dtostr(double n) { return std::to_string(n); }