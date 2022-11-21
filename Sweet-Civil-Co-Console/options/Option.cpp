#include "Option.h"
#include "../scclib/Strutils.h"
#include "../scclib/Convert.h"
#include "../scclib/Swtio.h"

#include<string>

std::string Option::create_option(std::string name, std::string description) {
	std::string foption;
	if (!name.empty() && !description.empty()) {
		foption = ": [" + name + "] - " + description;
	}
	return foption;
}

void Option::push_options(std::string optionslist[], std::string optionsdesclist[], int optionslist_size) {
	for (int i = 0; i < optionslist_size; i++) {
		Swtio::cput("(" + Convert::itostr(i+1) + ") " + Option::create_option(optionslist[i], optionsdesclist[i]) + Swtio::gcnl());
	}
}