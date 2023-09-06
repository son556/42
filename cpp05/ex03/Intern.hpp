#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>

class Intern
{
	public:
		Intern();
		Intern(const Intern& ref);
		virtual ~Intern();
		class NoTypeException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		Intern&	operator=(const Intern& ref);
		AForm* makeForm(std::string name, std::string target);
};

#endif
