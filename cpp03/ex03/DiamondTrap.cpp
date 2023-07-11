#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::string tmp_name;
	this->name = "diamond nobody";
	tmp_name = this->name + "_clap_name";
	this->setHitPoint(FragTrap::frag_hit_point);
	this->setEnergyPoint(ScavTrap::scav_energy_point);
	this->setAttackDamage(FragTrap::frag_attack_damage);
	ScavTrap::setName(tmp_name);
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name)
{
	std::string tmp_name;
	this->name = _name;
	tmp_name = this->name + "_clap_name";
	this->setHitPoint(FragTrap::frag_hit_point);
	this->setEnergyPoint(ScavTrap::scav_energy_point);
	this->setAttackDamage(FragTrap::frag_attack_damage);
	ScavTrap::setName(tmp_name);
	std::cout << "DiamondTrapTrap constructor called. name: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamond)
{
	*this = diamond;
	std::cout << "DiamondTrap copy constructor called. name: " << this->name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamond)
{
	std::cout << "DiamondTrap "<< this->name << " operator= is called" << std::endl;
	if (this != &diamond)
	{
		std::string tmp_name = diamond.getName();
		this->name = diamond.name;
		this->setAttackDamage(diamond.getAttackDamage());
		this->setHitPoint(diamond.getHitPoint());
		this->setEnergyPoint(diamond.getEnergyPoint());
		this->setName(tmp_name);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap name: " << this->name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "This DiamondTrap name: " << this->name \
			<< " and This ClapTrap name: " << this->getName() << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}