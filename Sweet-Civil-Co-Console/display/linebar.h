#ifndef LINEBAR_H
#define LINEBAR_H

#include<string>

class LineBar
{
public:
	static std::string create_linebar(std::string linebar_str = "-", int linebar_length = 35);
};

#endif