#ifndef AForm_HPP
#define AForm_HPP

#include "./Bureaucrat.hpp"

class AForm
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
		AForm();
		AForm(const AForm& ref);
		AForm(const std::string name_, const int s_grade, const int e_grade);
		AForm(const int s_grade, const int e_grade);
		virtual ~AForm();

		AForm& operator=(const AForm& ref);
		void beSigned(const Bureaucrat& ref);
		virtual void execute(const Bureaucrat& ref) const = 0;
		std::string getName() const;
		int getSignGrade() const;
		int getExcuteGrade() const;
		bool getSigned() const;
};
std::ostream& operator<<(std::ostream& os, const AForm& ref);
#endif