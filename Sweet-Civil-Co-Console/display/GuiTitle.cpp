#include "GuiTitle.h"
#include "../scclib/Swtio.h"

#include<string>

std::string GuiTitle::DEFAULT_GUI_SPECKW = "GUI";
std::string GuiTitle::DEFAULT_GUI_SPECFILE = "Gui";

std::string GuiTitle::create_gui_title(std::string speckw, std::string specfile)
{
	std::string f_gui_title_string;
	if (!speckw.empty() && !specfile.empty())
	{
		f_gui_title_string = "\n[ " + speckw + " > " + specfile + " ]\n\n";
	}
	return f_gui_title_string;
}

void GuiTitle::display_gui_title()
{
	Swtio::cput(GuiTitle::create_gui_title(GuiTitle::DEFAULT_GUI_SPECKW, GuiTitle::DEFAULT_GUI_SPECFILE));
}