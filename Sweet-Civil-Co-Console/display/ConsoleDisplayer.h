#ifndef CONSOLEDISPLAYER_H
#define CONSOLEDISPLAYER_H

#include<string>

class ConsoleDisplayer
{
public:
	static void display_console_message(std::string msg, bool cl_header = true);
	static void display_advanced_console_message(std::string msg, bool cl_header = true, bool show_time = true);
};

#endif