#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR;
	std::string&	strringREF = str;

	stringPTR = &str;
	std::cout << "---------------addr-------------------" << std::endl;
	std::cout << "str addr: " << &str << std::endl;
	std::cout << "stringPTR addr: " << &stringPTR << std::endl;
	std::cout << "stringREF addr: " << &strringREF << std::endl;
	std::cout << std::endl;

	std::cout << "--------------------val----------------" << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << strringREF << std::endl;
	return (0);
}