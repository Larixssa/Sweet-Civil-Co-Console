#include "Swtio.h"

#include<string>
#include<iostream>

void Swtio::cput(std::string nstr) {
	if (!nstr.empty()) {
		std::cout << nstr;
	}
}

void Swtio::cputln(std::string nstr) {
	if (!nstr.empty()) {
		std::cout << "\n" << nstr << "\n";
	}
}

void Swtio::cnl() { std::cout << "\n"; }

std::string Swtio::gcnl() { return "\n"; }
