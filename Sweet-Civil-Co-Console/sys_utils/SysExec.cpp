#include "SysExec.h"

#include<string>

void System_Exec::exec_command(std::string exec_cmd)
{
	if (!exec_cmd.empty())
	{
		#ifdef __linux__
		system(exec_cmd);
		#elif _WIN32
		std::string cmd_str = "powershell ";
		cmd_str = cmd_str + " -command " + exec_cmd;
		const char* command = cmd_str.c_str();
		system(command);
		#endif
	}
}

void System_Exec::clear_screen()
{
	#ifdef __linux__
	system("clear");
	#elif _WIN32
	system("cls");
	#endif
}

void System_Exec::exit_client()
{
	#if __linux__
	system("quit");
	#elif _WIN32
	exit(0);
	#endif
}
