#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string z_name)
{
	name = z_name;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->name << " disappeared." << std::endl;
}