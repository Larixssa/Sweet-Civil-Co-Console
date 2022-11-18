#include "Swtio.h"

#include<string>
#include<iostream>

void Swtio::cput(std::string nstr) {
	if (!nstr.empty()) {
		std::cout << nstr;
	}
}

void Swtio::cnl() { std::cout << "\n"; }

void Swtio::cputln(std::string nstr) {
	if (!nstr.empty()) {
		std::cout << "\n" << nstr << "\n";
	}
}
