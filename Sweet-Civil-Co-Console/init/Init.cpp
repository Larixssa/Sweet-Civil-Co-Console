// This is where code is initialized.

#include "Init.h"
#include "../parser/CommandParser.h"
#include "../command_utils/Command.h"
#include "../display/Title.h"
#include "../sys_utils/SysExec.h"
#include "../scclib/Strutils.h"
#include "../scclib/Swtio.h"

#include<iostream>
#include<sstream>
#include<string>

void INIT::init_client(bool show_title, bool clear_screen, bool do_load)
{

	std::string cmdio;

	bool DEFAULT_REINIT_VAL = false;

	//if (clear_screen) { System_Exec::clear_screen(); }
	if (show_title) { Title::display_title(); std::cout << "\n\n"; }
	// if (show_cmd_list) { Command_Parser::command_help_list(); }

	std::cout << "usr/console > "; std::getline(std::cin, cmdio);

	if (!cmdio.empty()) {
		Command_Parser::command_handler(cmdio);
	} else { INIT::init_client(DEFAULT_REINIT_VAL, DEFAULT_REINIT_VAL, DEFAULT_REINIT_VAL); }

}