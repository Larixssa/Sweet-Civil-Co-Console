#include "Title.h"
#include "LineBar.h"
#include "../client/Info.h"

#include<string>
#include<iostream>


std::string Title::create_title(std::string title_str, std::string version, bool shows_version)
{
	std::string full_version_string;
	if (!title_str.empty()) {
		full_version_string = title_str;
		if (shows_version && !version.empty()) {
			full_version_string = title_str + " - " + version;
		}
	}
	return full_version_string;
}

void Title::display_title()
{
	std::string title_content = Title::create_title(ClientInfo::CLIENT_NAME, ClientInfo::CLIENT_VERSION);
	std::string linebar = LineBar::create_linebar("-", 58);
	std::cout << title_content + "\n\n" + linebar;
}
