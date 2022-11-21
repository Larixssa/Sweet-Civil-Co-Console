#include "ProcessHandler.h"
#include "../scclib/Strutils.h"
#include "../scclib/Swtio.h"

#include<string>

std::string ProcessHandler::DEFAULT_PROC_TYPE = "cancelledproc";

void ProcessHandler::init_process_handler(std::string proc_type)
{
	if (!proc_type.empty())
	{
		if (STRING_UTILS::strcmpr(proc_type, "cancelledproc")) {
			Swtio::cput(Swtio::gcnl() + ProcessHandler::cancelled_process());
		} else if (STRING_UTILS::strcmpr(proc_type, "failedproc")) {
			Swtio::cput(Swtio::gcnl() + ProcessHandler::failed_process());
		}
	}
}

std::string ProcessHandler::cancelled_process()
{
	return "-- PROCESS CANCELLED --";
}

std::string ProcessHandler::failed_process()
{
	return "-- PROCESS FAILED --";
}