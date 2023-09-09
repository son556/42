#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base* generator(void)
{
	srand((unsigned)time(NULL));
	int n = rand() % 3;
	if (n == 0)
		return new A();
	else if (n == 1)
		return new B();
	return new C();
}

void identify(Base* ptr)
{
	if (dynamic_cast<A*>(ptr))
		std::cout << "identify: A*" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "identify: B*" << std::endl;
	else
		std::cout << "identify: C*" << std::endl;
}

void identify(Base& ref)
{
	try
	{
		A a = dynamic_cast<A&>(ref);
		std::cout << "identify: A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B b = dynamic_cast<B&>(ref);
		std::cout << "identify: B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C c = dynamic_cast<C&>(ref);
		std::cout << "identify: C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
}