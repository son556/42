#include "./ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("scav");
	ScavTrap scav2;

	scav2 = scav;
	scav.attack("small scav2");
	scav.guardGate();
	return (0);
}