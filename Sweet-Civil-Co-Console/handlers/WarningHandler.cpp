#include "WarningHandler.h"
#include "../scclib/Swtio.h"

#include<string>

std::string WarningHandler::DEFAULT_WARNING_TYPE = "incomplete_cmd";
std::string WarningHandler::DEFAULT_WARNING_MESSAGE = "WARNING";

void WarningHandler::warning_handler(std::string whtype, std::string whval)
{
	if (!whtype.empty() && !whval.empty())
	{
		if (whtype.compare(WarningHandler::DEFAULT_WARNING_TYPE) || whtype.compare("incomplete_cmd")) {
			WarningHandler::throw_warning_incomplete_cmd(whval);
		} else if (whtype.compare(WarningHandler::DEFAULT_WARNING_TYPE) || whtype.compare("empty_prompt")) {
			WarningHandler::throw_warning_empty_prompt(whval);
		}
	}
}

void WarningHandler::throw_warning_incomplete_cmd(std::string vval) {
	if (!vval.empty()) { Swtio::cput(
		"\n[" + WarningHandler::DEFAULT_WARNING_MESSAGE + "]: Command > " + vval + " is incomplete."
	); }
}

void WarningHandler::throw_warning_empty_prompt(std::string vval) {
	if (!vval.empty()) { Swtio::cput(
		"\n[" + WarningHandler::DEFAULT_WARNING_MESSAGE + "]: Prompt > " + vval + " is invalid or empty."
	); }
}