#include "Harl.hpp"

int	main(void)
{
	Harl	harl;
	std::string	level;

	std::cout << "insert level(DEBUG, INFO, WARNING, ERROR)" << std::endl;
	std::getline(std::cin, level);
	harl.complain(level);
	return (0);
}