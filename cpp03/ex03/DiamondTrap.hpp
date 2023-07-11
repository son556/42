#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(const DiamondTrap& diamond);
		virtual ~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& diamond);
		virtual void attack(const std::string& target);
		void whoAmI(void);
};
#endif