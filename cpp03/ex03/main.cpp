#include "./DiamondTrap.hpp"

int main(void)
{
	DiamondTrap dia("dia");
	DiamondTrap dia2;
	std::string s = "small dia2";

	dia2 = dia;
	dia.attack(s);
	dia.whoAmI();
	std::cout << "\n\n";
	return (0);
}