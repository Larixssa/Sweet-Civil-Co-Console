#include "File.h"
#include "../sys_utils/PlatformVars.h"
#include "../sys_utils/SysExec.h"
#include "../scclib/Strutils.h"
#include "../scclib/Swtio.h"

#include<string>
#include<fstream>

void File::create_file(std::string file_name, std::string fext)
{
	if (!file_name.empty())
	{
		if (PLATFORM_VARS::__IS_WINDOWS__) {
			System_Exec::exec_command("ni " + file_name + "." + fext);
		} else if (PLATFORM_VARS::__IS_LINUX__) {
			System_Exec::exec_command("touch " + file_name + "." + fext);
		}
	}
}

void File::make_directory(std::string directory_name)
{
	if (!directory_name.empty())
	{
		System_Exec::exec_command("mkdir " + directory_name);
	}
}

/*
void File::write_to_file(std::string file_name, std::string ext, std::string content)
{
	std::ofstream file;
	if (!content.empty() && !file_name.empty() && !ext.empty())
	{
		file.open(file_name + "." + ext, std::ios::out); file << content; file.close();
	}
}
*/

/*
void File::read_file(std::string file_name, std::string ext, std::string data)
{
	if (!file_name.empty() && !ext.empty() && !data.empty())
	{
		if (std::ifstream(file_name + "." + ext)) 
	}
}
*/

bool File::check_file_name(std::string file)
{
	const int arr_size = 22;

	// List down reserved file names for Windows.
	std::string invalid_file_names[arr_size] = {
		"CON", "PRN", "AUX", "NUL",
		"COM1", "COM2", "COM3", "COM4",
		"COM5", "COM6", "COM7", "COM8",
		"COM9", "LPT1", "LPT2", "LPT3",
		"LPT4", "LPT5", "LPT6", "LPT7",
		"LPT8", "LPT9"
	};

	std::string invalid_file_names_low[arr_size] = {
		"con", "prn", "aux", "nul",
		"com1", "com2", "com3", "com4",
		"com5", "com6", "com7", "com8",
		"com9", "com1", "com2", "com3",
		"com4", "com5", "com6", "com7",
		"com8", "com9"
	};

	bool __invalid__ = false;

	for (int i = 0; i < arr_size; i++)
	{
		std::string def_inv_fnames = invalid_file_names[i]; std::string def_inv_fnames_low = invalid_file_names_low [i];
		bool __fnames__ = STRING_UTILS::strcmpr(file, def_inv_fnames); bool __fnames_lower__ = STRING_UTILS::strcmpr(file, def_inv_fnames_low);
		__invalid__ = (__fnames__ || __fnames_lower__);
	}

	return __invalid__;
}