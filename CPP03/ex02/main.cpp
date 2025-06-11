#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap Tests ===" << std::endl;
    ClapTrap clap1("Clappy");
    clap1.attack("target1");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    std::cout << "\n=== ScavTrap Tests ===" << std::endl;
    ScavTrap scav1("Guardian");
    scav1.attack("Intruder");
    scav1.takeDamage(20);
    scav1.beRepaired(10);
    scav1.guardGate();

    std::cout << "\n=== FragTrap Tests ===" << std::endl;
    FragTrap frag1("Fraggy");
    frag1.attack("EnemyBot");
    frag1.takeDamage(30);
    frag1.beRepaired(20);
    frag1.highFivesGuys();

    std::cout << "\n=== Destructor calls ===" << std::endl;
    return 0;
}
