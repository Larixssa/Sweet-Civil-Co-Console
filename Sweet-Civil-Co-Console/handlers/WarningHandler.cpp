#include "WarningHandler.h"
#include "../scclib/Swtio.h"
#include "../scclib/Strutils.h"

#include<string>

std::string WarningHandler::DEFAULT_WARNING_TYPE = "incomplete_cmd";
std::string WarningHandler::DEFAULT_WARNING_MESSAGE = "WARNING";

void WarningHandler::warning_handler(std::string whtype, std::string whval)
{
	if (!whtype.empty() && !whval.empty())
	{
		if (STRING_UTILS::strcmpr(WarningHandler::DEFAULT_WARNING_TYPE, "incomplete_cmd")
			|| STRING_UTILS::strcmpr(whtype, "incomplete_cmd")) { WarningHandler::throw_warning_incomplete_cmd(whval); } 
		else if (STRING_UTILS::strcmpr(WarningHandler::DEFAULT_WARNING_TYPE, "empty_prompt")
			|| STRING_UTILS::strcmpr(whtype, "empty_prompt")) { WarningHandler::throw_warning_empty_prompt(whval); }
		else if (STRING_UTILS::strcmpr(WarningHandler::DEFAULT_WARNING_TYPE, "invalid_link")
			|| STRING_UTILS::strcmpr(whtype, "invalid_link")) { WarningHandler::throw_warning_invalid_link(whval); }
	}
}

void WarningHandler::throw_warning_incomplete_cmd(std::string vval) {
	if (!vval.empty()) { Swtio::cput(
		"\n[" + WarningHandler::DEFAULT_WARNING_MESSAGE + "]: Command > " + STRING_UTILS::quote_string(vval) + " is incomplete."
	); } Swtio::cnl(); Swtio::cnl();
}

void WarningHandler::throw_warning_empty_prompt(std::string vval) {
	if (!vval.empty()) { Swtio::cput(
		"\n[" + WarningHandler::DEFAULT_WARNING_MESSAGE + "]: Prompt > " + STRING_UTILS::quote_string(vval) + " is invalid or empty."
	); } Swtio::cnl(); Swtio::cnl();
}

void WarningHandler::throw_warning_invalid_link(std::string lnkval) {
	if (!lnkval.empty()) { Swtio::cput(
		"\n[" + WarningHandler::DEFAULT_WARNING_MESSAGE + "] Link > " + STRING_UTILS::quote_string(lnkval) + " is invalid."
	); }
}