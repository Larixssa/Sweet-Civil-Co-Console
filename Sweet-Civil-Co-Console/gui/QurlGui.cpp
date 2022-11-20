#include "QurlGui.h"
#include "../scclib/Strutils.h"
#include "../scclib/Swtio.h"	
#include "../scclib/HttpLink.h"
#include "../display/GuiTitle.h"
#include "../display/Prompt.h"
#include "../display/GuiGuide.h"
#include "../handlers/ProcessHandler.h"
#include "../handlers/WarningHandler.h"

#include<string>
#include<iostream>

void init_qurl_gui()
{
	std::string guide_array[] = {
		GuiGuide::create_guide("Input the URL in the prompt."),
		GuiGuide::get_default_exit_guide()
	};

	std::string iurl;

	GuiTitle::DEFAULT_GUI_SPECFILE = "Qurl";
	Prompt::DEFAULT_INPUT_TEXT = "URL";

	GuiTitle::display_gui_title();

	GuiGuide::push_guide(guide_array, 2); Swtio::cnl();

	Prompt::create_input_prompt(); std::getline(std::cin, iurl);

	if (!iurl.empty()) {
		if (!STRING_UTILS::strcmpr(iurl, "exit")) {
			std::size_t __npos__ = std::string::npos; std::size_t ffurl = iurl.find(".com");
			if (ffurl != __npos__)
				{ HttpLink::open_link(iurl); }
			else
				{ WarningHandler::throw_warning_invalid_link(iurl); Swtio::cnl(); Swtio::cnl(); }
			Swtio::cnl();
		} else {
			ProcessHandler::init_process_handler(ProcessHandler::DEFAULT_PROC_TYPE); Swtio::cnl(); Swtio::cnl();
		}
	} else {
		init_qurl_gui();
	}
}

void QurlGui::create_qurl_gui() { init_qurl_gui(); }