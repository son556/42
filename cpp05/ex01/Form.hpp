#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		const int signGrade;
		const int excuteGrade;
		bool sign;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public: 
				const char* what(void) const throw();
		};
		Form();
		Form(const Form& ref);
		Form(const std::string name_, const int s_rade, const int e_grade);
		~Form();

		Form& operator=(const Form& ref);
		void beSigned(const Bureaucrat& ref);
		std::string getName() const;
		int getSignGrade() const;
		int getExcuteGrade() const;
		bool getSigned() const;
};

std::ostream& operator<<(std::ostream& os, const Form& ref);
#endif
