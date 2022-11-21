#ifndef CONVERT_H
#define CONVERT_H

#include<string>

class Convert
{
public:
	static int strtoi(std::string str);
	static float strtof(std::string str);
	static double strtod(std::string str);
	static std::string itostr(int n);
	static std::string ftostr(float n);
	static std::string dtostr(double n);
};

#endif