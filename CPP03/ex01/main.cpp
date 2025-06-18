#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	{
		std::cout << "=== ScavTrap Tests ===" << std::endl;

		ScavTrap s1("Guardian");
		s1.attack("Intruder");
		s1.takeDamage(20);
		s1.beRepaired(10);
		s1.guardGate();
	}
	{
		std::cout << std::endl << std::endl << std::endl << std::endl;
		ScavTrap s("Scav");
		ClapTrap c("Clap");

		s.attack("target");
		c.attack("target");
	}
	return 0;
}
