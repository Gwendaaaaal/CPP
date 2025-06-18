#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "wrong number of args !" << std::endl;
		return (1);
	}
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::ifstream infile(argv[1]);
	std::string new_string;
	if (s1.empty())
	{
		std::cout << "s1 can't be empty !" << std::endl;
		return (1);
	}
	if (infile.is_open())
	{
		size_t pos = 0;
		size_t found;
		std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
		while ((found = content.find(s1, pos)) != std::string::npos)
		{
			new_string += content.substr(pos, found - pos);
			new_string += s2;
			pos = found + s1.length();
		}
		new_string += content.substr(pos);
	}
	else
	{
		std::cout << "file couldn't be opened." << std::endl;
		return (1);
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (outfile.is_open())
		outfile << new_string;
	else
		std::cout << "could not create " << filename + ".replace" << std::endl;
	return (0);
}
