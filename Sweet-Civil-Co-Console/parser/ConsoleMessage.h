#ifndef CONSOLEMESSAGE_H
#define CONSOLEMESSAGE_H

#include<string>

class ConsoleMessage
{
public:
	static std::string DEFAULT_CONSOLE_HEADER;
	static std::string create_console_message(std::string msg, bool include_console_header);
	static std::string advanced_console_message(std::string msg, bool cl_header, bool user_header);
};

#endif