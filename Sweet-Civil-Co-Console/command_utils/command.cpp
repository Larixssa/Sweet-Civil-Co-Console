#include "Command.h"
#include "../scclib/Strutils.h"

#include<string>

std::string Command::create_command(std::string name, std::string description)
{
	std::string full_string;
	std::string DEFAULT_VALUE_NAME = "COMMAND_NAME";
	std::string DEFAULT_DESCRIPTION_VALUE = "COMMAND_DESCRIPTION_DATA";

	if (!name.empty() && !description.empty())
		{ full_string = "[" + name + "]" + " - " + description; }
	else 
		{ full_string = "[" + DEFAULT_VALUE_NAME + "]" + ": <" + DEFAULT_DESCRIPTION_VALUE + ">"; }

	return full_string;
}

bool Command::check_command(std::string base_cmd, std::string p_cmd)
{
	bool parsed = false;
	if (base_cmd.compare(p_cmd) == 0) { parsed = true; }
	return parsed;
}

bool Command::check_command_starts_with(std::string base_cmd, std::string p_cmd_starts)
{
	bool parsed = false;
	if (STRING_UTILS::starts_with(base_cmd, p_cmd_starts)) { parsed = true; }
	return parsed;
}
