#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm(25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name_)
: AForm(name_, 25 , 5)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	if (this != &ref)
		AForm::operator=(ref);
	return *this;
}

const char * PresidentialPardonForm::ExecuteErrorExec::what(void) const throw ()
{
	return "can't execute because too low grade excute level";
}

const char * PresidentialPardonForm::ExecuteErrorSign::what(void) const throw ()
{
	return "can't execute because form not signed";
}

void PresidentialPardonForm::execute(const Bureaucrat& ref) const
{
	if (this->getSigned() == false)
		throw PresidentialPardonForm::ExecuteErrorSign();
	if (ref.getGrade() > this->getExcuteGrade())
		throw PresidentialPardonForm::ExecuteErrorExec();
	std::cout << ref.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
