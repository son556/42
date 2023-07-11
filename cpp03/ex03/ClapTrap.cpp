#include "./ClapTrap.hpp"

ClapTrap::ClapTrap() : hit_point(10), energy_point(10), attack_damage(0)
{
	this->name = "nobody";
	std::cout << "ClapTrap default constructor name: " << this->name << std::endl;
}

ClapTrap::ClapTrap(std::string clap_name) : hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << "ClapTrap constructor name: " << clap_name << std::endl;
	this->name = clap_name;
}

ClapTrap::ClapTrap(const ClapTrap& clap)
{
	*this = clap;
	std::cout << "ClapTrap copy constructor name: " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{ 
	std::cout << "ClapTrap " << this->name << " has been destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clap)
{
	std::cout << "ClapTrap "<< this->name << " operator= is called" << std::endl;
	if (this != &clap)
	{
		this->name = clap.name;
		this->attack_damage = clap.attack_damage;
		this->hit_point = clap.hit_point;
		this->energy_point = clap.energy_point;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (energy_point > 0 && hit_point > 0)
	{
		std::cout << "ClapTrap " << this->name << " attack " << target << " causing " << \
			this->attack_damage << " points of damage!" << std::endl;
		energy_point--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point > 0)
		std::cout << "ClapTrap " << this->name << " take damage" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
	if (hit_point > amount)
	{
		hit_point -= amount;
		std::cout << "ClapTrap " << this->name << " remaining hp: " << this->hit_point << std::endl;
	}
	else if (hit_point < amount && hit_point > 0)
	{
		hit_point = 0;
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_point > 0 && hit_point > 0)
	{
		hit_point += amount;
		energy_point--;
		std::cout << "ClapTrap " << this->name << " is repaired. remaining hp: " << this->hit_point \
			<< "remaining energy: " << this->energy_point << std::endl;
	}
}

void ClapTrap::setName(std::string& new_name)
{
	this->name = new_name;
}

std::string ClapTrap::getName(void) const
{
	return (this->name);
}

void ClapTrap::setHitPoint(unsigned int hit_p)
{
	hit_point = hit_p;
}

int ClapTrap::getHitPoint(void) const
{
	return (this->hit_point);
}

void ClapTrap::setEnergyPoint(unsigned int energy_p)
{
	this->energy_point = energy_p;
}

int ClapTrap::getEnergyPoint(void) const
{
	return (this->energy_point);
}

void ClapTrap::setAttackDamage(unsigned int attack_p)
{
	this->attack_damage = attack_p;
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->attack_damage);
}