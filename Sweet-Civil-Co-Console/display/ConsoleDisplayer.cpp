#include "ConsoleDisplayer.h"
#include "../parser/ConsoleMessage.h"
#include "../scclib/Strutils.h"
#include "../scclib/Swtio.h"

void ConsoleDisplayer::display_console_message(std::string msg, bool cl_header)
{
	Swtio::cput(std::string("\n") + ConsoleMessage::create_console_message(msg, cl_header)); Swtio::cnl(); Swtio::cnl();
}

void ConsoleDisplayer::display_advanced_console_message(std::string msg, bool cl_header, bool show_time)
{
	Swtio::cput(std::string("\n") + ConsoleMessage::advanced_console_message(msg, cl_header, show_time)); Swtio::cnl(); Swtio::cnl();
}