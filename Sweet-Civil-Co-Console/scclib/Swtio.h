#ifndef SWTIO_H
#define SWTIO_H

#include<string>

class Swtio
{
public:
	static void cput(std::string nstr);
	static void cputln(std::string nstr);
	static void cnl();
	static std::string gcnl();
};

#endif