#ifndef GITINFO_H
#define GITINFO_H

#include<string>

class GitInfo
{
public:
	static std::string DEFAULT_GIT_LINK;
	static std::string get_repo_link();
	static void out_repo_info();
};

#endif