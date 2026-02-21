#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
		return (BitcoinExchange(argv[1]));
	std::cout << "Need an input file." << std::endl;
	return (1);
}
