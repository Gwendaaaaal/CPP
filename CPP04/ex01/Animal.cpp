#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

void Animal::setIdea(int i, std::string idea)
{
	(void) i;
	(void) idea;
	std::cout << "This animal doesn't have a brain.." << std::endl;
}
std::string Animal::getIdea(int i) const
{
	(void) i;
	std::cout << "This animal doesn't have a brain.." << std::endl;
	return (NULL);
}
