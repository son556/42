#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(102);
	}
	catch(const char *str)
	{
		std::cerr << str << std::endl;
	}
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	Span spc = Span(1);

	spc.addNumber(2);
	try
	{
		std::cout << spc.shortestSpan() << std::endl;
	}
	catch(const char *str)
	{
		std::cerr << str << std::endl;
	}
	std::vector<int> test;
	for (int i = 0; i < 5; i++)
		test.push_back(i);
	Span test_span(3);
	try
	{
		test_span.addNumbers(test);
	}
	catch(const char *str)
	{
		std::cerr << str << '\n';
	}
	
	return 0;
}