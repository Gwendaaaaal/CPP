#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zomb = new Zombie(name);

	if (!zomb)
		return (NULL);
	return (zomb);
}
