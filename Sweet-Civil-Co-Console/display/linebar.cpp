#include "linebar.h"

#include<string>

std::string LineBar::create_linebar(std::string linebar_str, int linebar_length)
{
	int MAX_LINEBAR_LENGTH = 100;
	std::string DEFAULT_LINEBAR_STRING;
	if (linebar_length >= 100) { linebar_length = MAX_LINEBAR_LENGTH; }
	for (int i = 0; i < linebar_length; i++) {
		DEFAULT_LINEBAR_STRING += linebar_str;
	}
	return DEFAULT_LINEBAR_STRING;
}