#include "ConsoleMessage.h"
#include "../scclib/Strutils.h"

#include<string>
#include<ctime>

std::string ConsoleMessage::DEFAULT_CONSOLE_HEADER = "[Console]";

std::string ConsoleMessage::create_console_message(std::string msg, bool include_console_header)
{
	std::string fcontent;
	if (!msg.empty())
	{
		if (include_console_header) {
			fcontent = ConsoleMessage::DEFAULT_CONSOLE_HEADER + " - " + msg;
		} else {
			fcontent = msg;
		}
	}
	return fcontent;
}

std::string ConsoleMessage::advanced_console_message(std::string msg, bool cl_header, bool user_header)
{
	std::string fcontent;
	if (!msg.empty())
	{
		if (cl_header)
		{
			if (user_header) {
				fcontent = DEFAULT_CONSOLE_HEADER + " @  (usr/console) ~ " + msg;
			} else {
				fcontent = DEFAULT_CONSOLE_HEADER + " ~ " + msg;
			}
		} else {
			fcontent = msg;
		}
	}
	return fcontent;
}