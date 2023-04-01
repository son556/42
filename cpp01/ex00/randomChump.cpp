#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zzombie = Zombie(name);

	zzombie.announce();
}