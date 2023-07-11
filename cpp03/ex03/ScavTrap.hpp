#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		int scav_energy_point;
	public:
		ScavTrap();
		ScavTrap(std::string nema_s);
		ScavTrap(const ScavTrap &scav);
		ScavTrap& operator=(const ScavTrap &scav);
		virtual ~ScavTrap();
		void guardGate(void);
		virtual void attack(const std::string& target);
};
#endif