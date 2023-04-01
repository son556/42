#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	// Zombie	Zombiestack = Zombie(name);
	Zombie	*Zombiesample = new Zombie(name);
	return (Zombiesample);
}