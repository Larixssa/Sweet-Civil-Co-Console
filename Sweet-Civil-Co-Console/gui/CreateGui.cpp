#include "CreateGui.h"
#include "../options/Option.h"
#include "../display/GuiTitle.h"
#include "../display/Prompt.h"
#include "../display/GuiGuide.h"
#include "../display/ConsoleDisplayer.h"
#include "../scclib/Swtio.h"
#include "../scclib/Strutils.h"
#include "../scclib/File.h"
#include "../scclib/Thread.h"
#include "../handlers/ProcessHandler.h"
#include "../sys_utils/SysExec.h"
#include "../sys_utils/PlatformVars.h"
#include "../handlers/ErrorHandler.h"

#include<string>
#include<iostream>
#include<sstream>

std::string CreateGui::DEF_FILENAME = "File";
std::string CreateGui::DEF_FILEEXT = "txt";
std::string CreateGui::DEF_DIRNAME = "Directory";

void cls_sleep()
{
	Thread::csleep(1550);
	System_Exec::clear_screen();
}

void creategui_init()
{
	const int default_options_size = 2;

	const int default_guide_arr_size = 3;

	std::string __option__;

	GuiTitle::DEFAULT_GUI_SPECFILE = "Create";
	Prompt::DEFAULT_INPUT_TEXT = "Input Option";

	std::string gui_options[default_options_size] = {
		"file", "dir"
	};
	
	std::string gui_options_desc[default_options_size] = {
		"Create a file", "Make a directory."
	};

	std::string gui_guide[default_guide_arr_size] = {
		GuiGuide::create_guide("Creat an object"),
		GuiGuide::create_guide("Pick between a file or directory."),
		GuiGuide::get_default_exit_guide()
	};

	GuiTitle::display_gui_title();

	GuiGuide::push_guide(gui_guide, default_guide_arr_size);

	Swtio::cnl();

	Option::push_options(gui_options, gui_options_desc, default_options_size);

	Swtio::cnl();

	Prompt::create_input_prompt(); std::getline(std::cin, __option__);

	if (!__option__.empty()) {
		if (!STRING_UTILS::strcmpr(__option__, "exit")) {
			if (STRING_UTILS::strcmpr(__option__, "file") || STRING_UTILS::strcmpr(__option__, "1"))
				{ CreateGui::creategui_createfile(); } 
			else if (STRING_UTILS::strcmpr(__option__, "dir") || STRING_UTILS::strcmpr(__option__, "2"))
				{ CreateGui::creategui_makedirectory(); }
			Swtio::cnl();
		} else {
			ProcessHandler::init_process_handler(ProcessHandler::DEFAULT_PROC_TYPE); Swtio::cnl(); Swtio::cnl();
		}
	} else {
		creategui_init();
	}
}

void CreateGui::creategui_create() { creategui_init(); }

void CreateGui::creategui_createfile(bool doclear)
{
	if (doclear) { System_Exec::clear_screen(); }

	std::string _file_name_;
	
	GuiTitle::DEFAULT_GUI_SPECFILE = "Create";
	GuiTitle::DEFAULT_GUI_SPECSUBFILE = "Create File";
	Prompt::DEFAULT_INPUT_TEXT = "Input File Name";

	GuiTitle::display_gui_subtitle();

	Prompt::create_input_prompt(); std::getline(std::cin, _file_name_);

	bool __invalid_file_name__ = File::check_file_name(_file_name_);

	ErrorHandler::DEFAULT_THTYPE = "invalid_file_name";

	if (!_file_name_.empty()) {
		if (__invalid_file_name__) {
			ErrorHandler::throw_handler(ErrorHandler::DEFAULT_THTYPE, _file_name_);
			cls_sleep();
		} else {
			File::create_file(_file_name_);
			ConsoleDisplayer::display_console_message("Created file: " + STRING_UTILS::quote_string(_file_name_));
			cls_sleep();
		}
	}
}

void CreateGui::creategui_makedirectory(bool doclear)
{
	if (doclear) { System_Exec::clear_screen(); }

	std::string _dir_name_;

	GuiTitle::DEFAULT_GUI_SPECFILE = "Create";
	GuiTitle::DEFAULT_GUI_SPECSUBFILE = "Create Directory";
	Prompt::DEFAULT_INPUT_TEXT = "Input Directory Name";

	GuiTitle::display_gui_subtitle();

	Prompt::create_input_prompt(); std::getline(std::cin, _dir_name_);

	bool __invalid_dir_name__ = File::check_file_name(_dir_name_);

	if (!_dir_name_.empty()) {
		if (__invalid_dir_name__) {
			ErrorHandler::throw_handler(ErrorHandler::DEFAULT_THTYPE, _dir_name_);
			cls_sleep();
		} else {
			File::make_directory(_dir_name_);
			ConsoleDisplayer::display_console_message("Created directory: " + STRING_UTILS::quote_string(_dir_name_));
			cls_sleep();
		}
	}
}