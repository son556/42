#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{
}

HumanB::HumanB(std::string name, Weapon	weapon): name(name)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon == NULL)
		return ;
	std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

HumanB::~HumanB()
{
}