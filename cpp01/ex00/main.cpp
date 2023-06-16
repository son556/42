#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombiea = Zombie("zozo");
	zombiea.announce();

	Zombie* zombieB = newZombie("heapZombieB");
	zombieB->announce();

	Zombie* zombieC = new Zombie("juju");
	zombieC->announce();

	randomChump("hallpoint zombie");

	delete zombieB;
	delete zombieC;
}