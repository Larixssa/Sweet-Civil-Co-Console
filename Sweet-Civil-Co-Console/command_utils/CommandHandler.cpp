#include "CommandHandler.h"
#include "Command.h"
#include "../scclib/Strutils.h"
#include "../scclib/Swtio.h"
#include "../parser/CommandParser.h"
#include "../handlers/ErrorHandler.h"
#include "../init/Init.h"

#include<string>

void CommandHandler::push_commands(std::string commands_list[], std::string command_descriptions[], int cmdlist_size) {
	for (int i = 0; i < cmdlist_size; i++) {
		Swtio::cput(Command::create_command(commands_list[i], command_descriptions[i]) + "\n");
	}
}

void CommandHandler::handle_command(std::string commands_list[], int cmdlist_size, std::string cmdio) {
	bool __parse__ = false;
	for (int i = 0; i < cmdlist_size; i++) {
		if (STRING_UTILS::strcmpr(cmdio, commands_list[i])) {
			__parse__ = true;
		}
	}
	if (__parse__) {
		Command_Parser::parse_command(cmdio);
	} else {
		ErrorHandler::throw_cmd_doesnt_exists(cmdio); INIT::init_client(false, false, false);
	}
}