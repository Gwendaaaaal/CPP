#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (&other == this)
		return *this;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*other.brain);
	this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete (this->brain);
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}

void Cat::setIdea(int i, std::string idea) const
{
	return (this->brain->setIdea(i, idea));
}

std::string Cat::getIdea(int i) const
{
	return (this->brain->getIdea(i));
}
