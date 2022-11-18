#include "ClientTitle.h"
#include "LineBar.h"
#include "../client/ClientInfo.h"
#include "../scclib/Swtio.h"
#include "../scclib/Strutils.h"

#include<string>


std::string ClientTitle::create_title(std::string title_str, std::string version, bool shows_version)
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

void ClientTitle::display_client_title()
{
	std::string title_content = ClientTitle::create_title(ClientInfo::CLIENT_NAME, ClientInfo::CLIENT_VERSION);
	std::string linebar = LineBar::create_linebar("-", 58);
	Swtio::cput(title_content + "\n\n" + linebar);
}
