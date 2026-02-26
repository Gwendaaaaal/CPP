#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc <= 1)
		std::cerr << "Error argc" << std::endl;

	try {
		PmergeMe sorter(argc, argv);
		sorter.pmergeme();
	} catch (const std::exception &e) {
		std::cerr << "Error" << std::endl;
	}
	return (0);
}
