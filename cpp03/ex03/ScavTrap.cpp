#include "./ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::string name = "ScavTrap nobody";
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
	this->setName(name);
	this->scav_energy_point = this->getEnergyPoint();
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name_s)
{
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
	this->setName(name_s);
	this->scav_energy_point = this->getEnergyPoint();
	std::cout << "ScavTrap constructor called. name: " << name_s << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scav)
{
	*this = scav;
	std::cout << "ScavTrap copy constructor called. name: " << this->getName() << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scav)
{
	std::string tmp_name;
	std::cout << "ScavTrap "<< this->getName() << " operator= is called" << std::endl;
	if (this != &scav)
	{
		tmp_name = scav.getName();
		this->setName(tmp_name);
		this->setAttackDamage(scav.getAttackDamage());
		this->setHitPoint(scav.getHitPoint());
		this->setEnergyPoint(scav.getEnergyPoint());
		this->scav_energy_point = this->getEnergyPoint();
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap name: " << this->getName() << " destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->getHitPoint() > 0)
		std::cout << "ScavTrap: " << this->getName() << " has entered gatekeeper mode." << std::endl;
	else
		std::cout << "ScavTrap: " << this->getName() << "is dead." << std::endl; 
}

void ScavTrap::attack(std::string const& target)
{
	if (this->getEnergyPoint() > 0 && this->getHitPoint() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attack " << target << " causing " << \
			this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
}