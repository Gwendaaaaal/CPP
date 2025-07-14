#ifndef ANIMAL_HPP 
#define ANIMAL_HPP

#include <string>
#include <iostream>


class Animal {
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();
	
	std::string		getType() const;
	virtual void	makeSound() const;
	virtual void		setIdea(int i, std::string idea) const;
	virtual std::string getIdea(int i) const;
};

#endif
