#include "Weapon.hpp"

Weapon::Weapon(std::string std)
{
	this->type = std;
}

const std::string&	Weapon::getType(void)
{
	return this->type;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}