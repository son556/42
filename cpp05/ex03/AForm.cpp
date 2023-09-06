#include "./AForm.hpp"

AForm::AForm() : signGrade(150), excuteGrade(150), sign(false)
{
}

AForm::AForm(const AForm& ref) 
: name(ref.name), signGrade(ref.signGrade), excuteGrade(ref.excuteGrade), sign(ref.sign) 
{
}

AForm::AForm(const int s_grade, const int e_grade)
: signGrade(s_grade), excuteGrade(e_grade), sign(false)
{
}

AForm::AForm(const std::string name_, const int s_grade, const int e_grade)
 : name(name_), signGrade(s_grade),excuteGrade(e_grade), sign(false) 
{
	if (s_grade < 1)
		throw (AForm::GradeTooHighException());
	if (s_grade > 150)
		throw (AForm::GradeTooLowException());
	if (e_grade < 1)
		throw (AForm::GradeTooHighException());
	if (e_grade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::~AForm()
{
}

AForm&	AForm::operator=(const AForm& ref)
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

void AForm::beSigned(const Bureaucrat& ref)
{
	if (ref.getGrade() <= signGrade)
		sign = true;
	else
		throw (AForm::GradeTooLowException());
}

bool AForm::getSigned() const
{
	return (sign);
}

std::string AForm::getName() const
{
	return (name);
}

int AForm::getSignGrade() const
{
	return (signGrade);
}

int AForm::getExcuteGrade() const
{
	return (excuteGrade);
}

const char * AForm::GradeTooHighException::what(void) const throw()
{
	return ("High grade exception");
}

const char * AForm::GradeTooLowException::what(void) const throw()
{
	return ("Low grade exception");
}

std::ostream& operator<<(std::ostream& os, const AForm& ref)
{
	std::cout << ref.getName() << ", sign grade " << ref.getSignGrade() << ", excute grade " << ref.getExcuteGrade() \
		<< ", sign " << ref.getSigned() << std::endl;
	return (os);
}