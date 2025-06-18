#include "ClapTrap.hpp"

int main() {
	std::cout << "=== Constructors ===" << std::endl;
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");
	ClapTrap c = a; 
	ClapTrap d;
	d = b; 

	std::cout << std::endl << "=== Attacking ===" << std::endl;
	c.attack("d");
	d.attack("c");
	a.attack("target1");
	a.attack("target2");

	std::cout << std::endl << "=== Taking Damage ===" << std::endl;
	a.takeDamage(3);
	a.takeDamage(4);
	a.takeDamage(10); 
	std::cout << std::endl << "=== Repairing ===" << std::endl;
	b.beRepaired(5);
	b.takeDamage(2);
	b.beRepaired(3);

	std::cout << std::endl << "=== Energy depletion test ===" << std::endl;
	for (int i = 0; i < 10; ++i) {
		b.attack("Dummy");
	}

	std::cout << std::endl << "=== Repair with no energy ===" << std::endl;
	b.beRepaired(5); 

	std::cout << std::endl << "=== Attack with 0 hit points ===" << std::endl;
	ClapTrap dead("DeadBot");
	dead.takeDamage(100);
	dead.attack("Target");
	dead.beRepaired(10);

	std::cout << std::endl << "=== Destructors ===" << std::endl;
	return 0;
}
