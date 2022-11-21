#ifndef OPTION_H
#define OPTION_H

#include<string>

class Option
{
public:
	static std::string create_option(std::string name, std::string description);
	static void push_options(std::string optionslist[], std::string optionsdesclist[], int optionslist_size);
};

#endif