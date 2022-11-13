// sys_exec.h
/*
* Standard System and Client executions.
*/

#ifndef SYS_EXEC_H
#define SYS_EXEC_H

#include<string>

class System_Exec
{
public:
	static void exec_command(std::string sys_cmd);
	static void clear_screen();
	static void exit_client();
};

#endif