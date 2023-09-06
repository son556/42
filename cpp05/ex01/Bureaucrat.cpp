#include "./Bureaucrat.hpp"
#include "./Form.hpp"

Bureaucrat::Bureaucrat() : name("no name"), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.name)
{
	*this = ref;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	if (this != &ref)
	{
		this->grade = ref.grade;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref)
{
	std::cout << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
	return (os);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& ref, const int& g) : name(ref), grade(g)
{
	if (g > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (g < 1)
		throw (Bureaucrat::GradeTooHighException());
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("High grade exception");
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Low grade exception");
}

void Bureaucrat::downGrade()
{
	grade++;
	if (grade > 150)
	{
		grade--;
		throw (Bureaucrat::GradeTooLowException());
	}
}

void Bureaucrat::upGrade()
{
	grade--;
	if (grade < 1)
	{
		grade++;
		throw (Bureaucrat::GradeTooHighException());
	}
}

void Bureaucrat::signForm(Form& ref) const
{
	try
	{
		ref.beSigned(*this);
		std::cout << name << " signed " << ref.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't sign " << ref.getName() << "because " << e.what() << std::endl;
	}
}
