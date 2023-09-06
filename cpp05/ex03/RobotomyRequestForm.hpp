#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "./AForm.hpp"
# include <iostream>
# include <random>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		RobotomyRequestForm(const std::string name_);
		virtual ~RobotomyRequestForm();
		class ExecuteErrorSign : public std::exception
		{
			public: 
				const char* what(void) const throw();
		};
		class ExecuteErrorExec : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
		void execute(const Bureaucrat& ref) const;
};

#endif
