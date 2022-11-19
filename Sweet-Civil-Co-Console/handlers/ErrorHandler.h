#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <string>

class ErrorHandler
{
public:
	static std::string DEFAULT_THTYPE;
	static std::string DEFAULT_ERROR_STRING;
	static void throw_handler(std::string thtype, std::string thval);
	static void throw_empty_error(std::string kw);
	static void throw_cmd_doesnt_exists(std::string cval);
	static void throw_runtime_error(std::string vval);
};

#endif