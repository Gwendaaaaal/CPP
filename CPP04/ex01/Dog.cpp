#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (&other == this)
		return *this;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*other.brain);
	this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete (this->brain);
}

void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}

void Dog::setIdea(int i, std::string idea) const
{
	return (this->brain->setIdea(i, idea));
}

std::string Dog::getIdea(int i) const
{
	return (this->brain->getIdea(i));
}
