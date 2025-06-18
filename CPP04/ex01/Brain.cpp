#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->setIdea(i, "eat.");
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->setIdea(i, other.ideas[i]);
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->setIdea(i, other.ideas[i]);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i > 99)
	{
		std::cout << "Wrong index (" << i << ") to set an idea" << std::endl;
		return ;
	}
	this->ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i > 99)
	{
		std::cout << "Wrong index (" << i << ") to get an idea" << std::endl;
		return (NULL);
	}
	return (this->ideas[i]);
}
