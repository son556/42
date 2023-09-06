#include "./Bureaucrat.hpp"

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

		std::cout << a;
		std::cout << b;
		std::cout << std::endl;
		
		a.upGrade();
		b.downGrade();
		std::cout << a;
		std::cout << b;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}