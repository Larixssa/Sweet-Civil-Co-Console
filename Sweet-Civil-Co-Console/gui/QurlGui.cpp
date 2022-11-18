#include "QurlGui.h"
#include "../scclib/Swtio.h"
#include "../scclib/HttpLink.h"
#include "../display/GuiTitle.h"
#include "../display/Prompt.h"

#include<string>
#include<iostream>

void init_qurl_gui()
{
	std::string iurl;
	GuiTitle::DEFAULT_GUI_SPECFILE = "Qurl";
	Prompt::DEFAULT_INPUT_TEXT = "URL";
	GuiTitle::display_gui_title();
	Prompt::create_input_prompt(); std::getline(std::cin, iurl);
	Swtio::cnl();
	if (!iurl.empty()) {
		HttpLink::open_link(iurl);
	} else {
		init_qurl_gui();
	}
}

void QurlGui::create_qurl_gui() { init_qurl_gui(); }