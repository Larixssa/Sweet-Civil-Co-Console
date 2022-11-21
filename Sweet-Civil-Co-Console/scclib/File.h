#ifndef FILE_H
#define FILE_H

#include<string>

class File
{
public:
	static void create_file(std::string file_name, std::string fext = "txt");
	static void make_directory(std::string directory_name);
	// static void write_to_file(std::string file_name, std::string ext, std::string content);
	// static void read_file(std::string file_name, std::string ext, std::string data);
	static bool check_file_name(std::string file);
};

#endif