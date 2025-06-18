#include "PhoneBook.hpp"
#include "iomanip"
#include "stdlib.h"
#include <cstdlib>

PhoneBook::PhoneBook(void) {
	this->contactCount = 0;
}

PhoneBook::~PhoneBook(void) {
}

void PhoneBook::addContact(void)
{
	Contact		contact;
	std::string	str;

	std::cout << "Enter the first name of the contact." << std::endl;
	std::cin >> str;
	contact.setFirstName(str);
	std::cout << "Enter the last name of the contact." << std::endl;
	std::cin >> str;
	contact.setLastName(str);
	std::cout << "Enter the nickname of the contact." << std::endl;
	std::cin >> str;
	contact.setNickname(str);
	do {
		std::cout << "Enter the number of the contact." << std::endl;
		std::cin >> str;
	} while (contact.setNumber(str));
	std::cout << "Enter the darkest secret of the contact." << std::endl;
	std::cin >> str;
	contact.setSecret(str);

	this->contacts[contactCount % 8] = contact;
	std::cout << "Contact " << this->contactCount % 8 + 1<< " added" << std::endl;
	this->contactCount++;
}

std::string getString(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + '.');
	else
		return (str);
}

int	checkNumber(std::string str, int count)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (1);
	}
	if (std::atoi(str.c_str()) < 1 || std::atoi(str.c_str()) > count || std::atoi(str.c_str()) > 8) 
	{
		std::cout << "if marche pas avec count = " << count << std::endl;
		return (1);
	}
	return (0);
}

void PhoneBook::searchContact(void)
{
	std::string	str;

	if (!this->contactCount)
	{
		std::cout << "No contacts yet" << std::endl;
		return;
	}
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	for (int i = 0; i < this->contactCount && i < 8; i++)
	{
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		std::cout << std::setw(10) << std::right << getString(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << getString(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << getString(this->contacts[i].getNickname()) << "|" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
	}

	do {
	std::cout << "Choose which contact you want to show (by index)" << std::endl;
	std::cin >> str;
	} while (checkNumber(str, this->contactCount));

	this->contacts[std::atoi(str.c_str()) - 1].printContact();
}
