// DEFAULT INCLUDED HEADERS
#include "CommandParser.h"
#include "../command_utils/Command.h"
#include "../command_utils/Flag.h"
#include "../command_utils/CommandHandler.h"
#include "../sys_utils/SysExec.h"
#include "../init/Init.h"
#include "../client/ClientInfo.h"
#include "../client/GitInfo.h"
#include "../scclib/Swtio.h"
#include "../scclib/Strutils.h"
#include "../scclib/HttpLink.h"
#include "../handlers/ErrorHandler.h"

// INCLUDED GUI HEADERS
#include "../gui/QurlGui.h"
#include "../gui/CreateGui.h"

#include<string>

void Command_Parser::command_help_list()
{
	const int default_arr_size = 7;

	std::string command_table[default_arr_size] = {
		"help", 
		"clear",
		"version",
		"git",
		"qurl",
		"create",
		"exit"
	};

	std::string command_descriptions[default_arr_size] = {
		"Show information and list for commands.",
		"Clear the screen.",
		"Get the version of the console.",
		"Output the repository info and link.",
		"Similar to the " + STRING_UTILS::quote_string("curl") + " Linux command",
		"Create a file or make a directory.",
		"Exit the console."
	};

	Swtio::cput("\n-- Command List --\n\n");

	CommandHandler::push_commands(command_table, command_descriptions, default_arr_size);

	Swtio::cput("\n");
}

void Command_Parser::command_handler(std::string cmd_to_parse)
{
	const int default_cmd_table_size = 7;

	std::string local_cmd_table[default_cmd_table_size] = {
		"help", "clear", "version",
		"git", "qurl", "create",
		"exit"
	};

	bool do_parse = false;

	CommandHandler::handle_command(local_cmd_table, default_cmd_table_size, cmd_to_parse);
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

		if (Command::check_command_starts_with(prs_cmd, "git")) {
			if (Flag::check_flag(prs_cmd, "/open")) {
				HttpLink::open_link("github.com/Larixssa/QyVern-PY");
			} else if (Flag::check_flag(prs_cmd, "/link")) {
				Swtio::cput(std::string("\nRepository Link: ") + HttpLink::get_link("github.com/Larixssa/QyVern-PY") + "\n\n");
			} else {
				GitInfo::out_repo_info();
			}
		}

		if (Command::check_command(prs_cmd, "qurl")) {
			QurlGui::create_qurl_gui();
		}

		if (Command::check_command_starts_with(prs_cmd, "create")) {
			if (Flag::check_flag(prs_cmd, "/file")) {
				CreateGui::creategui_createfile(false);
			} else if (Flag::check_flag(prs_cmd, "/dir")) {
				CreateGui::creategui_makedirectory(false);
			} else { CreateGui::creategui_create(); }
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
