#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& ref)
{
	*this = ref;
}

Intern& Intern::operator=(const Intern& ref)
{
	static_cast<void>(ref);
	return *this;
}

Intern::~Intern()
{
}

const char * Intern::NoTypeException::what(void) const throw()
{
	return "no type";
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int idx = 0;
	while (idx < 4)
	{
		if (target.compare(arr[idx]) == 0)
			break;
		idx++;
	}
	try
	{
		switch (idx)
		{
			case 0:
				std::cout << "Intern creates " << arr[0] << std::endl;
				return new ShrubberyCreationForm(name);
				break;
			case 1:
				std::cout << "Intern creates " << arr[1] << std::endl;
				return new RobotomyRequestForm(name);
				break;
			case 2:
				std::cout << "Intern creates " << arr[2] << std::endl;
				return new PresidentialPardonForm(name);
				break;
			default:
				throw Intern::NoTypeException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}
}