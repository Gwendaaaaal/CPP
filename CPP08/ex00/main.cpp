#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	std::list<int> list;
	list.push_back(21);
	list.push_back(12);
	list.push_back(5);
	list.push_back(10);

	std::vector<int> vect;
	vect.push_back(12);
	vect.push_back(10);
	vect.push_back(5);
	vect.push_back(8);

	const std::vector<int> const_vect(vect);

	std::list<int>::iterator it_l = easyfind(list, 5);
	// std::vector<int>::iterator it_v = easyfind(const_vect, 8);
	std::vector<int>::const_iterator const_it_v = easyfind(const_vect, 8);

	std::cout << "it_l = " << *it_l << std::endl;
	std::cout << "const_it_v = " << *const_it_v << std::endl;

	try {
		easyfind(list, 42);
	} catch (const std::exception&) {
		std::cout << "42 not found" << std::endl;
	}

	return 0;
}
