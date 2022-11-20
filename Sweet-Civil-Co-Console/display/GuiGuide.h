#ifndef GUIGUIDE_H
#define GUIGUIDE_H

#include<string>

class GuiGuide
{
public:
	static std::string DEFAULT_GUIDE_HEADER;
	static std::string DEFAULT_EXIT_GUIDE;
	static std::string create_guide(std::string guide_content);
	static std::string get_default_exit_guide();
	static void push_guide(std::string guide[], int content_size);
};

#endif