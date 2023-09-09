#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <random>

class Base
{
	public:
		virtual ~Base();
};

Base* generator(void);
void identify(Base* ptr);
void identify(Base& ref);
#endif