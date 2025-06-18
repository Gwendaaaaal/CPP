#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== FragTrap Tests ===" << std::endl;
    FragTrap frag1("Frag");
    frag1.attack("target");
    frag1.takeDamage(50);
    frag1.beRepaired(20);
    frag1.highFivesGuys();

    std::cout << "\n=== Destructor calls ===" << std::endl;
    return 0;
}
