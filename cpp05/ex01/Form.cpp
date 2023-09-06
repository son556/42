#include "./Form.hpp"
#include "./Bureaucrat.hpp"

Form::Form() : signGrade(150), excuteGrade(150), sign(false)
{
}

Form::Form(const Form& ref) 
: name(ref.name), signGrade(ref.signGrade), excuteGrade(ref.excuteGrade), sign(ref.sign) 
{
}

Form::Form(const std::string name_, const int s_grade, const int e_grade)
 : name(name_), signGrade(s_grade),excuteGrade(e_grade), sign(false) 
{
	if (s_grade < 1)
		throw (Form::GradeTooHighException());
	if (s_grade > 150)
		throw (Form::GradeTooLowException());
	if (e_grade < 1)
		throw (Form::GradeTooHighException());
	if (e_grade > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form()
{
}

Form&	Form::operator=(const Form& ref)
{
	if (this != &ref)
	{
		const_cast<int &>(signGrade) = ref.signGrade;
		const_cast<int &>(excuteGrade) = ref.excuteGrade;
		const_cast<std::string &>(name) = ref.name;
		sign = ref.sign;
	}
	return (*this);
}

void Form::beSigned(const Bureaucrat& ref)
{
	if (ref.getGrade() <= signGrade)
		sign = true;
	else
		throw (Form::GradeTooLowException());
}

bool Form::getSigned() const
{
	return (sign);
}

std::string Form::getName() const
{
	return (name);
}

int Form::getSignGrade() const
{
	return (signGrade);
}

int Form::getExcuteGrade() const
{
	return (excuteGrade);
}

const char * Form::GradeTooHighException::what(void) const throw()
{
	return ("High grade exception");
}

const char * Form::GradeTooLowException::what(void) const throw()
{
	return ("Low grade exception");
}

std::ostream& operator<<(std::ostream& os, const Form& ref)
{
	std::cout << ref.getName() << ", Form sign grade " << ref.getSignGrade() << ", Form excute grade " << ref.getExcuteGrade() \
		<< ", Form sign " << ref.getSigned() << std::endl;
	return (os);
}
