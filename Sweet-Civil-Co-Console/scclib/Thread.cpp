#include "Thread.h"

#ifdef _WIN32
	#include<Windows.h>
	void Thread::csleep(unsigned ms)
		{ Sleep(ms); }
#else
	#include<unistd.h>
	void Thread::csleep(unsigned ms)
		{ Sleep(ms); }
#endif