#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap {
private:
	std::string name;
	unsigned int hit_points;
	unsigned int energy_points; 
	unsigned int attack_damage;

public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();


	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
