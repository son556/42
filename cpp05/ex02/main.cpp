#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat b1("Admin", 1);
	Bureaucrat b2("Jseo", 15);
	Bureaucrat b3("Dohykim", 70);
	Bureaucrat b4("Hyson", 140);

	AForm *f1 = new PresidentialPardonForm("Chang Chen");
	AForm *f2 = new RobotomyRequestForm("Terminator");
	AForm *f3 = new ShrubberyCreationForm("Fangorn");
	AForm *f4 = new PresidentialPardonForm("co co");

	std::cout << b1 << std::endl
		<< b2 << std::endl
		<< b3 << std::endl
		<< b4 << std::endl;
	std::cout << std::endl;
	std::cout << *f1 << std::endl
		<< *f2 << std::endl
		<< *f3 << std::endl;
	std::cout << std::endl;

	b3.signForm(*f2);
	b4.signForm(*f3);
	b1.signForm(*f4);
	b2.signForm(*f1);
	std::cout << std::endl;
	b2.executeForm(*f1);
	b3.executeForm(*f2);
	std::cout << std::endl;
	b1.executeForm(*f2);
	b1.executeForm(*f3);

	delete f4;
	delete f3;
	delete f2;
	delete f1;
	system("leaks test | grep total");
	return 0;
}