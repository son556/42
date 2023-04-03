#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;
	std::string level;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	level = argv[1];
	harl.complain(level);
	return (0);
}
