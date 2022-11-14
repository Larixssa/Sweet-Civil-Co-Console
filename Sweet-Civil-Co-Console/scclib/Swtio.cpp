#include "Swtio.h"

#include<string>
#include<iostream>

void Swtio::cput(std::string nstr) {
	if (!nstr.empty()) {
		std::cout << nstr;
	}
}

std::string Swtio::cnl() { return "\n"; }

void Swtio::cputln(std::string nstr) {
	if (!nstr.empty()) {
		std::cout << "\n" << nstr << "\n";
	}
}
