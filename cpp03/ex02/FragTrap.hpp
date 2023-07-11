#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "./ClapTrap.hpp"
class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string nema_s);
		FragTrap(const FragTrap &scav);
		FragTrap& operator=(const FragTrap &scav);
		virtual ~FragTrap();
		void highFivesGuys();
};
#endif