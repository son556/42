#include "Form.hpp"
#include "Bureaucrat.hpp"


int main(void)
{
	try
	{
		try
		{
			const Bureaucrat test("test", 200);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);
		Form	f("secret", 2, 150);
		Form	c;

		std::cout << a << b << std::endl;
		
		b.signForm(f);
		a.signForm(f);
		c = f;
		std::cout << f << c;
		a.upGrade();
		b.downGrade();
		std::cout << a << b << "the end" << std::endl;
	}
	catch(const std::exception& e)
	{
		system("leaks test | grep total");
		std::cerr << e.what() << '\n';
	}
	system("leaks test | grep total");
}