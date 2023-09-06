#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
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
		Bureaucrat();
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat(const std::string& ref, const int& g);
		Bureaucrat& operator=(const Bureaucrat& ref);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void upGrade();
		void downGrade();
		void signForm(AForm& ref) const;
		void executeForm(const AForm& ref);
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref);

#endif