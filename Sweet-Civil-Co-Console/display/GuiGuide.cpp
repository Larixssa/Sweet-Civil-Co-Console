#include "GuiGuide.h"
#include "../scclib/Strutils.h"
#include "../scclib/Swtio.h"

#include<string>

std::string GuiGuide::DEFAULT_GUIDE_HEADER = "-- GUIDE --";

std::string GuiGuide::DEFAULT_EXIT_GUIDE = "Type in " + STRING_UTILS::quote_string("exit") + " To exit out of the prompt.";

std::string GuiGuide::create_guide(std::string guide_content)
{
	std::string fguide_content;
	if (!guide_content.empty())
	{
		fguide_content = "* " + guide_content;
	}
	return fguide_content;
}

std::string GuiGuide::get_default_exit_guide()
{
	return GuiGuide::create_guide(DEFAULT_EXIT_GUIDE);
}

void GuiGuide::push_guide(std::string guide[], int content_size)
{
	for (int i = 0; i < content_size; i++) 
	{
		Swtio::cput(guide[i] + Swtio::gcnl());
	}
}