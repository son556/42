#include "phonebook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;
	while(1)
	{
		std::cout << "insert cmd(ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
			phonebook.add_contact();
		else if (cmd.compare("SEARCH") == 0)
			phonebook.search_contact();
		else if (cmd.compare("EXIT") == 0 || std::cin.eof())
			break ;
		else
			std::cout << "bad command" << std::endl;
	}
	return (0);
}