#include "Zombie.hpp"

int main(void)
{
	Zombie *heap = newZombie("heap");
	if (heap)
		heap->announce();

	randomChump("stack");
	delete(heap);

	return (0);
}
