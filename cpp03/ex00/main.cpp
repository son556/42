#include "./ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("king clap");
	ClapTrap clap2;

	clap2 = clap;
	clap.attack("small clap");
	clap2.takeDamage(12);
	clap.beRepaired(3);
	return (0);
}