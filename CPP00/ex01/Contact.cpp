#include "Contact.hpp"

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

void Contact::setFirstName(std::string str)
{
	this->firstName = str;
}

void Contact::setLastName(std::string str)
{
	this->lastName = str;
}

void Contact::setNickname(std::string str)
{
	this->nickname = str;
}

int Contact::setNumber(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (1);
	}
	this->number = str;
	return (0);
}

void Contact::setSecret(std::string str)
{
	this->secret = str;
}

std::string Contact::getFirstName(void)
{
	return (this->firstName);
}

std::string Contact::getLastName(void)
{
	return (this->lastName);
}

std::string Contact::getNickname(void)
{
	return (this->nickname);
}

void Contact::printContact(void)
{
	std::cout << "First Name : " << this->firstName << std::endl;
	std::cout << "Last Name : " << this->lastName << std::endl;
	std::cout << "Nickame : " << this->nickname << std::endl;
	std::cout << "Number : " << this->number << std::endl;
	std::cout << "Darkest secret : " << this->secret << std::endl;
}
