#ifndef CLIENTTITLE_H
#define CLIENTTITLE_H

#include<string>

class ClientTitle
{
public:
	static std::string create_title(std::string title_str, std::string version, bool shows_version = true);
	static void display_client_title();
};

#endif