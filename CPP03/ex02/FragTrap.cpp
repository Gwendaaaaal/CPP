#include "FragTrap.hpp"

FragTrap::FragTrap() 
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "FragTrap";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const std::string& name) 
{
	std::cout << "FragTrap constructor with name '" << name << "' called" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

FragTrap::~FragTrap() 
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) 
{
	if (this->hit_points > 0 && this->energy_points > 0) 
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " point of damage!" << std::endl;
		this->energy_points--;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " wants to high five !" << std::endl;
}

