#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "./AForm.hpp"
# include <iostream>
# include <exception>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string ascii_tree;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		ShrubberyCreationForm(const std::string name_);
		virtual ~ShrubberyCreationForm();

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
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
		void execute(const Bureaucrat& ref) const;
};

#endif
