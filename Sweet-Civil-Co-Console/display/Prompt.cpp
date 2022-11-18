#include "Prompt.h"
#include "../scclib/Strutils.h"
#include "../scclib/Swtio.h"

#include<string>

std::string Prompt::DEFAULT_INPUT_TEXT = "Input String";
std::string Prompt::DEFAULT_YX_PROMPT_TYPE = "default";

std::string Prompt::input_prompt(std::string prompt_str)
{
	std::string f_prompt_str;
	if (!prompt_str.empty()) {
		f_prompt_str = "[" + prompt_str + "] ~ ";
	}
	return f_prompt_str;
}

void Prompt::create_input_prompt()
{
	Swtio::cput(Prompt::input_prompt(Prompt::DEFAULT_INPUT_TEXT));
}

std::string Prompt::yx_prompt(std::string prompt_type)
{
	std::string f_prompt_str;
	std::string yx_str = "Y/X";
	if (!prompt_type.empty())
	{
		if (STRING_UTILS::strcmpr(prompt_type, "default")) {
			f_prompt_str = "(" + yx_str + ")";
		} else if (STRING_UTILS::cmpr(prompt_type, "brackets")) {
			f_prompt_str = "[" + yx_str + "]";
		}
	}
	return f_prompt_str + " ~ ";
}

void Prompt::create_yx_prompt()
{
	Swtio::cput(Prompt::yx_prompt(Prompt::DEFAULT_YX_PROMPT_TYPE));
}