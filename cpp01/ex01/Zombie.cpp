#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->name << " disappeared." << std::endl;
}