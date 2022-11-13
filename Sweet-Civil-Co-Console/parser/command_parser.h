#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include<string>

class Command_Parser
{
public:
	static void parse_command(std::string prs_cmd);
	static void command_handler(std::string cmd_to_parse);
	static void command_help_list();
};

#endif
