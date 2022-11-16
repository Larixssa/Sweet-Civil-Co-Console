#include "CommandParser.h"
#include "../command_utils/Command.h"
#include "../command_utils/Flag.h"
#include "../sys_utils/SysExec.h"
#include "../init/Init.h"
#include "../client/ClientInfo.h"
#include "../client/GitInfo.h"
#include "../scclib/Swtio.h"

#include<string>

void Command_Parser::command_help_list()
{
	const int default_arr_size = 5;

	std::string command_table[default_arr_size] = {
		"help",
		"exit",
		"version",
		"git",
		"clear"
	};

	std::string command_descriptions[default_arr_size] = {
		"Show information and list for commands.",
		"Exit the console.",
		"Get the version of the console.",
		"Output the repository info and link.",
		"Clear the screen."
	};

	Swtio::cput("\n-- Command List --\n\n");

	for (int i = 0; i < default_arr_size; i++) {
		Swtio::cput(Command::create_command(command_table[i], command_descriptions[i]) + "\n");
	}

	Swtio::cput("\n");
}

void Command_Parser::command_handler(std::string cmd_to_parse)
{
	const int default_cmd_table_size = 5;

	std::string local_cmd_table[default_cmd_table_size] = {
		"help", "clear", "version",
		"git", "exit"
	};

	bool do_parse = false;

	for (int i = 0; i < default_cmd_table_size; i++) {
		if (cmd_to_parse.compare(local_cmd_table[i])) {
			do_parse = true;
		}
	}
	
	if (do_parse) { Command_Parser::parse_command(cmd_to_parse); }
}

void Command_Parser::parse_command(std::string prs_cmd)
{

	bool DEFAULT_REINIT_VAL = false;

	if (!prs_cmd.empty())
	{

		if (Command::check_command(prs_cmd, "help")) {
			Command_Parser::command_help_list();
		}

		if (Command::check_command(prs_cmd, "clear")) {
			System_Exec::clear_screen();
		}

		if (Command::check_command_starts_with(prs_cmd, "version")) {
			if (Flag::check_flag(prs_cmd, "--console")) {
				ClientInfo::get_client_info_of("main");
			} else if (Flag::check_flag(prs_cmd, "--release")) {
				ClientInfo::get_client_info_of("release");
			} else {
				ClientInfo::get_client_info_of();
			}
		}

		if (Command::check_command(prs_cmd, "git")) {
			GitInfo::out_repo_info();
		}
		
		if (!Command::check_command(prs_cmd, "exit")) {
			INIT::init_client(
				DEFAULT_REINIT_VAL, 
				DEFAULT_REINIT_VAL, 
				DEFAULT_REINIT_VAL
			);
		} else { System_Exec::exit_client(); }

	}

}
