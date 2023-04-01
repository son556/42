#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*zombie_swamp = new	Zombie[N];
	std::string	name_origin;

	name_origin = name;
	for (int i = 0; i < N; i++)
	{
		if (i > 0)
			name = name + "(" + std::to_string(i) + ")";
		zombie_swamp[i].setName(name);
		name = name_origin;
	}
	return (zombie_swamp);
}