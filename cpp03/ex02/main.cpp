#include "./FragTrap.hpp"

int main(void)
{
	FragTrap scav("scav");
	FragTrap scav2;

	scav2 = scav;
	scav.attack("small scav2");
	scav.highFivesGuys();
	return (0);
}