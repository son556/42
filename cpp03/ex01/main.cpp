#include "./ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("scav");
	ScavTrap scav2;
	ClapTrap *tt = new ScavTrap("sss");

	scav2 = scav;
	scav.attack("small scav2");
	scav.guardGate();
	tt->attack("ssss");
	return (0);
}