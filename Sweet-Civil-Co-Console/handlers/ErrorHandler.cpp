#include "ErrorHandler.h"
#include "../scclib/Swtio.h"
#include "../scclib/Strutils.h"

std::string ErrorHandler::DEFAULT_THTYPE = "empty";
std::string ErrorHandler::DEFAULT_ERROR_STRING = "ERROR";

void ErrorHandler::throw_handler(std::string thtype, std::string thval)
{
	if (!thtype.empty() && !thval.empty())
	{
		if (STRING_UTILS::strcmpr(DEFAULT_THTYPE, "empty") || STRING_UTILS::strcmpr(thtype, "empty"))
			{ ErrorHandler::throw_empty_error(thval); }
		else if (STRING_UTILS::strcmpr(DEFAULT_THTYPE, "cmd_does_not_exist") || STRING_UTILS::strcmpr(thtype, "cmd_does_not_exist"))
			{ ErrorHandler::throw_cmd_doesnt_exists(thval); }
		else if (STRING_UTILS::strcmpr(DEFAULT_THTYPE, "invalid_file_name") || STRING_UTILS::strcmpr(thtype, "invalid_file_name"))
			{ ErrorHandler::throw_invalid_file_name(thval); }
		else if (STRING_UTILS::strcmpr(DEFAULT_THTYPE, "runtime") || STRING_UTILS::strcmpr(thtype, "runtime"))
			{ ErrorHandler::throw_runtime_error(thval); }
	}
}

void ErrorHandler::throw_empty_error(std::string kw) {
	if (!kw.empty()) { Swtio::cput(
		"\n[" + ErrorHandler::DEFAULT_ERROR_STRING + "] : String > " + STRING_UTILS::quote_string(kw) + " is empty."
	); } Swtio::cnl();
}

void ErrorHandler::throw_cmd_doesnt_exists(std::string cval) {
	if (!cval.empty()) { Swtio::cput(
		"\n[" + ErrorHandler::DEFAULT_ERROR_STRING + "]: Command > " + STRING_UTILS::quote_string(cval) + " does not exist."
	); } Swtio::cnl();
}

void ErrorHandler::throw_invalid_file_name(std::string fval) {
	if (!fval.empty()) { Swtio::cput(
			Swtio::gcnl() + "[" + ErrorHandler::DEFAULT_ERROR_STRING + "]: File cannot be named " + STRING_UTILS::quote_string(fval) + ", because it is invalid or reserved."
	); } Swtio::cnl();
}

void ErrorHandler::throw_runtime_error(std::string vval) {
	/* Runtime Error Script.
	* "Console cannot be started."
	* "Try to install / add the "config" directory."
	* "Read: Docs > Build.txt, to learn more."
	*/
	if (!vval.empty()) { Swtio::cput(
			std::string("\n---- Console cannot be started. ----\n") +
			"\n- Try to install / add the \"config\" directory.\n"
			"- Read: Docs > Build.txt, to learn more."
		); } Swtio::cnl();
}