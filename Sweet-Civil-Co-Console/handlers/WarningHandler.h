#ifndef WARNING_HANDLER_H
#define WARNING_HANDLER_H

#include<string>

class WarningHandler
{
public:
	static std::string DEFAULT_WARNING_TYPE;
	static std::string DEFAULT_WARNING_MESSAGE;
	static void warning_handler(std::string whtype, std::string whval);
	static void throw_warning_incomplete_cmd(std::string vval);
	static void throw_warning_empty_prompt(std::string vval);
};

#endif