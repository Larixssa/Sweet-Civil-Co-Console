#ifndef TITLE_H
#define TITLE_H

#include<string>

class Title
{
public:
	static std::string create_title(std::string title_str, std::string version, bool shows_version = true);
	static void display_title();
};

#endif