#include "ClapTrap.hpp"

int main() {
	std::cout << "=== Constructors ===" << std::endl;
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");
	ClapTrap c = a; // Copy constructor

	std::cout << "\n=== Assignment Operator ===" << std::endl;
	b = a; // Copy assignment

	std::cout << "\n=== Attacking ===" << std::endl;
	a.attack("target1");
	a.attack("target2");

	std::cout << "\n=== Taking Damage ===" << std::endl;
	a.takeDamage(3);
	a.takeDamage(4);
	a.takeDamage(10); // Overkill test

	std::cout << "\n=== Repairing ===" << std::endl;
	b.beRepaired(5);
	b.takeDamage(2);
	b.beRepaired(3);

	std::cout << "\n=== Energy depletion test ===" << std::endl;
	for (int i = 0; i < 12; ++i) {
		b.attack("Dummy");
	}

	std::cout << "\n=== Repair with no energy ===" << std::endl;
	b.beRepaired(5); // Should not work

	std::cout << "\n=== Attack with 0 hit points ===" << std::endl;
	ClapTrap dead("DeadBot");
	dead.takeDamage(100);
	dead.attack("Target"); // Should not work
	dead.beRepaired(10);   // Should not work

	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}
