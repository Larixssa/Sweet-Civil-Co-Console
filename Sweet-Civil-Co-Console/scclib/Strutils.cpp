#include "Strutils.h"

#include <string>

bool STRING_UTILS::starts_with(const std::string& str, const std::string& prefix)
{
	return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}

std::string itostr(int n) { std::string istr = std::to_string(n); return istr; }
std::string ftostr(float n) { std::string fstr = std::to_string(n); return fstr; }
std::string dtostr(double n) { std::string dstr = std::to_string(n); return dstr; }