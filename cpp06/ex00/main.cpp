#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong input" << std::endl;
		return 0;
	}
	try
	{
		ScalarConverter::convertChar(static_cast<std::string>(argv[1]));
		ScalarConverter::convertInt(static_cast<std::string>(argv[1]));
		ScalarConverter::convertFloat(static_cast<std::string>(argv[1]));
		ScalarConverter::convertDouble(static_cast<std::string>(argv[1]));
	}
	catch(std::bad_alloc)
	{
		std::cerr << "so long input!!" << std::endl;
	}
}