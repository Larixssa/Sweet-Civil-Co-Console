#include "GitInfo.h"
#include "../scclib/Swtio.h"

#include<string>

std::string GitInfo::DEFAULT_GIT_LINK = "https://github.com/Larixssa/Sweet-Civil-Co-Console";

std::string GitInfo::get_repo_link() {
	return GitInfo::DEFAULT_GIT_LINK;
}

void GitInfo::out_repo_info() {
	/* Git Info script.
	* # Sweet Civil Co. (Console)
	* 
	* The console for Sweet Civil Corporation.
	* This was a privated project by @Equinoxtic, this was made public with permission.
	*
	* ---- Credits ----
	*
	* > @Larixssa (Publisher / Creator)
	* > @Equinoxtic (Original Creator)
	* > Made in C++
	*
	* ; Larixssa <3
	* 
	* Repository: [REPOSISTORY LINK GOES HERE]
	*/

	std::string full_script =
		"\n" + std::string("# Sweet Civil Co. (Console)\n\n") +
		"The console for Sweet Civil Corporation.\n" +
		"This was a privated project by @Equinoxtic, this was maede public with permission.\n\n" +
		"---- Credits ----\n\n" +
		"> @Larixssa (Publisher / Creator)\n" +
		"> @Equinoxtic (Original Creator)\n" +
		"> Made in C++\n\n" +
		"; Larixssa <3\n\n" +
		"Repository: " + GitInfo::get_repo_link() + "\n\n";

	Swtio::cput(std::string(full_script));
}