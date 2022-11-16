// sys_exec.h
/*
* Standard System and Client executions.
*/

#ifndef SYSEXEC_H
#define SYSEXEC_H

#include<string>

class System_Exec
{
public:
	static void legacy_exec_command(std::string sys_cmd);
	static void legacy_clear_screen();
	static void exec_command(std::string sys_cmd);
	static void clear_screen();
	static void exit_client();
};

#endif