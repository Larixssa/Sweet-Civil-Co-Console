#ifndef PROCESSHANDLER_H
#define PROCESSHANDLER_H

#include<string>

class ProcessHandler
{
public:
	static std::string DEFAULT_PROC_TYPE;
	static std::string cancelled_process();
	static std::string failed_process();
	static void init_process_handler(std::string proc_type);
};

#endif