#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int hit_point;
		int energy_point;
		int attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string clap_name);
		ClapTrap(const ClapTrap& clap);
		virtual ~ClapTrap();
		ClapTrap& operator=(const ClapTrap& clap);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void setName(std::string &new_name);
		std::string getName(void) const;
		void setHitPoint(unsigned int hit_p);
		int  getHitPoint(void) const;
		void setEnergyPoint(unsigned int energy_p);
		int  getEnergyPoint(void) const;
		void setAttackDamage(unsigned int attack_p);
		int  getAttackDamage(void) const;
};
#endif