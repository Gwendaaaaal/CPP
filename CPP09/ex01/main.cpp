#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Need an inverted Polish mathematical operation" << std::endl;
		return (1);
	}
	try
	{
		int res = RPN(argv[1]);
		std::cout << res << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error" << std::endl;
		return (1);
	}
	return (0);
}
