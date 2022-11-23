#ifndef COMMAND_H
#define COMMAND_H

#include<string>

class Command
{
public:
	static std::string DEFAULT_COMMAND_NAME;
	static std::string DEFAULT_COMMAND_DESCRIPTION;
	static std::string create_command(std::string name, std::string description);
	static bool check_command(std::string base_cmd, std::string p_cmd);
	static bool check_command_starts_with(std::string base_cmd, std::string p_cmd_starts);
};

#endif