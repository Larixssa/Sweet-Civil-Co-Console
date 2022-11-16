#include "ErrorHandler.h"
#include "../scclib/Swtio.h"
#include "../scclib/Strutils.h"

std::string ErrorHandler::DEFAULT_THTYPE = "empty";
std::string ErrorHandler::DEFAULT_ERROR_STRING = "ERROR";

void ErrorHandler::throw_handler(std::string thtype, std::string thval)
{
	std::string DEF_THTYPE = ErrorHandler::DEFAULT_THTYPE;
	if (!thtype.empty() && !thval.empty())
	{
		if (thtype.compare(DEF_THTYPE) || thtype.compare("empty"))
			{ ErrorHandler::throw_empty_error(thval); }
		else if (thtype.compare(DEFAULT_THTYPE) || thtype.compare("runtime"))
			{ ErrorHandler::throw_runtime_error(thval); }
	}
}

void ErrorHandler::throw_empty_error(std::string kw) {
	if (!kw.empty()) { Swtio::cput(
		"[" + ErrorHandler::DEFAULT_ERROR_STRING + "] : String > " + STRING_UTILS::quote_string(kw) + " is empty."
	); }
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
		); }
}