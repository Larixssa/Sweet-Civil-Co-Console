#ifndef GUITITLE_H
#define GUITITLE_H

#include<string>

class GuiTitle
{
public:
	static std::string DEFAULT_GUI_SPECKW;
	static std::string DEFAULT_GUI_SPECFILE;
	static std::string DEFAULT_GUI_SPECSUBFILE;
	static std::string create_gui_title(std::string speckw, std::string specfile);
	static void display_gui_title();
	static std::string create_gui_subtitle(std::string speckw, std::string specfile, std::string specsubfile);
	static void display_gui_subtitle();
};

#endif