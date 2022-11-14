#include "Strutils.h"

#include <string>

bool STRING_UTILS::starts_with(const std::string& str, const std::string& prefix)
{
	return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}