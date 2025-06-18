#include <iostream>
#include "PhoneBook.hpp"

int main(void) 
{
	PhoneBook phonebook;
	std::string choice;

	while (true)
	{
		std::cout << "Please enter an option (ADD, SEARCH or EXIT)" << std::endl;
		std::cin >> choice;
		if (choice == "ADD")
		{
			phonebook.addContact();
		}
		else if (choice == "SEARCH") 
		{
			phonebook.searchContact();
		}
		else if (choice == "EXIT")
		{
			break;
		}
	}
}
