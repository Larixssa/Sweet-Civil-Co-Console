#include "init_client.h"
#include "../parser/command_parser.h"
#include "../command_utils/command.h"
#include "../display/title.h"
#include "../sys_utils/sys_exec.h"

#include<iostream>
#include<sstream>
#include<string>

void CLIENT_INIT::init_client(bool show_title, bool clear_screen, bool do_load)
{

	std::string cmdio;

	bool DEFAULT_REINIT_VAL = false;

	if (clear_screen) { System_Exec::clear_screen(); }
	if (show_title) { Title::display_title(); std::cout << "\n\n"; }
	// if (show_cmd_list) { Command_Parser::command_help_list(); }

	std::cout << "usr/console > "; std::getline(std::cin, cmdio);

	if (!cmdio.empty()) {
		Command_Parser::command_handler(cmdio);
	} else { CLIENT_INIT::init_client(DEFAULT_REINIT_VAL, DEFAULT_REINIT_VAL, DEFAULT_REINIT_VAL); }

}