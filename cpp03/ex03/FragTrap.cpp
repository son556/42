#include "./FragTrap.hpp"

FragTrap::FragTrap()
{
	std::string name = "FragTrap nobody";
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	this->setName(name);
	this->frag_hit_point = this->getHitPoint();
	this->frag_attack_damage = this->getAttackDamage();
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name_s)
{
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	this->setName(name_s);
	this->frag_hit_point = this->getHitPoint();
	this->frag_attack_damage = this->getAttackDamage();
	std::cout << "FragTrap constructor called. name: " << this->getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap& scav)
{
	*this = scav;
	std::cout << "FragTrap copy constructor called. name: " << this->getName() << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& scav)
{
	std::cout << "FragTrap "<< this->getName() << " operator= is called" << std::endl;
	std::string temp_name;
	if (this != &scav)
	{
		temp_name = scav.getName();
		this->setName(temp_name);
		this->setAttackDamage(scav.getAttackDamage());
		this->setHitPoint(scav.getHitPoint());
		this->setEnergyPoint(scav.getEnergyPoint());
		this->frag_hit_point = this->getHitPoint();
		this->frag_attack_damage = this->getAttackDamage();
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap name: " << this->getName() << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if(this->getHitPoint())
		std::cout << "FragTrap " << this->getName() << " asks for a positive high-five" << std::endl;
	else
		std::cout << "FragTrap " << this->getName() << " is dead" << std::endl;

}