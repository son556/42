#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string nema_s);
		ScavTrap(const ScavTrap &scav);
		ScavTrap& operator=(const ScavTrap &scav);
		virtual ~ScavTrap();
		void guardGate(void);
		void attack(std::string const& target);
};

#endif