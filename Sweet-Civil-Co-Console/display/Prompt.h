#ifndef PROMPT_H
#define PROMPT_H

#include<string>

class Prompt
{
public:
	static std::string DEFAULT_INPUT_TEXT;
	static std::string DEFAULT_YX_PROMPT_TYPE;
	static std::string input_prompt(std::string prompt_str);
	static void create_input_prompt();
	static std::string yx_prompt(std::string prompt_type);
	static void create_yx_prompt();
};

#endif