#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include<string>

class CommandHandler
{
public:
	static void push_commands(std::string commands_list[], std::string command_descriptions[], int cmdlist_size);
	static void handle_command(std::string commands_list[], int cmdlist_size, std::string cmdio);
};

#endif