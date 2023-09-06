#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <iostream>
#include <exception>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		PresidentialPardonForm(std::string name_);
		virtual ~PresidentialPardonForm();

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
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);
		void execute(const Bureaucrat& ref) const;
};

#endif
