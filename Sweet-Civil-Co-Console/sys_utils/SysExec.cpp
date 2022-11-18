#include "SysExec.h"
#include "Platform.h"
#include "../scclib/Strutils.h"

#include<string>

/// <summary>
/// Legacy Command Execution function.
/// </summary>
/// <param name="sys_cmd"></param>
void System_Exec::legacy_exec_command(std::string sys_cmd)
{
	if (!sys_cmd.empty())
	{
		#ifdef __linux__
		const char* lcommand = sys_cmd.c_str();
		system(lcommand);
		#elif _WIN32
		std::string cmd_str = "powershell ";
		cmd_str = cmd_str + " -command " + sys_cmd;
		const char* command = cmd_str.c_str();
		system(command);
		#endif
	}
}

/// <summary>
/// Legacy clear screen.
/// </summary>
void System_Exec::legacy_clear_screen()
{
	#ifdef __linux__
	system("clear");
	#elif _WIN32
	system("cls");
	#endif
}

void System_Exec::exit_client() { exit(0); }

void System_Exec::exec_command(std::string sys_cmd) {
	if (!sys_cmd.empty()) {
		if (STRING_UTILS::strcmpr(Platform::get_platform(), "Linux") or STRING_UTILS::strcmpr(Platform::get_platform(), "Default")) {
			const char* lcommand = sys_cmd.c_str();
			system(lcommand);
		} else if (STRING_UTILS::strcmpr(Platform::get_platform(), "Windows")) {
			std::string cmd_str = "powershell ";
			cmd_str = cmd_str + " -command " + sys_cmd;
			const char* command = cmd_str.c_str();
			system(command);
		}
	}
}

void System_Exec::clear_screen() {
	if (STRING_UTILS::strcmpr(Platform::get_platform(), "Linux") or STRING_UTILS::strcmpr(Platform::get_platform(), "Default"))
		{ system("clear"); } 
	else if (STRING_UTILS::strcmpr(Platform::get_platform(), "Windows"))
		{ system("cls"); }
}
