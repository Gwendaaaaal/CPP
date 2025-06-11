#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "ScavTrap";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string& name) 
{
	std::cout << "ScavTrap constructor with name '" << name << "' called" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) 
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
	if (this->hit_points > 0 && this->energy_points > 0) 
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " point of damage!" << std::endl;
		this->energy_points--;
	}
}

void ScavTrap::guardGate() 
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
