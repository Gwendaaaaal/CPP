#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "ClapTrap";
	this->energy_points = 10;
	this->hit_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "Constructor with name '" << name <<"' called" << std::endl;
	this->name = name;
	this->energy_points = 10;
	this->hit_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->name = other.name;
	this->attack_damage = other.attack_damage;
	this->energy_points = other.energy_points;
	this->hit_points = other.hit_points;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
		this->hit_points = other.hit_points;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hit_points > 0 && this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " point of damage!" << std::endl;
		this->energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	if (amount >= this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points > 0 && this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
		this->hit_points += amount;
		this->energy_points -= 1;
	}
}
