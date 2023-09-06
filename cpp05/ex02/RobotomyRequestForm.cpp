#include "./RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm(72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
: AForm(72, 45)
{
	*this = ref;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name_) : AForm(name_, 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	if (this != &ref)
		AForm::operator=(ref);
	return (*this);
}

const char * RobotomyRequestForm::ExecuteErrorSign::what(void) const throw()
{
	return ("can't execute because form not signed");
}

const char * RobotomyRequestForm::ExecuteErrorExec::what(void) const throw()
{
	return ("can't execute because too low grade excute level");
}

void RobotomyRequestForm::execute(const Bureaucrat& ref) const
{
	if (this->getSigned() == false)
		throw RobotomyRequestForm::ExecuteErrorSign();
	if (ref.getGrade() > this->getExcuteGrade())
		throw RobotomyRequestForm::ExecuteErrorExec();
	srand(time(NULL));
	int temp_rand = rand() % 2;
	if (temp_rand == 0)
		std::cout << this->getName() << " success!" << std::endl;
	else
		std::cout << this->getName() << " fail!" << std::endl;
}