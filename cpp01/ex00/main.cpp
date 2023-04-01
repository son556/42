#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombiea = Zombie("zozo"); // stack
	zombiea.announce();

	Zombie* zombieB = newZombie("heapZombieB"); //heap
	zombieB->announce();

	Zombie* zombieC = new Zombie("juju"); // heap
	zombieC->announce();

	randomChump("hallpoint zombie"); // stack

	delete zombieB;
	delete zombieC;
}