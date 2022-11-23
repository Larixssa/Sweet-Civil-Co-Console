#ifndef INIT_H
#define INIT_H

#include<string>

class INIT
{
public:
	static bool SHOW_TITLE;
	static bool CLEAR_SCREEN;
	static bool LOAD;
	static void init_client(bool show_title, bool clear_screen, bool do_load = true);
};

#endif