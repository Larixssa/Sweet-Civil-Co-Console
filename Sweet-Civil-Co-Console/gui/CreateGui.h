#ifndef CREATEGUI_H
#define CREATEGUI_H

#include<string>

class CreateGui
{
public:
	static std::string DEF_FILENAME;
	static std::string DEF_FILEEXT;
	static std::string DEF_DIRNAME;
	static void creategui_createfile(bool doclear = true);
	static void creategui_makedirectory(bool doclear = true);
	static void creategui_create();
};

#endif