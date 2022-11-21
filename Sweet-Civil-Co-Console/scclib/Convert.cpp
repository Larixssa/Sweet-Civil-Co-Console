#include "Convert.h"

#include<string>

int Convert::strtoi(std::string str)
{
	int converted_int;
	for (int i = 0; i < str.length(); i++) { converted_int = static_cast<int>(str[i]); }
	return converted_int;
}

float Convert::strtof(std::string str)
{
	float converted_float;
	for (int i = 0; i < str.length(); i++) { converted_float = static_cast<float>(str[i]); }
	return converted_float;
}

double Convert::strtod(std::string str)
{
	float converted_double;
	for (int i = 0; i < str.length(); i++) { converted_double = static_cast<double>(str[i]); }
	return converted_double;
}

std::string Convert::itostr(int n) { return std::to_string(n); }
std::string Convert::ftostr(float n) { return std::to_string(n); }
std::string Convert::dtostr(double n) { return std::to_string(n); }