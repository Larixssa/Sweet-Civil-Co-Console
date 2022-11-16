#ifndef STRUTILS_H
#define STRUTILS_H

#include<string>

class STRING_UTILS
{
public:
	static bool starts_with(const std::string& str, const std::string& prefix);
	static std::string quote_string(std::string str);
	static std::string itostr(int n);
	static std::string ftostr(float n);
	static std::string dtostr(double n);
};

#endif
